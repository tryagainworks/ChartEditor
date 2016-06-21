#include "myqabstractgraphicsshapeitem.h"

myQAbstractGraphicsShapeItem::myQAbstractGraphicsShapeItem()
{
    clrRed = QColor::fromRgb(255,0,0);
    clrGray = QColor::fromRgb(210,210,210);
    this->setFocus();
}

void myQAbstractGraphicsShapeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QMessageBox::information(0,"information","Clicked");
}

void myQAbstractGraphicsShapeItem::keyPressEvent(QKeyEvent *event)
{

}

void myQAbstractGraphicsShapeItem::keyReleaseEvent(QKeyEvent *event)
{

}

void myQAbstractGraphicsShapeItem::focusInEvent(QFocusEvent *event)
{
    objPen.setStyle(Qt::DashLine);
    objPen.setColor(clrRed);
    this->setPen(objPen);
}

void myQAbstractGraphicsShapeItem::focusOutEvent(QFocusEvent *event)
{
    objPen.setStyle(Qt::SolidLine);
    objPen.setColor(clrGray);
    this->setPen(objPen);
}
