#include "user_mmap_driver.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void usage(void)
{
	printf("*argv[0] -g <ADDRESS> -f <FILE>\n");
	printf("    -g <ADDR>   GPIO physical address\n");
	printf("    -f          File to progam\n");
	return;
}

int main(int argc, char *argv[]){
  int opt = 0, i = 0, j = 0, fd = 0;
  char *filename = NULL;
  unsigned int val = 0, a = 0, b = 0, c = 0, d = 0, page_base = 0, page_offset = 0;
  unsigned long int address = 0, current_address = 0, fsize;
  unsigned int page_size = sysconf(_SC_PAGESIZE);
  char buffer[4];
  unsigned int *ptr = NULL;
  void *ptr_temp = NULL;

  FILE *fp = NULL;

  while((opt = getopt(argc, argv, "g:f:")) != -1) {
		switch(opt) {
		case 'g':
			address=strtoul(optarg,NULL, 0);
			break;
		case 'f':
			filename=optarg;
			break;
		default:
			printf("invalid option: %c\n", (char)opt);
			usage();
			return -1;
		}

	}

  if(filename == NULL){
    printf("A filename is required\n");
    return -1;
  }

  if(address == 0){
    printf("A valid address is required\n");
    return -1;
  }

  fp = fopen(filename, "rb");
  if(fp == NULL){
    printf("Invalid file: %s\n", filename);
    return -1;
  }
  fseek(fp, 0, SEEK_END);
  fsize = ftell(fp);
  rewind(fp);

  fd = open("/dev/mem", O_RDWR);
  if(fd < 0){
    printf("Error opening dev mem\n");
    return -1;
  }

  printf("Writing %s of size %li to %08lx\n", filename, fsize, address);

//  address_counter = address;
  for(i=0; i<fsize; i+=4){
    current_address = address + i;
    page_base = (current_address / page_size)*page_size;
    page_offset = current_address - page_base;
    printf("fsize: %li, i: %i, addr: %08lx, ", fsize, i, current_address);
    printf("page base: %08x, page offset: %08x, ", page_base, page_offset);
    fread(buffer, 1, 4, fp);
    a = buffer[0];
    b = buffer[1];
    c = buffer[2];
    d = buffer[3];
    val = (a << 24)
        + (b << 16)
        + (c << 8)
        + d;
    printf("val: %08x, ", val);
    printf("a: %02x, b: %02x, c: %02x, d: %02x\n", a, b, c, d);
    ptr_temp = mmap(NULL, 2*page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, page_base);
    if(ptr_temp == MAP_FAILED || ptr_temp < 0){
      printf("Error mmapping\n");
      break;
    }
    ptr = (unsigned int*)(ptr_temp + page_offset);
    ptr[0] = val;
    munmap(ptr_temp, 2*page_size);
    ptr = NULL;
    ptr_temp = NULL;
  }
  close(fd);
  fclose(fp);
  return 0;
}
