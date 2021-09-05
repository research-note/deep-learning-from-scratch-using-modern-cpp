load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "lib",
    hdrs = [
        "gradient.hpp", "gradient.cc",
        "numerical_gradient.hpp", "numerical_gradient.cc", 
        "cross_entropy_error.hpp", "cross_entropy_error.cc",
        "softmax.hpp", "softmax.cc"
    ],
    visibility = ["//main:__pkg__"],
)
