#ifndef MYQABSTRACTGRAPHICSSHAPEITEM_H
#define MYQABSTRACTGRAPHICSSHAPEITEM_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>

class myQAbstractGraphicsShapeItem : public QAbstractGraphicsShapeItem
{
public:
    myQAbstractGraphicsShapeItem();
    QPen objPen;
    QColor clrRed,clrGray;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
};

#endif // MYQABSTRACTGRAPHICSSHAPEITEM_H
