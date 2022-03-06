# xiral

experimental realtime audio library

## contents

- `core` core services and clients written in C++ and GRPC.
- `sandbox` some third-party lib usage, benchmark and snippets.

## development

To run tests
```shell
$ bazel test $(bazel query //...)
```

To run the main client.
```
$ bazel run -c opt //core:client
```
