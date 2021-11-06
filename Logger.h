#ifndef __LOGER__H__
#define __LOGER__H__

#include "stdio.h"
#include "stdlib.h"

#define LOG 1

enum level
{
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL
};

static inline char *stringFromLogLevel(enum level lvl)
{
    static char *strings[] = { "LOG_TRACE", "LOG_DEBUG", "LOG_INFO", "LOG_WARN", "LOG_ERROR", "LOG_FATAL"};
    return strings[lvl];
}



#define log_trace(...) log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) log_log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

void log_log(int level, const char *file, int line, const char *fmt);

#endif