#include <system.h>
#include <multiboot.h>
#include <io.h>
#include <string.h>
#include <types.h>
#include <vmemory.h>
#include <time.h>
#include <gdt.h>
#include "./shell.c"
#include "./vmemory.c"
//#include <ldt.h>

void start_terminal() {
  printf("root@anusOS>");
}

void keyboard_init() ={
  
}

// Kernel init
void kernel(struct multiboot_info *boot_info) {
  console_init();
  gdt_init();
  idt_init();
  keyboard_init();  
  
  char *version = "0.1";
  char *name = "anusOS";
  print("Welcome to %s!",name);
  printf(" version: %s\n",version);
  print("==============================================\n");
  print("VGA setup\t   ... [ok] \n");

  /* multiboot data */
  printf("boot loader name: %s\n", boot_info->boot_loader_name);
  printf("Lower mem: %u Kb, Upper mem: %u Kb\n", (unsigned)boot_info->mem_lower, (unsigned)boot_info->mem_upper);

  /* get real time clock */
  struct time t = get_current_time();
  printf("Time & date ==> %d:%d:%d \t %d/%d/%d\n",t.hours, t.minutes, t.seconds, t.month, t.day_of_month, t.year);
  
  print("Loading virtual memory       ...[Not ok]\n");
  vmem_init();
  
  print("Loading filesystem           ...[Not ok]\n");

  print("Loading system call interface...[Not ok]\n");

  print("Loading system               ...[Not ok]\n");

  print("Loading modules              ...[Not ok]\n");

  asm volatile ("int $0x4");
    asm volatile ("int $0x3");

  start_terminal();
  term();
  while(1);
}
