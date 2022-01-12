#include <stdio.h>

#define LABEL_SYMBOL(name)                                                     \
  asm volatile("labelsym_" name "_%=: .global labelsym_" name "_%=" :);

extern void *labelsym_func2_13;

void func2() {
  puts("func2 started");

  LABEL_SYMBOL("func2");

  puts("func2 ended");
}

void func1() {
  puts("func1 started");

  void (*fp)() = labelsym_func2_13;
  // printf("%p\n", labelsym_func2_35);

  puts("func1 ended");
}

// extern void *labelsym_func2_35;

int main() {
  puts("Program started");

  printf("%p\n", labelsym_func2_13);

  puts("Program ended");
}
