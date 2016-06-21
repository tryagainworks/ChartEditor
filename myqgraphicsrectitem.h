#ifndef MYQGRAPHICSRECTITEM_H
#define MYQGRAPHICSRECTITEM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QScopedPointer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <qdebug.h>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QHash>
#include <QInputDialog>
#include <QApplication>
#include <clsglobal.h>

//typedef QMap<std::string, ScriptFunction> script_map;

class clsPathItem{
public:
    bool isPathDefined=false;
    float fltNoOfPixels=0.0;
    float fltYAxisChange=0.0;
    float fltDiff = 0.0;
    float fltCurrCursorIndex=0;
    float fltYAxisChangeSign=0;
    float fltBendMovement=0;
    bool blnByMouse=false;
};

class myQGraphicsRectItem : public QGraphicsRectItem
{
public:
    explicit myQGraphicsRectItem(shapeType _enmShape);
    void fnCreateShape();
    void fnShapeReSize(bool blnIncreased, bool blnCtrl);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    shapeType enmShape;
    //void fnInitShapeOptions();
    typedef void (myQGraphicsRectItem::*ScriptFunction)(QKeyEvent *event); // function pointer type
    //typedef void (myQGraphicsRectItem::*ScriptFunction)(void); // function pointer type
    QHash<int, QString> hshDisplay;
    QHash<int, myQGraphicsRectItem::ScriptFunction> hshExecute;
public:
    void fnExecute(int intValue);
private:
    void fnCreateRect();
    void fnDrawFloatText(QString strValue);
    void fnCreateDotedLine();
    void fnCreatePlainLine();
    void fnCreateCircle();
    void fnCreateUnwantedAreaRect();
    void fnClearUnwantedArea();
    void fnZoomInUnwantedAreaRect();
    void fnZoomOutUnwantedAreaRect();
    bool sceneEvent(QEvent *event);
    int intShapeX=50,intShapeY=50, intInitLineSize=50;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QScopedPointer<QGraphicsItem> objAtachedGraphicsObject_1, objAtachedGraphicsObject_2;

    void fnAddPathItem();
    bool blnIsPathItem=false;
    bool blnStartDrawing=false;
    bool isCtrlPressed=false, isAltPressed=false, isLockedByEnterKey=false, blnFirst=true, blnDoLineThickness=false, blnStartCopy=false;
    int intMaxRangeValue=0, intSingleBloclValueInRange=0,intActualRangeTimes=0;
    void fnAdd2ChildRects();
    void fnMoveBoxUpDown(bool blnKeyUp);
    void fnMovePlotCursor(bool blnRight);
    void fnBendGraphLine(bool blnDown);
    clsPathItem objPth;
    void fnAddPathItemMouseDraw();
    void fnDrawGraphLineByMouse(QPointF newPos);
    void fnGraphChangeColor();
    void fnTextChangeLineShape();
    QString strPeakNumber="3338.55";
    void fnLoadBackGroundImage(bool blnRefresh=false);
    void fnKey_1(QKeyEvent *event);
    void fnKey_2(QKeyEvent *event);
    void fnKey_3(QKeyEvent *event);
    void fnKey_4(QKeyEvent *event);
    void fnKey_5(QKeyEvent *event);
    void fnKey_EnterPressed(QKeyEvent *event);
    void fnKey_Minus(QKeyEvent *event);
    void fnKey_Plus(QKeyEvent *event);
    void fnKey_Left(QKeyEvent *event);
    void fnKey_Up(QKeyEvent *event);
    void fnKey_Right(QKeyEvent *event);
    void fnKey_Down(QKeyEvent *event);
    void fnKey_Backspace(QKeyEvent *event);
    void fnKey_Space(QKeyEvent *event);
    void fnKey_Period(QKeyEvent *event);
    void fnKey_Alt_Pressed(QKeyEvent *event);
    void fnKey_Alt_Released(QKeyEvent *event);
    void fnKey_Ctrl_Pressed(QKeyEvent *event);
    void fnKey_Ctrl_Released(QKeyEvent *event);



    void fnLeftCurDown(QKeyEvent *event);
    void fnRightCurDown(QKeyEvent *event);
    void fnInitShapeOptionExecution();
    void fnKey_6(QKeyEvent *event);
    void fnWidth(QKeyEvent *event);
    void fnHeight(QKeyEvent *event);
    void fnLeft(QKeyEvent *event);
    void fnRight(QKeyEvent *event);
    void fnLineThickness(QKeyEvent *event);
    void fnLineGapSize(QKeyEvent *event);
    void fnLineNonGapSize(QKeyEvent *event);
    void fnLock(QKeyEvent *event);
    void fnUnLock(QKeyEvent *event);
    void fnDrawManual(QKeyEvent *event);
    void fnDrawAuto(QKeyEvent *event);
    void fnDrawReset(QKeyEvent *event);
    void fnKey_EnterReleased(QKeyEvent *event);

    void fnWidth1();
    void fnDrawGraphLineByMouseRefresh();
    void fnLoadBackGroundImageResize(bool blnIncrease);
    void fnDrawRangeText(QString strValue);
};



#endif // MYQGRAPHICSRECTITEM_H
