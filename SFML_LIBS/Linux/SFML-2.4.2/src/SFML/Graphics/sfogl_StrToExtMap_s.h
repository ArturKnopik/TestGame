#ifndef _SFOGL_STRTOEXTMAP_S_H
#define _SFOGL_STRTOEXTMAP_S_H


#include "PFN_LOADFUNCPOINTERS.h"

struct sfogl_StrToExtMap_s {
    const char * extensionName;

    int * extensionVariable;

    PFN_LOADFUNCPOINTERS LoadExtension;

};
#endif
