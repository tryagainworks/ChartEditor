#include "clswritesettings.h"
#include <QApplication>
#include <qdebug.h>

//clsWriteSettings objVarGlbWriteSetting;

clsWriteSettings::clsWriteSettings()
{

    //set = new QSettings("D:\\settings",QSettings::IniFormat);
    set = new QSettings(qApp->applicationDirPath()+"/settings",QSettings::IniFormat);
    qDebug() << qApp->applicationDirPath()+"/settings";
    scp.reset(set);
}

void clsWriteSettings::setIntXPixIncrementCount_Normal(const int &value)
{
    set->setValue("x_increment_pixel_normal",value);
}

void clsWriteSettings::setIntYPixIncrementCount_Normal(const int &value)
{
    set->setValue("y_increment_pixel_normal",value);
}

void clsWriteSettings::setIntXPixIncrementCount_Ctrl(const int &value)
{
    set->setValue("x_increment_pixel_ctrl",value);
}

void clsWriteSettings::setIntYPixIncrementCount_Ctrl(const int &value)
{
    set->setValue("y_increment_pixel_ctrl",value);
}

void clsWriteSettings::setFltZoom(const float &value)
{
    set->setValue("zoom",value);
}

void clsWriteSettings::setFltGraphLineThickness(const double &value)
{
    set->setValue("graph_line_thickness",value);
}

void clsWriteSettings::setStrCommand(const QString &value)
{
    set->setValue("command",value);
}

void clsWriteSettings::setStrPDFDirPath(const QString &value)
{
    set->setValue("pdf_open_path",value);
}

void clsWriteSettings::setIntRectWidth(const int &value)
{
    set->setValue("peak_num_width",value);
}

void clsWriteSettings::setIntRectHeight(const int &value)
{
    set->setValue("peak_num_height",value);
}

void clsWriteSettings::setFltTextFontSize(const float &value)
{
    set->setValue("peak_num_font_size",value);
}

void clsWriteSettings::setFltDotLineGapSize(const float &value)
{
    set->setValue("doted_line_gap_size",value);
}

void clsWriteSettings::setFltDotLineBarSize(const float &value)
{
    set->setValue("doted_line_bar_size",value);
}

void clsWriteSettings::setIntDotLineWidthSize(const int &value)
{
    set->setValue("doted_line_width_size",value);
}

void clsWriteSettings::setIntGraphMarkLineGapSize(const int &value)
{
    set->setValue("graph_mark_line_gap_size",value);
}

void clsWriteSettings::setIntGraphMarkLineHeight(const int &value)
{
    set->setValue("graph_mark_line_height",value);
}

void clsWriteSettings::setIntGraphMarkLineWidth(const int &value)
{
    set->setValue("graph_mark_line_width",value);
}

void clsWriteSettings::setIntGreyColorSize(const int &value)
{
    set->setValue("grey_color",value);
}

void clsWriteSettings::setIntBoxSize(const int &value)
{
    set->setValue("box_init_size",value);
}

void clsWriteSettings::setStrFontName(const QString &value)
{
    set->setValue("font_name",value);
}

void clsWriteSettings::setIntFontSize(const int &value)
{
    set->setValue("font_size",value);
}

void clsWriteSettings::setStrPDFSavePath(const QString &value)
{
    set->setValue("pdf_save_path",value);
}

void clsWriteSettings::setStrImageSavePath(const QString &value)
{
    set->setValue("image_save_path",value);
}

void clsWriteSettings::setStrPDFLogoPath(const QString &value)
{
    set->setValue("pdf_logo_path",value);
}

void clsWriteSettings::setStrProfileName(const QString &value)
{
    set->setValue("profile_name",value);
}

void clsWriteSettings::setStrPDFTOIMGCommand(const QString &value)
{
    set->setValue("pdf_to_img_command",value);
}

void clsWriteSettings::setStrIMGTOPDFCommand(const QString &value)
{
    set->setValue("img_to_pdf_command",value);
}
