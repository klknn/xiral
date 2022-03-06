#include <grpcpp/grpcpp.h>

#include "xiral/init.h"
#include "xiral/instrument.grpc.pb.h"
#include "xiral/logging.h"

int main(int argc, char** argv) {
  xiral::InitMain(argc, argv);

  PLOGV << "verbose";
  LOG(plog::debug) << "debug";
  LOG(INFO) << "info";
  LOG(WARNING) << "warn";
  LOG(ERROR) << "error";
  LOG(FATAL) << "fatal";
  return 0;
}
