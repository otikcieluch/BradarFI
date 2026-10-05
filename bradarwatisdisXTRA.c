#include <string.h>
#include "bradarwatisdisXTRA.h"

const char *xtrahlp(const char *name) {
    //helper
    if (!strcmp(name,"-h") || !strcmp(name,"--help")) return "BradarFI is a simple file info helper. Usage: bradarwatisdis <filename>";

    


    return NULL;
}

int xtraflags(const char *name, xtraflags *xfl) {

    if (!strcmp(name,"--no-octal")) {xfl->nooctal = 1; return 1; }
    if (!strcmp(name,"--no-modified")) {xfl->nomodified = 1; return 1; }
    if (!strcmp(name,"--no-permissions")) {xfl->noperms = 1; return 1; }
    if (!strcmp(name,"--no-birth-time")) {xfl->nobrdtime = 1; return 1; }
    if (!strcmp(name,"--no-acces-time")) {xfl->noacctime = 1; return 1; }
    if (!strcmp(name,"--no-owner-name")) {xfl->noowner = 1; return 1; }
    if (!strcmp(name,"--no-filesize")) {xfl->nofilesize = 1; return 1; }
    if (!strcmp(name,"--no-filetype")) {xfl->nofiletype = 1; return 1; }
    if (!strcmp(name,"--no-file-content")) {xfl->noflct = 1; return 1; }

    return 0;
}
