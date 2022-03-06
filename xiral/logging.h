#pragma once

#define PLOG_CAPTURE_FILE
#include <plog/Log.h>

// For glog-like usage.
constexpr plog::Severity NONE = plog::none;
constexpr plog::Severity FATAL = plog::fatal;
constexpr plog::Severity ERROR = plog::error;
constexpr plog::Severity WARNING = plog::warning;
constexpr plog::Severity INFO = plog::info;
