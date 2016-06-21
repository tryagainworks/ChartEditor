#ifndef MYQGRAPHICSELLIPSEITEM_H
#define MYQGRAPHICSELLIPSEITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include "clswritesettings.h"
#include "clsglobalvariables.h"

class myQGraphicsEllipseItem :  public QGraphicsEllipseItem
{
public:
    myQGraphicsEllipseItem(shapeType _enmShape);
    void fnCreateShape();
    void fnShapeReSize(bool blnIncreased, bool blnCtrl);
private:
    void fnCreateCircle();
    void fnDrawGraph();
    void fnUnDoDrawGraph();
    shapeType enmShape;
};

#endif // MYQGRAPHICSELLIPSEITEM_H
