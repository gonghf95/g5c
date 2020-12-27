#include "src/common/Logger.h"

#include <QDebug>
#include <QDateTime>
#include <QThread>

namespace detail
{
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
    QString current_thread_id = QString::number(quint64(QThread::currentThreadId()),16);
    QString  log = QString("%1 [%2][0x%3][%4]%5\n").arg(time, level_str(level), current_thread_id, func_name, msg);
    qDebug() << log.toStdString().c_str();
}
}

void Logger::info(const QString &func_name, const QString &msg)
{
    detail::print_log(INFO, func_name, msg);
}

void LOG_INFO(const char *tag, const char *fmt, ...)
{
    char buf[256];
    va_list ap;
    qvsnprintf(buf, sizeof(buf), fmt, ap);
    Logger::info(tag, buf);
}
