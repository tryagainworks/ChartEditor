#include "clspdf.h"

//extern clsGlobalVariables clsGlobal::vecGlobal[0]->objVarGlbReadSetting;
//extern QVector<clsGlobal*> clsGlobal::vecGlobal[0];

clsPDF::clsPDF(QObject *parent) : QObject(parent)
{

}

QString clsPDF::fnSaveAsPNG(const QString &strPDFFilePath)
{
	QString strCommand;
	QProcess prs(this);
	QFileInfo fileinf(strPDFFilePath);
    QString strCreatedPNGFileName = fileinf.baseName() + "." + fileinf.suffix();
    strCreatedPNGFileName = QDir::toNativeSeparators(fileinf.absolutePath()) + QDir::separator() + strCreatedPNGFileName.replace(".pdf","_Temp.png",Qt::CaseInsensitive);

    strCommand = clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getStrPDFTOIMGCommand();
	QStringList strLstCmd = strCommand.split(",");

	prs.setProgram(strLstCmd.at(0).trimmed());

	QStringList lstArgs;
	for(int iCount=1; iCount<strLstCmd.length(); iCount++)
	{
		QString strTemp = strLstCmd.at(iCount).trimmed();
		if(strTemp=="<pdf_file>")
			lstArgs.append(strPDFFilePath);
		else if(strTemp=="<png_file>")
			lstArgs.append(strCreatedPNGFileName);
		else
			lstArgs.append(strLstCmd.at(iCount));
	}
	prs.setArguments(lstArgs);
	prs.start();
	if(prs.waitForFinished())
	{
		QFile file(strCreatedPNGFileName);
		if(file.exists())
		{
			vecPNGFiles.push_back(file.fileName());
			return file.fileName();
		}
		else
			return "*created and error";
	}
	else
		return "*file not created";
}

QString clsPDF::fnSaveAsPDF(const QString &strPNGFilePath)
{
	QString strCommand;
	QProcess prs(this);
	QFileInfo fileinf(strPNGFilePath);
	QString strFileActualName = fileinf.baseName() + "." + fileinf.suffix();
    strFileActualName = QDir::toNativeSeparators(fileinf.absolutePath()) + QDir::separator() + strFileActualName.replace("_TempImageForPDF.png","_SaveAsPDF.pdf",Qt::CaseInsensitive);

    strCommand = clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getStrIMGTOPDFCommand();
	QStringList strLstCmd = strCommand.split(",");

	prs.setProgram(strLstCmd.at(0).trimmed());

	QStringList lstArgs;
	for(int iCount=1; iCount<strLstCmd.length(); iCount++)
	{
		QString strTemp = strLstCmd.at(iCount).trimmed();
		if(strTemp=="<pdf_file>")
			lstArgs.append(strFileActualName);
		else if(strTemp=="<png_file>")
			lstArgs.append(strPNGFilePath);
		else
			lstArgs.append(strLstCmd.at(iCount));
	}
	prs.setArguments(lstArgs);
	prs.start();
	if(prs.waitForFinished())
	{
		QFile file(strFileActualName);
		if(file.exists())
		{
			return file.fileName();
		}
		else
			return "*created and error";
	}
	else
		return "*file not created";
}

QString clsPDF::fnGetPreCmdLine()
{
	return "";
}

QString clsPDF::fnGetPostCmdLine()
{
	return "";
}

bool clsPDF::fnSaveAsPDF(const QString &strPNGFilePath, QPixmap &pixmap)
{
	return false;
}

bool clsPDF::fnDeletePNGFile(const QString &strPNGFilePath)
{
	QFile file(strPNGFilePath);
	if(file.remove())
	{
		qDebug()<<"Deleted " + strPNGFilePath;
		return true;
	}
	else
		return false;
}

bool clsPDF::fnDeleteAllPNGFiles()
{
	QVector<QString>::iterator itr;
	for(itr=vecPNGFiles.begin(); itr!=vecPNGFiles.end(); itr++)
	{
		QFile file(*itr);
		if(file.exists())
		{
            qDebug()<<"Deleting...... : " + *itr;
			if(file.remove())
			{
                qDebug()<<"Deleted : " + *itr;
			}
			else
			{
				return false;
			}
        }else{
            qDebug()<<"File already Deleted : " + *itr;
        }
	}
	vecPNGFiles.clear();
	return true;
}
