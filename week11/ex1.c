#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
 char *filename = "ex1.txt";
 char *text = "This is a nice day";
 int fd = open(filename, O_RDWR);
 struct stat file_stat;
 int size;
 char *addr;
 fstat(fd, &file_stat);
 size = file_stat.st_size;
 addr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
 if(addr == MAP_FAILED) {
  perror("Error mapping the file");
  return 1;
 }
 for(int i = 0; i < strlen(text); i++) {
  addr[i] = text[i];
 }
 fstat(fd, &file_stat);
 size = file_stat.st_size;
 munmap(addr, strlen(text));
 ftruncate(fd, strlen(text));
 close(fd);
}
