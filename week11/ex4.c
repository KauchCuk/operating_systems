#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
 int file1 = open("ex1.txt", O_RDWR);
 int file2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IWRITE | S_IREAD);
 struct stat file1_info;
 char* file1_mapped;
 char* file2_mapped;
 fstat(file1, &file1_info);
 ftruncate(file2, file1_info.st_size);
 file1_mapped = mmap(NULL, file1_info.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, file1, 0);
 file2_mapped = mmap(NULL, file1_info.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, file2, 0);
 memcpy(file2_mapped, file1_mapped, file1_info.st_size);
 munmap(file1_mapped, file1_info.st_size);
 munmap(file2_mapped, file1_info.st_size);
 close(file1);
 close(file2);
 return 0;
}
