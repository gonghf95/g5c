#ifndef COMMON_LOGGER_H
#define COMMON_LOGGER_H

#include <QString>

class Logger
{
public:
    enum LOG_LEVEL
    {
        INFO,
        DEBUG,
        WARNING,
        ERROR,
        FATAL
    };

    static void info(const QString& func_name, const QString& msg);
};

void LOG_INFO(const char* tag, const char* fmt, ...);

#endif // COMMON_LOGGER_H
