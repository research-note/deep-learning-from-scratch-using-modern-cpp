# NEW
load("@bazel_tools//tools/build_defs/cc:action_names.bzl", "ACTION_NAMES")
# NEW
load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
)

all_compile_actions = [
    ACTION_NAMES.cpp_compile,
    ACTION_NAMES.cpp_link_static_library,
    ACTION_NAMES.llvm_cov
]

all_cpp_compile_actions = [
    ACTION_NAMES.cpp_compile,
    ACTION_NAMES.linkstamp_compile,
    ACTION_NAMES.cpp_header_parsing,
    ACTION_NAMES.cpp_module_compile,
    ACTION_NAMES.cpp_module_codegen,
    ACTION_NAMES.clif_match,
]

all_link_actions = [
    ACTION_NAMES.cpp_link_executable,
    ACTION_NAMES.cpp_link_dynamic_library,
    ACTION_NAMES.cpp_link_nodeps_dynamic_library,
]

def _impl(ctx):
    tool_paths = [
        tool_path(
            name = "gcc",
            path = "/usr/bin/clang-12",
        ),
        tool_path(
            name = "ld",
            path = "/usr/bin/lld-12",
        ),
        tool_path(
            name = "ar",
            path = "/usr/bin/llvm-ar-12",
        ),
        tool_path(
            name = "cpp",
            path = "/usr/bin/clang++-12",
        ),
        tool_path(
            name = "gcov",
            path = "/usr/bin/llvm-cov-12",
        ),
        tool_path(
            name = "nm",
            path = "/usr/bin/llvm-nm-12",
        ),
        tool_path(
            name = "objdump",
            path = "/usr/bin/llvm-objcopy-12",
        ),
        tool_path(
            name = "strip",
            path = "/usr/bin/llvm-strip-12",
        ),
    ]

    # NEW
    features = [
        feature(
            name = "default_linker_flags",
            enabled = True,
            flag_sets = [
                flag_set(
                    actions = all_link_actions,
                    flag_groups = ([
                        flag_group(
                            flags = [
                                "-lm",
                                "-ldl",
                                "-lstdc++",
                                "-pg",
                                "-Og",
                                "-Wall",
                                "-ltbb"
                            ],
                        ),
                    ]),
                ),
            ],
        ),
    ]

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        features = features, # NEW
        cxx_builtin_include_directories = [
            "/usr/lib/llvm-12/lib/clang/12.0.0/include",
            "/usr/include"
        ],
        toolchain_identifier = "k8-toolchain",
        host_system_name = "local",
        target_system_name = "local",
        target_cpu = "k8",
        target_libc = "unknown",
        compiler = "clang",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths,
    )

cc_toolchain_config = rule(
    implementation = _impl,
    attrs = {},
    provides = [CcToolchainConfigInfo],
)
