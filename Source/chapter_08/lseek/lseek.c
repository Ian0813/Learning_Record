/*
 * =====================================================================================
 *
 *       Filename:  lseek.c
 *
 *    Description:  read n bytes from position pos
 *
 *        Version:  1.0
 *        Created:  2022年11月27日 02時26分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n) {

    if (lseek(fd, pos, 0) >= 0) {
        return read(fd, buf, n);
    } else {
        return -1;
    }
}

int file_size(int fd) {

    off_t pos;

    pos = lseek(fd, 0, 2);
    return pos;
}

int main(int argc, char *argv[]) {

    int fd, offset, size;
    char buf[BUFSIZ] = {0};
    char *file_name;
    srand(time(NULL));

    if (argc > 1) {
        file_name = argv[1];
    } else {
        file_name = "text.txt";
    }

    fd = open(file_name, O_RDONLY, 0);
    size = file_size(fd);
    offset = rand() % size;
    get(fd, offset, buf, (size - offset));
    printf("read: %s", buf);

    close(fd);
    return 0;
}

