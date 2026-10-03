#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "bradarwatisdisFUNC.h"





int permissions(const char *filename, char perms[11]) {
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
    //setuid
    perms[3]  = (mode & S_ISUID) ? ((mode & S_IXUSR) ? 's' : 'S')
    : ((mode & S_IXUSR) ? 'x' : '-');
    perms[4]  = (mode & S_IRGRP) ? 'r' : '-';
    perms[5]  = (mode & S_IWGRP) ? 'w' : '-';
    //setgid
    perms[6]  = (mode & S_ISGID) ? ((mode & S_IXGRP) ? 's' : 'S')
    : ((mode & S_IXGRP) ? 'x' : '-');
    perms[7]  = (mode & S_IROTH) ? 'r' : '-';
    perms[8]  = (mode & S_IWOTH) ? 'w' : '-';
    //sticky
    perms[9]  = (mode & S_ISVTX) ? ((mode & S_IXOTH) ? 't' : 'T')
    : ((mode & S_IXOTH) ? 'x' : '-');
    perms[10] = '\0';
    return 0;
}

//birth time/date
int brdtime(const char *filename, struct timespec *out) {
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
int modtime(const char *filename, struct timespec *out) {
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    *out = sb.st_mtim;
    return 0;
}

//filesize
int filesize(const char *filename, off_t *out) {
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    *out = sb.st_size;
    return 0;
}

//owner
int ownernames(const char *filename, char *user, size_t ulen, char *group, size_t glen) {
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
const char *filetype(const char *filename) {
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

//octal mode
int permsoctal(const char *filename, unsigned int *out) {
    struct stat sb;
    //error
    if (lstat(filename, &sb) == -1)
        return -1;

    *out = sb.st_mode & 07777;
    return 0;
}

//access time
int acctime(const char *filename, struct timespec *out) {
    struct stat sb;
    //error
    if (stat(filename, &sb) == -1)
        return -1;

    *out = sb.st_atim;
    return 0;
}
