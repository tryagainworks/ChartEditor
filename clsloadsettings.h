#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QPen>
#include <QBrush>
#include <QColor>
#include <QSettings>
#include <QDir>

class clsLoadSettings
{
public:
    clsLoadSettings();
    void fetchFltXPixIncrementCount_Normal(float &value);
    void fetchFltYPixIncrementCount_Normal(float &value);
    void fetchFltXPixIncrementCount_Ctrl(float &value);
    void fetchFltYPixIncrementCount_Ctrl(float &value);
    void fetchFltZoom(float &value);
    void fetchFltGraphLineThickness(float &value);
    void fetchStrCommand(QString &value);
    void fetchStrPDFDirPath(QString &value);

    void fetchFltRectWidth(float &value);
    void fetchFltRectHeight(float &value);
    void fetchFltTextFontSize(float &value);
    void fetchFltDotLizeGapSize(float &value);
    void fetchFltDotLizeBarSize(float &value);
    void fetchFltDotLineWidthSize(float &value);
    void fetchFltGraphMarkLineGapSize(float &value);
    void fetchFltGraphMarkLineHeight(float &value);
    void fetchFltGraphMarkLineWidth(float &value);
    void fetchFltGreyColorSize(float &value);
    void fetchFltBoxSize(float &value);

    void fetchStrFontName(QString &value);
    void fetchIntFontSize(int &value);

    void fetchStrPDFSavePath(QString &value);
    void fetchStrImageSavePath(QString &value);
    void fetchStrPDFLogoPath(QString &value);
    void fetchStrProfileName(QString &value);

    void fetchStrPDFTOIMGCommand(QString &value);
    void fetchStrIMGTOPDFCommand(QString &value);
private:
    QScopedPointer<QSettings> scp;
    QSettings *set;
};

#endif // CLSSETTINGS_H
