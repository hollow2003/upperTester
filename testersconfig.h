#ifndef TESTERSCONFIG_H
#define TESTERSCONFIG_H

#include "xmlDataType.h"

class TestersConfig
{
public:
    QString sn;                            // 测试的序列号
    QList<TesterConfig> testers;           // 包含多个 Tester 的配置
    QList<TestResponse> testResponse;      // 存储测试结果
    TestersConfig();
    bool loadFromXml(QString filePath);
    bool reloadFromSourceFile();
    void appendTestItem(QString itemName);
    void removeTestItem(QString itemName);
    void testAll();
    void testFailure();
    void removeAllTestItem();
    void removeAllResponse();
    void removeAllFailureItem();
private:
    QList<QString> testList;               // 待测试项名称
    QList<QString> failureList;            //测试失败项名称
    QString sourceFilePath;                // 源文件路径
    bool failToContinue;                   // 是否失败时继续
};

#endif // TESTERSCONFIG_H
