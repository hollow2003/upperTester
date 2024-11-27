#include <QString>
#include <QXmlStreamReader>
#include <QFile>
#include "testersconfig.h"

TestersConfig::TestersConfig() {

}

bool TestersConfig::loadFromXml(QString filePath) {
    TestersConfig testersConfig;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << filePath;
        return false;
    }

    QXmlStreamReader xml(&file);
    TesterConfig currentTester;

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();

        if (xml.isStartElement()) {
            const QString elementName = xml.name().toString();
            if (elementName == "FailToContinue") {
                this->failToContinue = (xml.readElementText() == "true");
            } else if (elementName == "SN") {
                this->sn = xml.readElementText().remove('"');
            } else if (elementName == "Tester") {
                currentTester = TesterConfig(); // 开始解析新的 Tester
            } else if (elementName == "TestStyle") {
                currentTester.testStyle = xml.readElementText();
            } else if (elementName == "ItemName") {
                currentTester.itemName = xml.readElementText();
            } else if (elementName == "ReturnType") {
                currentTester.returnType = xml.readElementText();
            } else if (elementName == "CheckThreshold") {
                currentTester.checkThreshold = xml.readElementText();
            } else if (elementName == "FileLoc") {
                currentTester.fileLoc = xml.readElementText().remove('"');
            } else if (elementName == "SetupDuration") {
                currentTester.setupDuration = xml.readElementText();
            } else if (elementName == "RspDuration") {
                currentTester.rspDuration = xml.readElementText();
            } else if (elementName == "ConnectType") {
                currentTester.connectType = xml.readElementText();
            } else if (elementName == "ServerIp") {
                currentTester.tcpConfig.serverIp = xml.readElementText().remove('"');
            } else if (elementName == "ServerPort") {
                currentTester.tcpConfig.serverPort = xml.readElementText();
            } else if (elementName == "ClientIp") {
                currentTester.tcpConfig.clientIp = xml.readElementText().remove('"');
            } else if (elementName == "ClientPort") {
                currentTester.tcpConfig.clientPort = xml.readElementText();
            } else if (elementName == "ADBCmd") {
                currentTester.adbConfig.adbCmd = xml.readElementText().remove('"');
            }
        } else if (xml.isEndElement() && xml.name() == "Tester") {
            this->testers.append(currentTester); // 完成当前 Tester 的解析
        }
    }

    if (xml.hasError()) {
        qDebug() << "XML Parsing Error:" << xml.errorString();
        return false;
    }

    file.close();
    this->sourceFilePath = filePath;
    return true;
}

bool TestersConfig::reloadFromSourceFile() {
    this->testers.clear();
    return this->loadFromXml(this->sourceFilePath);
}

void TestersConfig::appendTestItem(QString itemName) {
    this->testList.append(itemName);
}

void TestersConfig::removeTestItem(QString itemName) {
    for(size_t i = 0; i < this->testList.count(); i++) {
        if(itemName == this->testList.at(i)) {
            this->testList.removeAt(i);
            break;
        }
    }
}

void TestersConfig::testAll() {
    for(auto &item : this->testers) {
        if(this->testList.contains(item.itemName)) {
            qDebug() << "test " << item.itemName << "\n";
        }
    }
}

void TestersConfig::testFailure() {
    for(auto &item : this->testers) {
        if(this->failureList.contains(item.itemName)) {
            qDebug() << "test " << item.itemName << "\n";
        }
    }
}

void TestersConfig::removeAllTestItem() {
    this->testList.clear();
}

void TestersConfig::removeAllResponse() {
    this->testResponse.clear();
}

void TestersConfig::removeAllFailureItem() {
    this->failureList.clear();
}
