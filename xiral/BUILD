load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "logging",
    hdrs = ["logging.h"],
    deps = ["@com_github_plog//:plog"],
)

cc_test(
    name = "logging_test",
    srcs = ["logging_test.cc"],
    size = "small",
    deps = [
        ":logging",
        ":gtest_main",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "init",
    hdrs = ["init.h"],
    srcs = ["init.cc"],
    deps = [
        ":logging",
        "@com_github_plog//:plog",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/strings",
    ],
)

proto_library(
    name = "instrument_proto",
    srcs = ["instrument.proto"],
)

cc_proto_library(
    name = "instrument_cc_proto",
    deps = [":instrument_proto"],
)

cc_grpc_library(
    name = "instrument_cc_grpc",
    srcs = [":instrument_proto"],
    grpc_only = True,
    deps = [":instrument_cc_proto"],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        ":init",
        ":instrument_cc_grpc",
    ],
)

cc_library(
    name = "gtest_main",
    srcs = ["gtest_main.cc"],
    testonly = True,
    deps = [
        ":init",
        "@com_google_googletest//:gtest",
        "@com_google_absl//absl/flags:flag",
    ]
)
