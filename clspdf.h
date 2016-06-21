#ifndef CLSPDF_H
#define CLSPDF_H

#include <QObject>
#include <QPixmap>
#include <QProcess>
#include <QSettings>
#include <QFileInfo>
#include <QFile>
#include <qdebug.h>
#include <QDir>
#include "clsglobalvariables.h"
#include <clsglobal.h>

class clsPDF : public QObject
{
    Q_OBJECT

public:
    explicit clsPDF(QObject *parent = 0);
    QString fnSaveAsPNG(const QString &strPDFFilePath);
    QString fnGetPreCmdLine();
    QString fnGetPostCmdLine();
    bool fnSaveAsPDF(const QString &strPNGFilePath, QPixmap &pixmap);
    bool fnDeletePNGFile(const QString &strPNGFilePath);
    bool fnDeleteAllPNGFiles();

    QString fnSaveAsPDF(const QString &strPNGFilePath);

private:
    QVector<QString> vecPNGFiles;
signals:

public slots:
};

#endif // CLSPDF_H
