#ifndef TCPCLIENTPOOL_H
#define TCPCLIENTPOOL_H
#include <QString>
#include <QTcpSocket>
#include "xmlDataType.h"

class TcpClientPool
{
public:
    TcpClientPool(size_t maxSize);
    size_t max_clients;
    QList<TcpClient> tcpClients;
    bool sendRequest(QString serverIp, QString serverPort, QString rspDuration, QString setupDuration,
                     QString clientIP, QString clientPort, QString cmd);
    int findClient(QString serverIp, QString serverPort,
                    QString clientIP, QString clientPort);
    bool createClient(QString serverIp, QString serverPort,
                      QString clientIP, QString clientPort, QString setupDuration);
    void removeClient(size_t index);
};

#endif // TCPCLIENTPOOL_H
