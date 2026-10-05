#include <string.h>
#include "bradarwatisdisXTRA.h"

const char *xtrahlp(const char *name) {
    //helper
    if (!strcmp(name,"-h") || !strcmp(name,"--help")) return "BradarFI is a simple file info helper. Usage: bradarwatisdis <filename>";

    


    return NULL;
}

int xtraflags(const char *name) {

    if (!strcmp(name,"--no-octal"

//wip
