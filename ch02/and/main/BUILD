load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "and",
    hdrs = ["and.hpp", "and.cc"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":and",
        "//lib:hello-time",
    ],
)
