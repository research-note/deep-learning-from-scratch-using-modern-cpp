load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "bin",
    srcs=[
        "http_session.cpp",
        "listener.cpp",
        "shared_state.cpp",
        "websocket_session.cpp",
    ],
    hdrs = [
        "beast.hpp",
        "http_session.hpp",
        "listener.hpp",
        "net.hpp",
        "shared_state.hpp",
        "websocket_session.hpp",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":bin",
        "//boost:boost",
    ],
)
