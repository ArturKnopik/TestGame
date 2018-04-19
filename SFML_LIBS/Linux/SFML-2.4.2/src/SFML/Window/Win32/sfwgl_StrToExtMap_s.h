#ifndef _SFWGL_STRTOEXTMAP_S_H
#define _SFWGL_STRTOEXTMAP_S_H


#include "PFN_LOADFUNCPOINTERS.h"

struct sfwgl_StrToExtMap_s {
    const char * extensionName;

    int * extensionVariable;

    PFN_LOADFUNCPOINTERS LoadExtension;

};
#endif
