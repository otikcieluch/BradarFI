#ifndef BRADARWATISDISXTRA_H
#define BRADARWATISDISXTRA_H

//the flags struct
typedef struct {
    int nooctal;
    int nomodified;
    int noperms;
    int nobrdtime;
    int noacctime;
    int noowner;
    int nofilesize;
    int nofiletype;
    int noflct;
    int noflname;
} xtraflags;

//help func
const char *xtrahlp(const char *name);

//flags func
int xtraflag(const char *name, xtraflags *xfl);

#endif
