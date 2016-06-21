#include "dlgpreview.h"
#include "ui_dlgpreview.h"

dlgPreview::dlgPreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgPreview)
{
    ui->setupUi(this);
}

dlgPreview::~dlgPreview()
{
    delete ui;
}
