#ifndef _SFGLX_STRTOEXTMAP_S_H
#define _SFGLX_STRTOEXTMAP_S_H


#include "PFN_LOADFUNCPOINTERS.h"

struct sfglx_StrToExtMap_s {
    const char * extensionName;

    int * extensionVariable;

    PFN_LOADFUNCPOINTERS LoadExtension;

};
#endif
