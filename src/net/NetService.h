#ifndef NET_NETSERVICE_H
#define NET_NETSERVICE_H

#include <QThread>
#include <QTcpSocket>

///
/// \brief The NetService class
///
///
class NetService : public QThread
{
public:
    explicit NetService(QObject* parent=nullptr);

protected:
    virtual void run();

private:
    QTcpSocket* tcpSocket_;
};

#endif
