#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "clspdf.h"
#include <QImage>
#include "mygraphicsitem.h"
#include <QGraphicsItem>
#include <QScopedPointer>
#include <QVector>
#include <QFileDialog>
#include <qdebug.h>
#include <QMessageBox>
#include "mygraphicsitem.h"
#include "mygraphicsitem.cpp"
#include <QPainter>
#include <QPixmap>
#include <QScrollBar>
#include <QRadioButton>
#include <QHash>
#include <QGridLayout>
#include <QSignalMapper>
#include "clsglobal.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
private slots:
    void RadioButtonClick_Execute(int intValue);

	void on_cmdLoad_clicked();

    void on_cmdPeakNumber_clicked();

    void on_cmdPeakNumberErase_clicked();

    void on_cmdSingleLine_clicked();

    void on_cmdDoubleLine_clicked();

    void on_cmdGraph_clicked();

    void on_cmdHDot_clicked();

    void on_cmdVDot_clicked();

    void on_cmdEraser_clicked();

    void on_cmdPreview_clicked();

    void on_cmdSettings_clicked();

    void on_cmdSaveAsImage_clicked();

    void on_cmdLoadProject_clicked();

    void on_cmdLogo_clicked();

    void on_cmdTransparent_clicked();

    void on_cmdSaveAsPDF_clicked();


private:

    clsPDF pdf;
    QGraphicsScene *scene;
    bool fnConvertPDFFileAsTempImage();
    bool fnLoadTempImageFileToScene(const QString &strPNGFile);
	bool fnReLoadPDFFileAsImage();
    bool fnSaveSceneAsPDF();
    bool blnIsCurrentlyPreview=false;
    void fnPreview();
    void fnDeallocateObjects();
    void fnAfterItemAdded(myGraphicsItem<myQGraphicsRectItem> *jj);
    void fnSaveSceneAsImage(QString strPNgFilePath, bool blnShowMSG = true);
    QString strPNGFileFromPDFDocument ,strPDFFileFromPNG, strPDFFile;
    void fnInitShapeOptions(myGraphicsItem<myQGraphicsRectItem> *jj);
    Ui::MainWindow *ui;
    myGraphicsItem<myQGraphicsRectItem> *ActiveShape;
};

#endif // MAINWINDOW_H
