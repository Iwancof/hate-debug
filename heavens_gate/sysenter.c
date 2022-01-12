#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

size_t assembly_write(char *str);

int main() {
  char buf[] = "Hello, world!\n";
  void *ptr = mmap((void *)0x10000, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
  if (ptr != (void *)0x10000) {
    printf("mmap failed: %p\n", ptr);
    return 1;
  }

  strcpy(ptr, buf);
  int tmp = assembly_write(ptr);

  printf("%d\n", tmp);
  return 0;
}
