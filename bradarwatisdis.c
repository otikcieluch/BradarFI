#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "bradarwatisdisKIND.h"
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

//permissions
int permissions(const char *filename, char perms[11])
{
    struct stat sb;
    //error
    if (lstat(filename, &sb) == -1)
        return -1;

    mode_t mode = sb.st_mode;

    //type
    perms[0] = S_ISDIR(mode)  ? 'd' :
               S_ISLNK(mode)  ? 'l' :
               S_ISCHR(mode)  ? 'c' :
               S_ISBLK(mode)  ? 'b' :
               S_ISFIFO(mode) ? 'p' :
               S_ISSOCK(mode) ? 's' : '-';
    perms[1]  = (mode & S_IRUSR) ? 'r' : '-';
    perms[2]  = (mode & S_IWUSR) ? 'w' : '-';
    perms[3]  = (mode & S_IXUSR) ? 'x' : '-';
    perms[4]  = (mode & S_IRGRP) ? 'r' : '-';
    perms[5]  = (mode & S_IWGRP) ? 'w' : '-';
    perms[6]  = (mode & S_IXGRP) ? 'x' : '-';
    perms[7]  = (mode & S_IROTH) ? 'r' : '-';
    perms[8]  = (mode & S_IWOTH) ? 'w' : '-';
    perms[9]  = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';
    return 0;
}

//birth time/date
int brdtime(const char *filename, struct timespec *out)
{
    struct statx sx;

    //errors
    if (statx(AT_FDCWD, filename, 0, STATX_BTIME, &sx) == -1)
        return -1;
    if (!(sx.stx_mask & STATX_BTIME)) {
        errno = ENOTSUP;
        return -1;
    }
    out->tv_sec  = sx.stx_btime.tv_sec;
    out->tv_nsec = sx.stx_btime.tv_nsec;

    return 0;
}
//modification time
int modtime(const char *filename, struct timespec *out)
{
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    *out = sb.st_mtim;
    return 0;
}
//filesize
int filesize(const char *filename, off_t *out)
{
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    *out = sb.st_size;
    return 0;
}
//owner
int ownernames(const char *filename, char *user, size_t ulen,
               char *group, size_t glen)
{
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    struct passwd *pw = getpwuid(sb.st_uid);
    struct group  *gr = getgrgid(sb.st_gid);

    if (pw)
        snprintf(user, ulen, "%s", pw->pw_name);
    else
        snprintf(user, ulen, "%u", (unsigned)sb.st_uid);

    if (gr)
        snprintf(group, glen, "%s", gr->gr_name);
    else
        snprintf(group, glen, "%u", (unsigned)sb.st_gid);

    return 0;
}
//file type
const char *filetype(const char *filename)
{
    char perms[11];

    if (permissions(filename, perms) == -1)
        return "Unknown";
    //types
    switch (perms[0]) {
    case '-': return "Regular file";
    case 'd': return "Directory";
    case 'l': return "Symbolic link";
    case 'c': return "Character device";
    case 'b': return "Block device";
    case 'p': return "FIFO (named pipe)";
    case 's': return "Socket";
    default:  return "Unknown";
    }
}

int main(int argc, char *argv[])
{
    //if no file/dir entered helper
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
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
    printf("Content:  %s\n", kind(filename));
    //clear
    fflush(stdout);

    //Format & execution
    printf("File:     %s\n", filename);
    printf("Type:     %s\n", filetype(filename));
    //filesizes
    off_t sz;
    if (filesize(filename, &sz) == 0)
        printf("Size:     %lld bytes\n", (long long)sz);
    //perms
    char perms[11];
    if (permissions(filename, perms) == 0)
        printf("Perms:    %s\n", perms);
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
