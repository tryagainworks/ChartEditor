#include "clsglobalvariables.h"

//clsGlobalVariables clsGlobal::vecGlobal[0]->objVarGlbReadSetting;

clsGlobalVariables::clsGlobalVariables()
{
    fnLoadSettings();
}

void clsGlobalVariables::fnLoadSettings(){
    clsLoadSettings objSet;

    objSet.fetchFltXPixIncrementCount_Normal(fltXPixIncrementCount_Normal);
    objSet.fetchFltYPixIncrementCount_Normal(fltYPixIncrementCount_Normal);
    objSet.fetchFltXPixIncrementCount_Ctrl(fltXPixIncrementCount_Ctrl);
    objSet.fetchFltYPixIncrementCount_Ctrl(fltYPixIncrementCount_Ctrl);
    objSet.fetchFltZoom(fltZoom);
    objSet.fetchFltGraphLineThickness(fltGraphLineThickness);
    objSet.fetchStrCommand(strCommand);
    objSet.fetchStrPDFDirPath(strPDFDirPath);

    objSet.fetchFltRectWidth(fltRectWidth);
    objSet.fetchFltRectHeight(fltRectHeight);
    objSet.fetchFltTextFontSize(fltTxtFontSize);
    objSet.fetchFltDotLizeGapSize(fltDotLineGapSize);
    objSet.fetchFltDotLizeBarSize(fltDotLineBarSize);
    objSet.fetchFltDotLineWidthSize(fltDotLineWidthSize);
    objSet.fetchFltGraphMarkLineGapSize(fltGraphMarkLineGapSize);
    objSet.fetchFltGraphMarkLineHeight(fltGraphMarkLineHeight);
    objSet.fetchFltGraphMarkLineWidth(fltGraphMarkLineWidth);
    objSet.fetchFltGreyColorSize(fltGreyColorSize);
    objSet.fetchFltBoxSize(fltBoxInitSize);

    objSet.fetchStrFontName(strFontName);
    objSet.fetchIntFontSize(intFontSize);

    objSet.fetchStrPDFSavePath(strPDFSavePath);
    objSet.fetchStrImageSavePath(strImageSavePath);
    objSet.fetchStrPDFLogoPath(strPDFLogoPath);
    objSet.fetchStrProfileName(strProfileName);

    objSet.fetchStrPDFTOIMGCommand(strPDFTOIMGCommand);
    objSet.fetchStrIMGTOPDFCommand(strIMGTOPDFCommand);

    ColorOnFocusIn = QColor::fromRgb(255,0,0);
    ColorOnFocusOut = QColor::fromRgb(0,255,0);
    clrYellow = QColor::fromRgb(242,250,0);
    clrGraphBlue = QColor::fromRgb(0,0,255);
    clrGraphGreen = QColor::fromRgb(0,128,0);
    clrWhite = QColor::fromRgb(255,255,255);
    ColorOnLocked = QColor::fromRgb(0,0,0);
    qDebug() << "Color = " + QString::number(getFltGreyColorSize());
    clrGrey = QColor::fromRgb(getFltGreyColorSize() ,getFltGreyColorSize(),getFltGreyColorSize());
    clrDarkGrey = QColor::fromRgb(75,75,75);
}

float clsGlobalVariables::getFltXPixIncrementCount_Normal() const
{
	return fltXPixIncrementCount_Normal;
}

float clsGlobalVariables::getFltYPixIncrementCount_Normal() const
{
	return fltYPixIncrementCount_Normal;
}

float clsGlobalVariables::getFltXPixIncrementCount_Ctrl() const
{
	return fltXPixIncrementCount_Ctrl;
}

float clsGlobalVariables::getFltYPixIncrementCount_Ctrl() const
{
	return fltYPixIncrementCount_Ctrl;
}

float clsGlobalVariables::getFltZoom() const
{
	return fltZoom;
}

float clsGlobalVariables::getFltGraphLineThickness() const
{
	return fltGraphLineThickness;
}

QString clsGlobalVariables::getStrCommand() const
{
	return strCommand;
}

QString clsGlobalVariables::getStrPDFDirPath() const
{
	return strPDFDirPath;
}

float clsGlobalVariables::getFltTextFontSize() const
{
	return fltTxtFontSize;
}

float clsGlobalVariables::getFltDotLizeGapSize() const
{
	return fltDotLineGapSize;
}

float clsGlobalVariables::getFltDotLizeBarSize() const
{
	return fltDotLineBarSize;
}

float clsGlobalVariables::getFltDotLineWidthSize() const
{
	return fltDotLineWidthSize;
}

float clsGlobalVariables::getFltGraphMarkLineGapSize() const
{
	return fltGraphMarkLineGapSize;
}

float clsGlobalVariables::getFltGraphMarkLineHeight() const
{
	return fltGraphMarkLineHeight;
}

float clsGlobalVariables::getFltGraphMarkLineWidth() const
{
	return fltGraphMarkLineWidth;
}

float clsGlobalVariables::getFltGreyColorSize() const
{
	return fltGreyColorSize;
}

float clsGlobalVariables::getFltRectWidth() const
{
	return fltRectWidth;
}

float clsGlobalVariables::getFltRectHeight() const
{
	return fltRectHeight;
}

float clsGlobalVariables::getFltBoxSize() const
{
	return fltBoxInitSize;
}

QString clsGlobalVariables::getStrFontName() const
{
	return strFontName;
}

int clsGlobalVariables::getIntFontSize() const
{
    return intFontSize;
}

QString clsGlobalVariables::getStrPDFSavePath() const
{
	return strPDFSavePath;
}

QString clsGlobalVariables::getStrImageSavePath() const
{
	return strImageSavePath;
}

QString clsGlobalVariables::getStrPDFLogoPath() const
{
	return strPDFLogoPath;
}

QString clsGlobalVariables::getStrProfileName() const
{
	return strProfileName;
}

QString clsGlobalVariables::getStrPDFTOIMGCommand() const
{
	return strPDFTOIMGCommand;
}

QString clsGlobalVariables::getStrIMGTOPDFCommand() const
{
	return strIMGTOPDFCommand;
}
