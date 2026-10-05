#ifndef BRADARWATISDISXTRA_H
#define BRADARWATISDISXTRA_H

const char *xtrahlp(const char *name);

//the flags struct
typedef struct {
 int nooctal;
 int nomodified;
 int noperms;
 int nobrdtime;
 int noacctime;
 int noowner
 int nofilesize;
 int nofiletype;
 int noflct;
} xtraflags;


#endif
