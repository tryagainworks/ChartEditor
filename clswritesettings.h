#ifndef CLSWRITESETTINGS_H
#define CLSWRITESETTINGS_H
#include <QSettings>

class clsWriteSettings
{
public:
    clsWriteSettings();
    void setIntXPixIncrementCount_Normal(const int &value);
    void setIntYPixIncrementCount_Normal(const int &value);
    void setIntXPixIncrementCount_Ctrl(const int &value);
    void setIntYPixIncrementCount_Ctrl(const int &value);
    void setFltZoom(const float &value);
    void setFltGraphLineThickness(const double &value);
    void setStrCommand(const QString &value);
    void setStrPDFDirPath(const QString &value);

    void setIntRectWidth(const int &value);
    void setIntRectHeight(const int &value);
    void setFltTextFontSize(const float &value);
    void setFltDotLineGapSize(const float &value);
    void setFltDotLineBarSize(const float &value);
    void setIntDotLineWidthSize(const int &value);
    void setIntGraphMarkLineGapSize(const int &value);
    void setIntGraphMarkLineHeight(const int &value);
    void setIntGraphMarkLineWidth(const int &value);
    void setIntGreyColorSize(const int &value);
    void setIntBoxSize(const int &value);

    void setStrFontName(const QString &value);
    void setIntFontSize(const int &value);

    void setStrPDFSavePath(const QString &value);
    void setStrImageSavePath(const QString &value);
    void setStrPDFLogoPath(const QString &value);
    void setStrProfileName(const QString &value);

    void setStrPDFTOIMGCommand(const QString &value);
    void setStrIMGTOPDFCommand(const QString &value);
private:
    QScopedPointer<QSettings> scp;
    QSettings *set;

};

#endif // CLSWRITESETTINGS_H
