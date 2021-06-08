#include <stdio.h>
#include "./include/system.h"
#include "./include/io.h"
#include "./include/string.h"
#include "./include/vmemory.h"
#include "./include/time.h"
#include "./include/types.h"

int main() {
  term();
  return 0;
}
int term() {
  char cmd[30];
  printf("Welcome to the anusOS shell, enjoy your stay\n");
  printf("root@anusOS> ");
  scanf("%s", cmd);
}
