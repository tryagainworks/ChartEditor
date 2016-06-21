#include "mainwindow.h"
#include <QApplication>
#include <QVector>
#include "clsglobal.h"
#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QScopedPointer<clsGlobal> scp;
    QApplication a(argc, argv);
    clsGlobal *glb = new clsGlobal();
    scp.reset(glb);
    clsGlobal::vecGlobal.push_back(glb);
    MainWindow w;
    w.show();
    return a.exec();
}

