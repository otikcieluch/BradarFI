#include <string.h>
#include "bradarwatisdisXTRA.h"

//helper
const char *xtrahlp(const char *name) {
    //helper
    if (!strcmp(name,"-h") || !strcmp(name,"--help")) {
        return "BradarFI is a simple file info helper.\n"
               "Usage: bradarwatisdis <filename> [flags]\n"
               "Flags:\n"
               "  --no-file           hide File\n"
               "  --no-file-content   hide Content\n"
               "  --no-filetype       hide Type\n"
               "  --no-filesize       hide Size\n"
               "  --no-permissions    hide the rwx string\n"
               "  --no-octal          hide the octal mode\n"
               "  --no-owner-name     hide Owner\n"
               "  --no-birth-time     hide Created\n"
               "  --no-modified       hide Modified\n"
               "  --no-access-time    hide Accessed";


    }

    


    return NULL;
}

//flags
int xtraflag(const char *name, xtraflags *xfl) {
    
    //flags
    if (!strcmp(name,"--no-octal")) {xfl->nooctal = 1; return 1; }
    if (!strcmp(name,"--no-modified")) {xfl->nomodified = 1; return 1; }
    if (!strcmp(name,"--no-permissions")) {xfl->noperms = 1; return 1; }
    if (!strcmp(name,"--no-birth-time")) {xfl->nobrdtime = 1; return 1; }
    if (!strcmp(name,"--no-access-time")) {xfl->noacctime = 1; return 1; }
    if (!strcmp(name,"--no-owner-name")) {xfl->noowner = 1; return 1; }
    if (!strcmp(name,"--no-filesize")) {xfl->nofilesize = 1; return 1; }
    if (!strcmp(name,"--no-filetype")) {xfl->nofiletype = 1; return 1; }
    if (!strcmp(name,"--no-file-content")) {xfl->noflct = 1; return 1; }
    if (!strcmp(name,"--no-file")) {xfl->noflname = 1; return 1; }

    return 0;
}
