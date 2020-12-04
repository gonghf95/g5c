#include "src/public/Logger.h"

#include <QDebug>
#include <QDateTime>
#include <QThread>

namespace detail {
QString level_str(Logger::LOG_LEVEL level)
{
    QString str;
    switch(level)
    {
    case Logger::DEBUG:
        str = "DEBUG";
        break;
    case Logger::WARNING:
        str = "WARNING";
        break;
    case Logger::ERROR:
        str = "ERROR";
        break;
    case Logger::FATAL:
        str = "FATAL";
        break;
    default:
        str = "INFO";
    }
    return str;
}

void print_log(Logger::LOG_LEVEL level,
               const QString& func_name, const QString& msg)
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    qDebug() << time << " [" << level_str(level) << "] " << func_name << " " << msg << endl;
}
}

void Logger::info(const QString &func_name, const QString &msg)
{
    detail::print_log(LOG_LEVEL::INFO, func_name, msg);
}
