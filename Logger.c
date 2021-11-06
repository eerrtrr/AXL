#include "Logger.h"


void log_log(int level, const char *file, int line, const char *fmt) {
    #ifdef LOG     
        printf("%s : In file %s line %d -> %s\n", stringFromLogLevel(level), file, line, fmt);
    #endif
}