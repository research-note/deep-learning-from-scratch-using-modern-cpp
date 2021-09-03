load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "Grid",
    hdrs = ["Grid.hpp", "Grid.cc"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":Grid",
        "//lib:Cuboid",
    ],
)
