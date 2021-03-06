#ifndef MYGRAPHICSITEM_CPP
#define MYGRAPHICSITEM_CPP

#include "mygraphicsitem.h"

//extern QVector<clsGlobal*> clsGlobal::vecGlobal[0];
//extern clsGlobalVariablesclsGlobal::vecGlobal[0]->objVarGlbReadSetting;

template <class T>
int myGraphicsItem<T>::StaticiCount=1;


template <class T>
myGraphicsItem<T>::myGraphicsItem(shapeType _enmShape):T(_enmShape),enmShape {_enmShape}
{
	iCount = StaticiCount++;
	qDebug()<< QString::number(iCount);
	this->T::setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsFocusable);
	T::fnCreateShape();
	qDebug() << "class template created";
}

template <class T>
void myGraphicsItem<T>::fnMoveShape(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Up:
		//if(!isAltPressed)
        T::moveBy(0, -1 * (isCtrlPressed ? clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Ctrl() :clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Normal()));
		break;
	case Qt::Key_Down:
		//if(!isAltPressed)
        T::moveBy(0, 1 * (isCtrlPressed ?clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Ctrl() :clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Normal()));
		break;
	case Qt::Key_Left:
        T::moveBy(-1 * (isCtrlPressed ?clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Ctrl() :clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Normal()), 0);
		break;
	case Qt::Key_Right:
        T::moveBy(1 * (isCtrlPressed ?clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Ctrl() :clsGlobal::vecGlobal[0]->objVarGlbReadSetting.getFltYPixIncrementCount_Normal()), 0);
		break;
	}
}

template <class T>
myGraphicsItem<T>::~myGraphicsItem()
{
	qDebug() << "class template deleted";
}

template <class T>
void myGraphicsItem<T>::keyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Alt:
		isAltPressed=true;
		T::keyPressEvent(event);
		break;
	case Qt::Key_Control:
		isCtrlPressed=true;
		T::keyPressEvent(event);
		break;
	case Qt::Key_Return:
		isEnterPressed = !isEnterPressed;
		isEnterPressed ?  fnLocked() : fnFocusIn();
		T::keyPressEvent(event);
		break;
	case Qt::Key_Up:
	case Qt::Key_Down:
	case Qt::Key_Left:
	case Qt::Key_Right:
		if(!isEnterPressed)
		{
			fnMoveShape(event);
		}
		T::keyPressEvent(event);
		break;
	case Qt::Key_Plus:
		T::fnShapeReSize(true,isCtrlPressed);
		//QGraphicsItem::keyPressEvent(event);
		break;
	case Qt::Key_Minus:
		T::fnShapeReSize(false,isCtrlPressed);
		break;
	case Qt::Key_Tab:
	case Qt::Key_Space:
	case Qt::Key_0:
	case Qt::Key_1:
	case Qt::Key_2:
	case Qt::Key_3: //Fix
	case Qt::Key_4: //Fix Mouse Draw
	case Qt::Key_5: //Refresh
	case Qt::Key_6:
	case Qt::Key_7:
	case Qt::Key_8:
	case Qt::Key_9:
	case Qt::Key_Period:
	case Qt::Key_Backspace:
	case Qt::Key_C:
	case Qt::Key_S:
	case Qt::Key_R:
		T::keyPressEvent(event);
		break;
	}
}

template <class T>
void myGraphicsItem<T>::keyReleaseEvent(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Alt:
		isAltPressed=false;
		T::keyReleaseEvent(event);
		break;
	case Qt::Key_Delete:
		delete this;
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.vecGraphicsItem.operator [](iCount) =0;
		qDebug() << "Deleted";
		break;
	case Qt::Key_Control:
		isCtrlPressed=false;
		T::keyReleaseEvent(event);
		break;
	case Qt::Key_Return:
		break;
	}
	//QGraphicsItem::keyReleaseEvent(event);
}

template <class T>
void myGraphicsItem<T>::focusInEvent(QFocusEvent *event)
{
	switch(enmShape)
	{
	case shapeType::PeakNumberDraw:
	case shapeType::PeakNumberErase:
	case shapeType::DrawGraph:
	case shapeType::BlankArea:
	case shapeType::VDotedLine:
	case shapeType::HDotedLine:
	case shapeType::DoubleLine:
	case shapeType::SingleLine:
	case shapeType::Transparent:
    case shapeType::Logo:
		if(isEnterPressed)
		{
			fnLocked();
		}
		else
		{
			fnFocusIn();
		}
		break;
	}
	QGraphicsItem::focusInEvent(event);
}

template <class T>
void myGraphicsItem<T>::fnFocusIn()
{
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.ColorOnFocusIn);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setStyle(Qt::DashLine);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setWidth(1);
    this->T::setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
}

template <class T>
void myGraphicsItem<T>::fnFocusOut()
{
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.ColorOnFocusOut);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setStyle(Qt::DashLine);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setWidth(1);
    this->T::setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
}

template <class T>
void myGraphicsItem<T>::fnLocked()
{
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setColor(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.ColorOnLocked);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setStyle(Qt::SolidLine);
    clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setWidth(1);
    this->T::setPen(clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen);
}

template <class T>
void myGraphicsItem<T>::focusOutEvent(QFocusEvent *event)
{
	switch(enmShape)
	{
	case shapeType::PeakNumberDraw:
	case shapeType::PeakNumberErase:
	case shapeType::BlankArea:
	case shapeType::DrawGraph:
	case shapeType::VDotedLine:
	case shapeType::HDotedLine:
	case shapeType::DoubleLine:
	case shapeType::SingleLine:
    case shapeType::Logo:
        clsGlobal::vecGlobal[0]->objVarGlbReadSetting.objPen.setStyle(Qt::DashLine);
		if(isEnterPressed)
		{
			fnLocked();
		}
		else
		{
			fnFocusOut();
		}
		break;
	}
	QGraphicsItem::focusOutEvent(event);
}

#endif MYGRAPHICSITEM_CPP
