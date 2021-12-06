#ifndef __LOGER__H__
#define __LOGER__H__

#include "stdio.h"
#include "stdlib.h"

#define LOG 1

#define CBlack "\033[0;30m"
#define CRed "\033[0;31m"
#define CGreen "\033[0;32m"
#define CYellow "\033[0;33m"
#define CBlue "\033[0;34m"
#define CPurple "\033[0;35m"
#define CCyan "\033[0;36m"
#define CWhite "\033[0;37m"

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



#define log_trace(...) log_log(LOG_TRACE, CGreen, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, CCyan, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) log_log(LOG_INFO, CWhite, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, CYellow, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, CBlue, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, CRed, __FILE__, __LINE__, __VA_ARGS__)

void log_log(int level, const char* COLOR, const char *file, int line, const char *fmt);

#endif