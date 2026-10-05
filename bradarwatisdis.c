#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "bradarwatisdisKIND.h"
#include "bradarwatisdisFUNC.h"
#include "bradarwatisdisXTRA.h"


//main
int main(int argc, char *argv[]) {
// execution & format
    
    //if no file/dir entered helper
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    //flags
    xtraflags o = {0};
    int nfiles = 0;

    //multi-word filenames
    char filename[1024] = "";
    size_t used = 0;

    //also multi-word filenames
    for (int i = 1; i < argc; i++) {
        //helper
        const char *msghlp = xtrahlp(argv[i]);
        if (msghlp) {
            printf("%s\n", msghlp);
            return 0;
        }

        //flags
        if (xtraflag(argv[i], &o))
            continue;

        //filename proc
        int n;
        if (nfiles > 0) {
            n = snprintf(filename + used, sizeof filename - used, " %s", argv[i]);
        } else {
            n = snprintf(filename + used, sizeof filename - used, "%s", argv[i]);
        }

        if (n < 0 || (size_t)n >= sizeof filename - used) {
            fprintf(stderr, "filename too long\n");
            return 1;
        }
        used += n;
        nfiles++;
    }

    
    struct stat st;
    //error handling
    if (stat(filename, &st) != 0) {
        fprintf(stderr, "pak you %s\n", filename);
        return 1;
    }

    //print file content
    if (!o.noflct) {
        if (strcmp(filetype(filename), "Directory") == 0) {
            printf("Content:  Directory\n");
        } else {
            printf("Content:  %s\n", kind(filename));
        }
    }
    
    //clear
    fflush(stdout);

    //print filename
    printf("File:     %s\n", filename);
    
    //filetype not kind
    if (!o.nofiletype)
        printf("Type:     %s\n", filetype(filename));
    
    //filesizes
    off_t sz;
    if (!o.nofilesize) {
        if (filesize(filename, &sz) == 0)
           printf("Size:     %lld bytes\n", (long long)sz);
    }
    
    //perms
    char perms[11];
    unsigned int octal;
    int haveperms = 0, haveoctal = 0;

    if (!o.noperms)
         haveperms = (permissions(filename, perms) == 0);
    if (!o.nooctal)
         haveoctal = (permsoctal(filename, &octal) == 0);

    if (haveperms && haveoctal)
         printf("Perms:    %s (%o)\n", perms, octal);
    else if (haveperms)
         printf("Perms:    %s\n", perms);
    else if (haveoctal)
         printf("Perms:    (%o)\n", octal);

    //owers and groups
    char user[64], group[64];

    if (!o.noowner && ownernames(filename, user, sizeof user, group, sizeof group) == 0)
        printf("Owner:    %s:%s\n", user, group);
    
    //time
    struct timespec ts;
    char tbuf[64];
    struct tm tm;

    //brd time init
    if (!o.nobrdtime) {
        if (brdtime(filename, &ts) == 0) {
            localtime_r(&ts.tv_sec, &tm);
            strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S", &tm);
            printf("Created:  %s\n", tbuf);
        } else {
            printf("Created:  unavailable\n");
        }
    }

    //mod time init
    if (!o.nomodified && modtime(filename, &ts) == 0) {
        localtime_r(&ts.tv_sec, &tm);
        strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S", &tm);
        printf("Modified: %s\n", tbuf);
    }

    //acc time init
    if (!o.noacctime && acctime(filename, &ts) == 0) {
        localtime_r(&ts.tv_sec, &tm);
        strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S", &tm);
        printf("Accessed: %s\n", tbuf);
    }

    /* old "File:     %n\n"
           "Type:     %F\n"
           "Size:     %s bytes\n"
           "Perms:    %A (%a)\n"
           "Owner:    %U:%G\n"
           "Modified: %y\n",
        "--", filename, (char *)NULL);
     */

    //returns 0
    return 0;
}
