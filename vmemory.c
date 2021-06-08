#include <vmemory.h>
#include "gdt.c"

void vmem_init() {
  gdt_init();
  /* load gdt, ldt and other initialization */
}
