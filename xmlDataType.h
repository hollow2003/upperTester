#ifndef XMLDATATYPE_H
#define XMLDATATYPE_H
#include <QString>
#include <QTcpSocket>

// TCP 配置
struct TcpConfig {
    QString serverIp;
    QString serverPort;
    QString clientIp;
    QString clientPort;
};

// ADB 配置
struct AdbConfig {
    QString adbCmd;
};

// TCP socket配置
struct TcpClient {
    QString serverIp;
    QString serverPort;
    QString clientIp;
    QString clientPort;
    QTcpSocket tcpSocket;
};

// Tester 配置
struct TesterConfig {
    QString testStyle;       // 触发方式，例如 "Trigger"
    QString itemName;        // 测试项目名称，例如 "Eth IP"
    QString returnType;      // 返回值类型，例如 "uint32" 或 "FILE"
    QString checkThreshold;      // 检查阈值，可能为空值
    QString fileLoc;         // 文件位置，可能为空值
    QString setupDuration;       // 预设时长
    QString rspDuration;         // 响应时长
    QString connectType;     // 连接类型，例如 "TCP" 或 "ADB"
    TcpConfig tcpConfig;     // TCP 相关配置
    AdbConfig adbConfig;     // ADB 相关配置
};

// 单项测试Response
struct TestResponse {
    QString itemName;
    QString returnType;
    QString responseBody;
};

#endif // XMLDATATYPE_H
