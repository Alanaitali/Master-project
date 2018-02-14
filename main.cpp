#include "MainWindow.h"
#include "MyTcpSocket.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

void read_ip()
{
    QFile inputFile("/etc/remote_ip.conf");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        MyTcpSocket::set_ip(inputFile.readAll());
        inputFile.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    read_ip();
    w.show();
    return a.exec();
}


