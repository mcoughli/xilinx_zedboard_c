#include <stdlib.h>
#include "stdio.h"
#include "ed25519.h"
#include "user_mmap_driver.h"

#define SHARED_BUFFER 0xA0040000
#define RESET_CONTROL 0xB0000000
#define CONTROL_OFFSET 0x280

int main(){
  unsigned char seed[32], public_key[32], private_key[64], data[0x100];
  unsigned char microblaze_signature[64], arm_signature[64];
  unsigned char *shared_buffer, *control;
  shared_memory shared_buffer_mem;
  int i;
  //Use system() to call python programming script. As this program has to
  //be run as root anyways, this should be fine.
  system("/usr/bin/python /home/michael/program_memory.py --bin /home/michael/ecdsa_test.bin --base_address 0xA0000000");
  //reset system
  writeValueToAddress(1, RESET_CONTROL);
  shared_buffer_mem = getSharedMemoryArea(RESET_CONTROL, 0x2000);
  shared_buffer = shared_buffer_mem->ptr;
  control = shared_buffer + 0x280;
  while(*control == 0){
    asm("");
    __asm__("");
  }
  //copy seed
  printf("Seed from microblaze: 0x");
  for(i=0; i<32; i++){
    seed[i] = shared_buffer[i];
    printf("%02x", seed[i]);
  }
  //copy public key
  printf("\nPublic key from microblaze: 0x");
  for(i=0; i<32; i++){
    public_key[i] = shared_buffer[0x20 + i];
    printf("%02x", public_key[i]);
  }
  //copy private key
  printf("\nPrivate key from microblaze: 0x");
  for(i=0; i<64; i++){
    private_key[i] = shared_buffer[0x40 + i];
    printf("%02x", private_key[i]);
  }
  //copy data
  printf("\nMicroblaze signed date:\n0x");
  for(i=0; i<0x100; i++){
    data[i] = shared_buffer[0x80 + i];
    printf("%02x", data[i]);
  }
  //copy generated signature
  printf("Microblaze signature: 0x");
  for(i=0; i<64; i++){
    microblaze_signature[i] = shared_buffer[0x180 + i];
    printf("%02x", microblaze_signature[i]);
  }
  ed25519_sign(arm_signature, data, 0x100, public_key, private_key);
  printf("\nOur signature: 0x");
  for(i=0; i<64; i++){
    printf("%02x", arm_signature[i]);
  }
}