#include "Logger.h"


void log_log(int level, const char* COLOR, const char *file, int line, const char *fmt) {
    #ifdef LOG     
        printf("%s%s : In file %s line %d -> %s\n", COLOR, stringFromLogLevel(level), file, line, fmt);
    #endif
}