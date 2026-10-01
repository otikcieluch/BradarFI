#ifndef BRADARWATISDISFUNC_H
#define BRADARWATISDISFUNC_H

#include <stddef.h>
#include <sys/types.h>
#include <time.h>

int permissions(const char *filename, char perms[11]);

int brdtime(const char *filename, struct timespec *out);

int modtime(const char *filename, struct timespec *out);

int filesize(const char *filename, off_t *out);

int ownernames(const char *filename, char *user, size_t ulen, char *group, size_t glen);

const char *filetype(const char *filename);

int permsoctal(const char *filename, unsigned int *out);

int acctime(const char *filename, struct timespec *out);

#endif
