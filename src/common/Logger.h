#ifndef G5C_PUBLIC_LOGGER_H
#define G5C_PUBLIC_LOGGER_H

#include <QString>

#define LOG_INFO(str) do{Logger::info(Q_FUNC_INFO, QString(str));}while(0)

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

#endif // G5C_PUBLIC_LOGGER_H
