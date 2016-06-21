#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H
#include "myqgraphicsrectitem.h"
#include "myqgraphicsellipseitem.h"
#include "myqgraphicslineitem.h"
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QVector>
#include <QGraphicsView>
#include <clsglobal.h>

template <class T>
class myGraphicsItem : public T
{
public:
    myGraphicsItem(shapeType _enmShape);
    ~myGraphicsItem();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

private:
    static int StaticiCount;
    int iCount=0;
    shapeType enmShape;
    void fnMoveShape(QKeyEvent *event);
    bool isCtrlPressed=false, isEnterPressed=false, isAltPressed=false;
    void fnFocusIn();
    void fnFocusOut();
    void fnLocked();
};



#endif // MYGRAPHICSITEM_H
