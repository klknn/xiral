#include "gtest/gtest.h"
#include "absl/flags/flag.h"
#include "absl/flags/declare.h"
#include "xiral/init.h"

ABSL_DECLARE_FLAG(bool, logtostderr);

int main(int argc, char **argv) {
  // Enable stderr logging by default.
  absl::SetFlag(&FLAGS_logtostderr, true);
  xiral::InitMain(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
