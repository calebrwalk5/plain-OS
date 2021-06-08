#include <stdio.h>
#include "./include/system.h"
#include "./include/io.h"
#include "./include/string.h"
#include "./include/vmemory.h"
#include "./include/time.h"
#include "./include/types.h"
#include "./programs/hello.c"

int main() {
  term();
  return 0;
}

void term() {
  char cmd[30];
  printf("root@anusOS> ");
  scanf("%s", cmd);
  if (cmd == "hello") {
    hello();
    break;
  } else if (cmd == "help") {
    printf("read through the source code to see what commands you can use\n");
    break;
  } else {
    printf("invalid command\n");
    break;
  }
}
