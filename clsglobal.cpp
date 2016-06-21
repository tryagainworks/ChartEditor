#include "clsglobal.h"

clsGlobal::clsGlobal()
{

}

clsGlobal::~clsGlobal()
{
    qDebug()<<"clsGlobal Object Cleared";
}

QVector<clsGlobal*> clsGlobal::vecGlobal;
