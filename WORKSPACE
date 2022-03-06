load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


# ==== Common deps ====

# Protocol buffers.
http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

# GRPC.
http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "9647220c699cea4dafa92ec0917c25c7812be51a18143af047e20f3fb05adddc",
    urls = [
        "https://github.com/grpc/grpc/archive/refs/tags/v1.43.0.tar.gz"
    ],
    strip_prefix = "grpc-1.43.0",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()


# ==== C++ deps ====

# Abseil.
http_archive(
    name = "com_google_absl",
    urls = ["https://github.com/abseil/abseil-cpp/archive/20211102.0.zip"],
    strip_prefix = "abseil-cpp-20211102.0",
    # sha256 = "6622893ab117501fc23268a2936e0d46ee6cb0319dcf2275e33a708cd9634ea6",
)

# Google test.
http_archive(
    name = "com_google_googletest",  # 2022-01-28T15:27:11Z
    sha256 = "eb70a6d4520f940956a6b3e37d205d92736bb104c6a1b2b9f82bfc41bd7a2b34",
    strip_prefix = "googletest-28e1da21d8d677bc98f12ccc7fc159ff19e8e817",
    # Keep this URL in sync with ABSL_GOOGLETEST_COMMIT in ci/cmake_common.sh.
    urls = ["https://github.com/google/googletest/archive/28e1da21d8d677bc98f12ccc7fc159ff19e8e817.zip"],
)

# Google benchmark.
http_archive(
    name = "com_github_google_benchmark",  # 2021-09-20T09:19:51Z
    sha256 = "62e2f2e6d8a744d67e4bbc212fcfd06647080de4253c97ad5c6749e09faf2cb0",
    strip_prefix = "benchmark-0baacde3618ca617da95375e0af13ce1baadea47",
    urls = ["https://github.com/google/benchmark/archive/0baacde3618ca617da95375e0af13ce1baadea47.zip"],
)

# Bazel platform rules.
http_archive(
    name = "platforms",
    sha256 = "b601beaf841244de5c5a50d2b2eddd34839788000fa1be4260ce6603ca0d8eb7",
    strip_prefix = "platforms-98939346da932eef0b54cf808622f5bb0928f00b",
    urls = ["https://github.com/bazelbuild/platforms/archive/98939346da932eef0b54cf808622f5bb0928f00b.zip"],
)

http_archive(
    name = "com_github_plog",
    strip_prefix = "plog-1.1.6",
    urls = ["https://github.com/SergiusTheBest/plog/archive/refs/tags/1.1.6.zip"],
    sha256 = "d9499c61befcb19e334a8ec6851b21f8ccd5d3ae7e43a3cba996bf6b71016d27",
    build_file_content = """
cc_library(
    name = "plog",
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)
"""
)
