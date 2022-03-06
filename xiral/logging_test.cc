#include "xiral/logging.h"

#include "gtest/gtest.h"

namespace {

TEST(LoggingTest, VariousLog) {
  PLOGV << "verbose";
  LOG(plog::debug) << "debug";
  LOG(INFO) << "info";
  LOG(WARNING) << "warn";
  LOG(ERROR) << "error";
  LOG(FATAL) << "fatal";
  // EXPECT_EQ(1, 2) << "fail";
}

}
