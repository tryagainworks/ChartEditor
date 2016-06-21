#ifndef CLSGLOBALVARIABLES_H
#define CLSGLOBALVARIABLES_H

#include "clsloadsettings.h"
#include <QGraphicsItem>
#include <QVector>
#include <QDebug>

enum class shapeType : int {PeakNumberErase, PeakNumberDraw, BlankArea, SingleLine, DoubleLine, DrawGraph, VDotedLine, HDotedLine, Logo, Transparent};

class clsGlobalVariables
{
public:
    clsGlobalVariables();

    float getFltXPixIncrementCount_Normal() const;
    float getFltYPixIncrementCount_Normal() const;
    float getFltXPixIncrementCount_Ctrl() const;
    float getFltYPixIncrementCount_Ctrl() const;
    float getFltZoom() const;
    float getFltGraphLineThickness() const;
    QString getStrCommand() const;
    QString getStrPDFDirPath() const;

    float getFltRectWidth() const;
    float getFltRectHeight() const;
    float getFltTextFontSize() const;
    float getFltDotLizeGapSize() const;
    float getFltDotLizeBarSize() const;
    float getFltDotLineWidthSize() const;
    float getFltGraphMarkLineGapSize() const;
    float getFltGraphMarkLineHeight() const;
    float getFltGraphMarkLineWidth() const;
    float getFltGreyColorSize() const;
    float getFltBoxSize() const;

    QString getStrFontName() const;
    int getIntFontSize() const;

    QString getStrPDFSavePath() const;
    QString getStrImageSavePath() const;
    QString getStrPDFLogoPath() const;
    QString getStrProfileName() const;

    QString getStrPDFTOIMGCommand() const;
    QString getStrIMGTOPDFCommand() const;

    QPen objPen;
    QBrush objBrush;
    QColor ColorOnFocusIn,ColorOnFocusOut, clrWhite, clrGrey, clrDarkGrey, ColorOnLocked, clrYellow, clrGraphGreen, clrGraphBlue;
    QVector<QGraphicsItem*> vecGraphicsItem;
    QVector<QPen> vecPen;
    QVector<QBrush> vecBrush;

//private:
    float fltXPixIncrementCount_Normal;
    float fltYPixIncrementCount_Normal;
    float fltXPixIncrementCount_Ctrl;
    float fltYPixIncrementCount_Ctrl;
    float fltZoom;
    float fltGraphLineThickness;
    QString strCommand;
    QString strPDFDirPath;

    float fltRectWidth;
    float fltRectHeight;
    float fltTxtFontSize;
    float fltDotLineGapSize;
    float fltDotLineBarSize;
    float fltDotLineWidthSize;
    float fltGraphMarkLineGapSize;
    float fltGraphMarkLineHeight;
    float fltGraphMarkLineWidth;
    float fltGreyColorSize;
    float fltBoxInitSize;

    QString strFontName;
    int intFontSize;

    QString strPDFSavePath;
    QString strImageSavePath;
    QString strPDFLogoPath;
    QString strProfileName;

    QString strPDFTOIMGCommand;
    QString strIMGTOPDFCommand;
    void fnLoadSettings();
};

#endif // CLSGLOBALVARIABLES_H
