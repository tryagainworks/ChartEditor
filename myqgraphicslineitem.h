#ifndef MYQGRAPHICSLINEITEM_H
#define MYQGRAPHICSLINEITEM_H
#include <QGraphicsLineItem>
#include <clsglobal.h>

class myQGraphicsLineItem : public QGraphicsLineItem
{
public:
    myQGraphicsLineItem(shapeType _enmShape);
    void fnCreateShape();
    void fnShapeReSize(bool blnIncreased, bool blnCtrl);
private:
    void fnCreateGraphicsVLineDot();
    void fnCreateGraphicsHLineDot();
    shapeType enmShape;
    QScopedPointer<QGraphicsLineItem> SupportLineObject;
    bool sceneEvent(QEvent *event);
    void fnDrawSupportLine();
    void fnCreateLine(shapeType Type);
};

#endif // MYQGRAPHICSLINEITEM_H
