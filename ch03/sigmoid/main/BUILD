load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "sigmoid",
    hdrs = ["sigmoid.hpp", "sigmoid.cc"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":sigmoid",
        "//lib:hello-time",
    ],
)
