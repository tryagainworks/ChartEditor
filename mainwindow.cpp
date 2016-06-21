#include "mainwindow.h"
#include "ui_mainwindow.h"

//extern clsGlobalVariables clsGlobal::vecGlobal[0]->objVarGlbReadSetting;
//extern QVector<clsGlobal*> clsGlobal::vecGlobal[0];

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    fnDeallocateObjects();
    delete ui;
}

void MainWindow::RadioButtonClick_Execute(int intValue)
{
    qDebug()<<"Value = " << intValue;
    ActiveShape->fnExecute(intValue);
}

void MainWindow::fnDeallocateObjects(){
    for(int iCount=0; iCount<clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.count(); iCount++)
    {
        if(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount)!=NULL)
        {
            qDebug() << "Removed from for loop (" + QString::number(iCount) + ")";
            delete clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount);
        }
    }
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.clear();
    pdf.fnDeleteAllPNGFiles();
}


void MainWindow::on_cmdLoad_clicked()
{
    if(fnConvertPDFFileAsTempImage())
	{
        ui->fraToolContainer->setEnabled(true);
	}
}

bool MainWindow::fnConvertPDFFileAsTempImage()
{
    fnDeallocateObjects();
    //ui->graphicsView->scene()->clear();
    QFileDialog objF(this,"Open PDF File",clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getStrPDFDirPath());
	objF.setNameFilter("PDF Files (*.pdf)");
	objF.exec();
	clsWriteSettings writeSet;
    //writeSet.setStrPDFDirPath(objF.directory().absolutePath());
    strPDFFile = QDir::toNativeSeparators(objF.selectedFiles().at(0));
    strPNGFileFromPDFDocument = pdf.fnSaveAsPNG(strPDFFile);
    if(!strPNGFileFromPDFDocument.startsWith('*'))
	{
        if(fnLoadTempImageFileToScene(strPNGFileFromPDFDocument))
		{
            this->setWindowTitle("Current File - " + strPDFFile);
            QMessageBox::information(this,"PDF File Load","Below File Loaded : \n\n" + strPDFFile + "\n\nYou can edit now.");
            return true;
		}
	}
	else
	{
		QMessageBox::critical(this,"Error","Failed to load the file. (PNG Image file not created. Call System Admin.)");
		return false;
	}
}

bool MainWindow::fnLoadTempImageFileToScene(const QString &strPNGFile)
{
	QPixmap pix = QPixmap::fromImage(QImage(strPNGFile));
    scene->setSceneRect(QRectF(0,0,pix.rect().width(),pix.rect().height()));
    //make the background while when in the case of PNG (if needed)
    scene->setBackgroundBrush(QBrush(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.clrWhite));
    //scene->addRect(scene->sceneRect(),QPen(),QBrush(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.clrWhite));
    QGraphicsPixmapItem *pixItem= scene->addPixmap(pix);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.push_back(pixItem);
	return true;
}

bool MainWindow::fnReLoadPDFFileAsImage()
{
	return false;
}

bool MainWindow::fnSaveSceneAsPDF()
{
    QString strTempPNGFile = strPNGFileFromPDFDocument;
    strTempPNGFile.replace("_Temp.png","_TempImageForPDF.png",Qt::CaseInsensitive);
    fnSaveSceneAsImage(strTempPNGFile,false);

    strPDFFileFromPNG = pdf.fnSaveAsPDF(strTempPNGFile);
    if(!strPDFFileFromPNG.startsWith('*'))
    {
       pdf.fnDeletePNGFile(strTempPNGFile);
       QMessageBox::information(this,"Save As PDF","Current PDF file : \n\n" + strPDFFile  +"\n\nSaved as : \n\n" + strPDFFileFromPNG);
    }
    else
    {
        QMessageBox::critical(this,"Error","Failed to load the file. (PNG Image file not created. Call System Admin.)");
        return false;
    }
}

void MainWindow::fnAfterItemAdded(myGraphicsItem<myQGraphicsRectItem> *jj){
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.push_back(jj);
    scene->addItem(jj);
    jj->moveBy(ui->graphicsView->horizontalScrollBar()->value(), ui->graphicsView->verticalScrollBar()->value());
    scene->setFocusItem(jj);
    scene->setFocus();
    fnInitShapeOptions(jj);
}

