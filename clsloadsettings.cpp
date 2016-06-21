#include "clsloadsettings.h"
#include <QApplication>
#include <qdebug.h>

clsLoadSettings::clsLoadSettings()
{
    //set = new QSettings("D:\\settings",QSettings::IniFormat);
    set = new QSettings(qApp->applicationDirPath() +"/settings",QSettings::IniFormat);
    qDebug() << qApp->applicationDirPath()+"/settings";
    scp.reset(set);
}

void clsLoadSettings::fetchFltXPixIncrementCount_Normal(float &value)
{
    value = set->value("x_increment_pixel_normal").toFloat();
}

void clsLoadSettings::fetchFltYPixIncrementCount_Normal(float &value)
{
    value = set->value("y_increment_pixel_normal").toFloat();
}

void clsLoadSettings::fetchFltXPixIncrementCount_Ctrl(float &value)
{
    value = set->value("x_increment_pixel_ctrl").toFloat();
}

void clsLoadSettings::fetchFltYPixIncrementCount_Ctrl(float &value)
{
    value = set->value("y_increment_pixel_ctrl").toFloat();
}

void clsLoadSettings::fetchFltZoom(float &value)
{
    value = set->value("zoom").toFloat();
}

void clsLoadSettings::fetchFltGraphLineThickness(float &value)
{
    value = set->value("graph_line_thickness").toFloat();
}

void clsLoadSettings::fetchStrCommand(QString &value)
{
    value =QDir::toNativeSeparators(set->value("command").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchStrPDFDirPath(QString &value)
{
    value = QDir::toNativeSeparators(set->value("pdf_open_path").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchFltRectWidth(float &value)
{
    value = set->value("peak_num_width").toFloat();
}

void clsLoadSettings::fetchFltRectHeight(float &value)
{
    value = set->value("peak_num_height").toFloat();
}

void clsLoadSettings::fetchFltTextFontSize(float &value)
{
    value = set->value("peak_num_font_size").toFloat();
}

void clsLoadSettings::fetchFltDotLizeGapSize(float &value)
{
    value = set->value("doted_line_gap_size").toFloat();
}

void clsLoadSettings::fetchFltDotLizeBarSize(float &value)
{
    value = set->value("doted_line_bar_size").toFloat();
}

void clsLoadSettings::fetchFltDotLineWidthSize(float &value)
{
    value = set->value("doted_line_width_size").toFloat();
}

void clsLoadSettings::fetchFltGraphMarkLineGapSize(float &value)
{
    value = set->value("graph_mark_line_gap_size").toFloat();
}

void clsLoadSettings::fetchFltGraphMarkLineHeight(float &value)
{
    value = set->value("graph_mark_line_height").toFloat();
}

void clsLoadSettings::fetchFltGraphMarkLineWidth(float &value)
{
    value = set->value("graph_mark_line_width").toFloat();
}

void clsLoadSettings::fetchFltGreyColorSize(float &value)
{
    value = set->value("grey_color").toFloat();
}

void clsLoadSettings::fetchFltBoxSize(float &value)
{
    value = set->value("box_init_size").toFloat();
}

void clsLoadSettings::fetchStrFontName(QString &value)
{
    value = set->value("font_name").toString();
}

void clsLoadSettings::fetchIntFontSize(int &value)
{
    value = set->value("font_size").toInt();
}

void clsLoadSettings::fetchStrPDFSavePath(QString &value)
{
    value = QDir::toNativeSeparators(set->value("pdf_save_path").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchStrImageSavePath(QString &value)
{
    value = QDir::toNativeSeparators(set->value("image_save_path").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchStrPDFLogoPath(QString &value)
{
    value = QDir::toNativeSeparators(set->value("pdf_logo_path").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchStrProfileName(QString &value)
{
    value = set->value("profile_name").toString();
}

void clsLoadSettings::fetchStrPDFTOIMGCommand(QString &value)
{
    value = QDir::toNativeSeparators(set->value("pdf_to_img_command").toString().replace("%%","\\"));
}

void clsLoadSettings::fetchStrIMGTOPDFCommand(QString &value)
{
    value = QDir::toNativeSeparators(set->value("img_to_pdf_command").toString().replace("%%","\\"));
}
