#include <string.h>
#include "bradarwatisdisXTRA.h"

const char *xtrahlp(const char *name) {
    //helper
    if (!strcmp(name,"-h") || !strcmp(name,"--help")) return "BradarFI is a simple file info helper. Usage: bradarwatisdis <filename>";

    


    return NULL;
}

int xtraflags(const char *name, xtraflags *xfl) {

    if (!strcmp(name,"--no-octal") {xfl->nooctal = 1; return 1; }
    if (!strcmp(name,"--no-octal") {xfl->nooctal = 1; return 1; }

//wip