void MainWindow::fnInitShapeOptions(myGraphicsItem<myQGraphicsRectItem> *jj){
    QRadioButton *radio[jj->hshDisplay.count()];
    QSignalMapper *sig[jj->hshDisplay.count()];
    QGridLayout *gl = new QGridLayout(ui->groupBox);
    for(int iCount=0;iCount<jj->hshDisplay.count();iCount++){
        radio[iCount] = new QRadioButton(jj->hshDisplay.value(iCount),ui->groupBox);
        radio[iCount]->setVisible(true);
        gl->addWidget(radio[iCount],0,iCount);
        sig[iCount] = new QSignalMapper(this);
        connect(radio[iCount],SIGNAL(clicked()),sig[iCount],SLOT(map()));
        sig[iCount]->setMapping(radio[iCount],iCount);
        connect(sig[iCount],SIGNAL(mapped(int)),this,SLOT(RadioButtonClick_Execute(int)));
    }
}

void MainWindow::on_cmdPeakNumber_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::PeakNumberDraw);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdPeakNumberErase_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::PeakNumberErase);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdSingleLine_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::SingleLine);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdDoubleLine_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::DoubleLine);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdGraph_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::DrawGraph);
    ActiveShape = jj;
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdHDot_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::HDotedLine);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdVDot_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::VDotedLine);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdEraser_clicked()
{
	myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::BlankArea);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdLogo_clicked()
{
    myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::Logo);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdTransparent_clicked()
{
    myGraphicsItem<myQGraphicsRectItem> *jj = new myGraphicsItem<myQGraphicsRectItem>(shapeType::Transparent);
    fnAfterItemAdded(jj);
}

void MainWindow::on_cmdPreview_clicked()
{
	fnPreview();
}

void MainWindow::fnPreview()
{
    if(!blnIsCurrentlyPreview)
	{
        blnIsCurrentlyPreview = true;
		ui->cmdPreview->setText("Undo Preview");
		ui->fraToolContainer->setEnabled(false);
        //0 is the main image on the scene
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecPen.push_back(QPen());
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecBrush.push_back(QBrush());
        for(int iCount=1; iCount<clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.count(); iCount++)
		{
            if(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount)!=0)
			{
                myQGraphicsRectItem *rect = (myQGraphicsRectItem*)clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount);
				rect->setEnabled(false);
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen=rect->pen();
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush=rect->brush();
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecPen.push_back(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecBrush.push_back(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush);
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.clrWhite);
                rect->setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);

				switch(rect->enmShape)
				{
				case shapeType::BlankArea:
				case shapeType::PeakNumberErase:
                    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush.setStyle(Qt::SolidPattern);
                    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.clrWhite);
                    rect->setBrush(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush);
					break;
                case shapeType::HDotedLine:
                case shapeType::VDotedLine:
                    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush.setStyle(Qt::NoBrush);
                    rect->setBrush(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush);
                    break;
				}
			}
			else
			{
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecPen.push_back(QPen());
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecBrush.push_back(QBrush());
			}
		}
	}
	else
	{
        blnIsCurrentlyPreview = false;
		ui->cmdPreview->setText("Preview");
		ui->fraToolContainer->setEnabled(true);
        //0 is the main image on the scene
        for(int iCount=1; iCount<clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.count(); iCount++)
		{
            if(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount)!=0)
			{
                myQGraphicsRectItem *rect = (myQGraphicsRectItem*)clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.at(iCount);
				rect->setEnabled(true);
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen =clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecPen.at(iCount);
                clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush =clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecBrush.at(iCount);
                rect->setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
                rect->setBrush(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objBrush);
			}
		}
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecPen.clear();
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecBrush.clear();
	}
}

void MainWindow::on_cmdSettings_clicked()
{
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.fnLoadSettings();
}

void MainWindow::on_cmdSaveAsImage_clicked()
{
    QString strTemp = strPNGFileFromPDFDocument;
    strTemp.replace("_Temp.png","_SaveAsImage.png",Qt::CaseInsensitive);
    fnSaveSceneAsImage(strTemp);
}

void MainWindow::fnSaveSceneAsImage(QString strPNgFilePath, bool blnShowMSG){
    bool blnPreviewed=false;
    if(!blnIsCurrentlyPreview){
        fnPreview();
        blnPreviewed=true;
    }
    QImage img(ui->graphicsView->scene()->sceneRect().size().toSize(),QImage::Format_ARGB32);
    QPainter painter(&img);
    ui->graphicsView->scene()->clearSelection();
    ui->graphicsView->scene()->render(&painter);
    img.save(strPNgFilePath,"PNG");
    if(blnShowMSG){
        QMessageBox::information(this,"Export as Image","Current PDF file : \n\n" + strPDFFile  +"\n\nExported as : \n\n" + strPNgFilePath);
    }
    if(blnPreviewed){
        fnPreview();
    }
}

void MainWindow::on_cmdLoadProject_clicked()
{

}

void MainWindow::on_cmdSaveAsPDF_clicked()
{
    fnSaveSceneAsPDF();
}
