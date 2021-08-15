load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "OR",
    hdrs = ["OR.hpp", "OR.cpp"],
)

cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        ":OR"
    ]
)
