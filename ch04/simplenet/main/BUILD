load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "simplenet",
    hdrs = ["Simplenet.hpp", "Simplenet.cc"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":simplenet",
        "//lib:lib",
    ],
)
