#ifndef CLSGLOBAL_H
#define CLSGLOBAL_H

#include "clsglobalvariables.h"
#include "clswritesettings.h"
#include "qdebug.h"

class clsGlobal
{
public:
    clsGlobal();
    ~clsGlobal();
    clsGlobalVariables objVarGlbReadSetting;
    clsWriteSettings objVarGlbWriteSetting;
    static QVector<clsGlobal*> vecGlobal;
};

#endif // CLSGLOBAL_H
