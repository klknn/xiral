#include "xiral/init.h"

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include "xiral/logging.h"
#include "plog/Appenders/ColorConsoleAppender.h"
#include "plog/Appenders/ConsoleAppender.h"
#include "plog/Appenders/RollingFileAppender.h"
#include "plog/Init.h"
#include "plog/Util.h"

ABSL_FLAG(bool, logcolor, true, "If true, print log with color.");
ABSL_FLAG(bool, logtostderr, true, "If true, print log to stderr.");
// ABSL_FLAG(int, stderrthreshold, 0, "0: INFO, 1: WARNING, 2: ERROR, 3: FATAL.");
ABSL_FLAG(int, minloglevel, 0, "0: INFO, 1: WARNING, 2: ERROR, 3: FATAL.");
ABSL_FLAG(bool, logutctime, false, "If true, print log with UTC time.");

namespace {

class AbslFormatter {
 public:
  // Returns a header for a new file. In our case it is empty.
  static plog::util::nstring header() {
    return plog::util::nstring();
  }

  // Returns a string from a record.
  static plog::util::nstring format(const plog::Record& record) {
    tm t;
    auto time = record.getTime();
    if (absl::GetFlag(FLAGS_logutctime)) {
      plog::util::gmtime_s(&t, &time.time);
    }
    else {
      plog::util::localtime_s(&t, &time.time);
    }

    // based on abseil-py prefix
    // https://github.com/abseil/abseil-py/blob/9954557f9df0b346a57ff82688438c55202d2188/absl/logging/__init__.py#L731
    return absl::StrFormat(
        "%c%02d%02d %02d:%02d:%02d.%06d %5d %s:%d] %s\n",
        severityToString(record.getSeverity())[0],
        t.tm_mon + 1, t.tm_mday,
        t.tm_hour,
        t.tm_min,
        t.tm_sec,
        time.millitm,
        record.getTid(),
        record.getFile(),
        record.getLine(),
        record.getMessage());
  }
};

}  // namespace

namespace xiral {

void InitMain(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);

  // TODO: gflags or abseil-py compatible log filename
  // /tmp/<program>.<hostname>.<user>.log.<severity>.<date>-<time>.<pid>
  static plog::RollingFileAppender<::AbslFormatter> file_appender(
      "/tmp/xiral.log", /*maxFileSize=*/80000, /*maxFiles=*/3);

  auto severity = static_cast<plog::Severity>(
      plog::info - absl::GetFlag(FLAGS_minloglevel));
  auto& logger = plog::init(severity, &file_appender);

  if (absl::GetFlag(FLAGS_logtostderr)) {
    static plog::ConsoleAppender<::AbslFormatter> console_appender(
        plog::streamStdErr);
    static plog::ColorConsoleAppender<::AbslFormatter> color_console_appender(
        plog::streamStdErr);

    if (absl::GetFlag(FLAGS_logcolor)) {
      logger.addAppender(&color_console_appender);
    } else {
      logger.addAppender(&console_appender);
    }
  }
  // plog::get()->setMaxSeverity(plog::debug);
}

}  // namespace xiral
