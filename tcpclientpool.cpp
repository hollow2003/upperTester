#include "tcpclientpool.h"

TcpClientPool::TcpClientPool(size_t maxSize) {
    max_clients = maxSize;
}

bool TcpClientPool::sendRequest(QString serverIp, QString serverPort, QString rspDuration, QString setupDuration,
                               QString clientIp, QString clientPort, QString cmd) {
    int index = findClient(serverIp, serverPort,
                           clientIp, clientPort);
    if(index == -1) {
        if(createClient(serverIp, serverPort,
                         clientIp, clientPort, setupDuration)) {
            index = tcpClients.count() - 1;
        }
        else {
            qDebug() << "Can't establish connection \n";
            return false;
        }
    }
    QByteArray  str=cmd.toUtf8();
    tcpClients[index].tcpSocket.write(str.append('\n'));
    tcpClients[index].tcpSocket.flush();

    // 限制响应延迟
    int rspTimeout = rspDuration.toInt();
    if (rspTimeout <= 0) {
        rspTimeout = 5000;  // 默认响应时间
    }

    if (tcpClients[index].tcpSocket.waitForReadyRead(rspTimeout)) {
        QString response = tcpClients[index].tcpSocket.readAll();
        qDebug() << "收到响应：" << response;
    } else {
        qDebug() << "响应超时！";
        return false;
    }
    return true;
}


int TcpClientPool::findClient(QString serverIp, QString serverPort,
                              QString clientIp, QString clientPort) {
    for (int i = 0; i < tcpClients.size(); ++i) {
        const auto &item = tcpClients[i];
        if ((item.clientPort == clientPort) && (item.clientIp == clientIp)) {
            if((item.serverPort == serverPort) && (item.serverIp == serverIp)) {
                return i; // 返回匹配的索引
            }
            else{
                removeClient(i);
            }
        }
    }
    return -1; // 未找到时返回 -1
}


bool TcpClientPool::createClient(QString serverIp, QString serverPort,
                                 QString clientIp, QString clientPort, QString setupDuration) {
    if (serverIp.isEmpty() || clientIp.isEmpty() || serverPort.toUShort() == 0 || clientPort.toUShort() == 0) {
        qDebug() << "服务器和客户端 IP 或端口不能为空！";
        return false;
    }
    TcpClient tcpClient;
    tcpClient.clientPort = clientPort;
    tcpClient.clientIp = clientIp;
    tcpClient.serverPort = serverPort;
    tcpClient.serverIp = serverIp;
    QHostAddress clientAddr(clientIp);
    tcpClient.tcpSocket.bind(clientAddr, clientPort.toUShort());
    int timeout = setupDuration.toUInt();
    qDebug() << "绑定ip:：" << clientAddr << ":" << clientPort;
    if (!tcpClient.tcpSocket.bind(clientAddr, clientPort.toUShort())) {
        qDebug() << "绑定失败：" << tcpClient.tcpSocket.errorString();
        return false;
    }
    // 连接服务器
    tcpClient.tcpSocket.connectToHost(serverIp, serverPort.toUShort());
    if (!tcpClient.tcpSocket.waitForConnected(timeout)) {
        qDebug() << "连接超时！";
        return false;
    }
    if(tcpClients.count() >= max_clients) {
        removeClient(0);
        tcpClients.append(tcpClient);
    }
    return true;
}

void TcpClientPool::removeClient(size_t index) {
    tcpClients[index].tcpSocket.disconnectFromHost();

    if (tcpClients[index].tcpSocket.state() == QTcpSocket::UnconnectedState || tcpClients[index].tcpSocket.waitForDisconnected(5000)) {
        qDebug() << "成功断开连接";
    } else {
        qDebug() << "断开连接失败：" << tcpClients[index].tcpSocket.errorString();
    }
    tcpClients[index].tcpSocket.deleteLater(); // 延迟删除，安全释放资源
    tcpClients.removeAt(index);
}
