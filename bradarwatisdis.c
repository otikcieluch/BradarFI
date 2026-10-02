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

    //helper
    const char *msghlp = xtra(filename);
    if(msghlp) {
        printf("%s\n",msghlp);
        return 1;
    }

    //multi-word filenames
    char filename[1024] = "";
    size_t used = 0;

    //also multi-word filenames
    for (int i = 1; i < argc; i++) {
        int n = snprintf(filename + used, sizeof filename - used,
                         "%s%s", i > 1 ? " " : "", argv[i]);
        if (n < 0 || (size_t)n >= sizeof filename - used) {
            fprintf(stderr, "filename too long\n");
            return 1;
        }
        used += n;
    }

    struct stat st;
    //error handling
    if (stat(filename, &st) != 0) {
        fprintf(stderr, "pak you %s\n", filename);
        return 1;
    }

    //print file type
    if (strcmp(filetype(filename), "Directory") == 0) {
    printf("Content:  Directory\n");
    } else {
    printf("Content:  %s\n", kind(filename));
    }
    //clear
    fflush(stdout);

    
    printf("File:     %s\n", filename);
    printf("Type:     %s\n", filetype(filename));
    //filesizes
    off_t sz;
    if (filesize(filename, &sz) == 0)
        printf("Size:     %lld bytes\n", (long long)sz);
    //perms
    char perms[11];
    unsigned int octal;
    if (permissions(filename, perms) == 0 && permsoctal(filename, &octal) == 0)
    printf("Perms:    %s (%o)\n", perms, octal);
    
    //owers and groups
    char user[64], group[64];
    
    if (ownernames(filename, user, sizeof user, group, sizeof group) == 0)
        printf("Owner:    %s:%s\n", user, group);

    struct timespec ts;
    char tbuf[64];
    struct tm tm;
    
    //brd time init
    if (brdtime(filename, &ts) == 0) {
        localtime_r(&ts.tv_sec, &tm);
        strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S", &tm);
        printf("Created:  %s\n", tbuf);
    } else {
        printf("Created:  unavailable\n");
    }
    
    //mod time init
    if (modtime(filename, &ts) == 0) {
        localtime_r(&ts.tv_sec, &tm);
        strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S", &tm);
        printf("Modified: %s\n", tbuf);
    }

    //acc time init
    if (acctime(filename, &ts) == 0) {
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
