#ifndef DLGPREVIEW_H
#define DLGPREVIEW_H

#include <QDialog>

namespace Ui {
class dlgPreview;
}

class dlgPreview : public QDialog
{
    Q_OBJECT

public:
    explicit dlgPreview(QWidget *parent = 0);
    ~dlgPreview();

private:
    Ui::dlgPreview *ui;
};

#endif // DLGPREVIEW_H
