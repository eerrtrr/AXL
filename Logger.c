#include "Logger.h"


void log_log(int level, const char* COLOR, const char *file, int line, const char *fmt, ...) {
    #ifdef LOG
        printf("%s%s : In file %s line %d -> ", COLOR, stringFromLogLevel(level), file, line);
        
        char buffer[256];
        va_list args;
        va_start(args, fmt);
        vsprintf(buffer,fmt, args);
        perror(buffer);
        va_end(args);
    #endif
}