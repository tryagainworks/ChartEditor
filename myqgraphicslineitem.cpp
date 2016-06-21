#include "myqgraphicslineitem.h"

//extern clsGlobalVariables clsGlobal::vecGlobal[0]->objVarGlbReadSetting;
//extern QVector<clsGlobal*> clsGlobal::vecGlobal[0];

myQGraphicsLineItem::myQGraphicsLineItem(shapeType _enmShape):enmShape{_enmShape}
{

}

void myQGraphicsLineItem::fnCreateShape()
{
    switch(enmShape)
    {
    case shapeType::SingleLine:
        break;
    case shapeType::DoubleLine:
        break;
    case shapeType::VDotedLine:
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setStyle(Qt::DotLine);
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.clrGrey);
        this->setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
        this->setLine(10,10,10,100);
        break;
    case shapeType::HDotedLine:
        break;
    }
}

void myQGraphicsLineItem::fnCreateLine(shapeType Type){

}

void myQGraphicsLineItem::fnDrawSupportLine()
{
    if(SupportLineObject.data()==0)
    {
        //QGraphicsTextItem *txt = scene()->addText(QString::number(fltValue));

        //QTransform tr= txt->transform().rotate(-90);
        //txt->setTransform(tr);
        //txt->setPos(pos().x()+(rect().width()/2), pos().y()+rect().height());
        //txtObject.reset(txt);
    }
}

void myQGraphicsLineItem::fnShapeReSize(bool blnIncreased, bool blnCtrl)
{

}

void myQGraphicsLineItem::fnCreateGraphicsVLineDot()
{

}

void myQGraphicsLineItem::fnCreateGraphicsHLineDot()
{

}

bool myQGraphicsLineItem::sceneEvent(QEvent *event)
{
    QGraphicsItem::sceneEvent(event);
}
