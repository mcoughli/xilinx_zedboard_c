#include "user_mmap_driver.h"
#include <openssl/rand.h>
#include <openssl/aes.h>
#include "aes_fpga.h"
#include <time.h>

char *int2bin(int a, char *buffer, int buf_size) {
        buffer += (buf_size - 1);
        int i;
        for (i = 31; i >= 0; i--) {
                *buffer-- = (a & 1) + '0';
                
                a >>= 1;
        }
        
        return buffer;
}


int main(int argc, char** argv){
        int i, j;
        unsigned char data_to_encrypt[] = {0x01, 0x4B, 0xAF, 0x22, 0x78, 0xA6, 0x9D, 0x33, 0x1D, 0x51, 0x80, 0x10, 0x36, 0x43, 0xE9, 0x9A, '\0'};

        unsigned char key[] = {0xE8, 0xE9, 0xEA, 0xEB, 0xED, 0xEE, 0xEF, 0xF0, 0xF2, 0xF3, 0xF4, 0xF5, 0xF7, 0xF8, 0xF9, 0xFA, '\0'};

        unsigned char data_to_encrypt2[] = {0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, '\0'};
	
	int data_length;
        if(argc == 2){
                data_length = atoi(argv[1]);
        } else{
                data_length = 100;
        }
        printf("Data length: %i\n", data_length);
        unsigned char data_to_encrypt3[16*data_length];
        unsigned char encrypted_data_openssl[16*data_length];
	unsigned char encrypted_data_fabric[16*data_length];

        srand (time(NULL));

        int randStart = rand();
        for(i=0; i<data_length; i++){
                for(j=0; j<16; j++){
                        data_to_encrypt3[16*i + j] = i*j+3;//+randStart;
                }
        }

        AES_KEY aes_key;
        AES_set_encrypt_key(key, 128, &aes_key);

        unsigned char* data_pointer = data_to_encrypt3;
        unsigned char* encrypted_dest = encrypted_data_fabric;

        clock_t begin, end;
        begin = clock();
        for(i=0; i<data_length; i++){
                AES_encrypt(data_pointer, encrypted_dest, &aes_key);    
                data_pointer = data_pointer + 16;
                encrypted_dest = encrypted_dest + 16;
        }
	end = clock();
	double ticks = (double)(end - begin);
        double seconds =(double)(end - begin)/CLOCKS_PER_SEC;
        printf ("It took %f clicks (%f seconds) in openssl.\n",ticks,seconds);
//        FILE *openssl_fabric_log;
//        openssl_fabric_log = fopen("aes_openssl_results.csv", "a");
  //      fprintf(openssl_fabric_log, "%f,%i\n", seconds, data_length);
    //    fclose(openssl_fabric_log);
//        int source = SHARED_MEM_BASE;
//        int length = SHARED_MEM_LENGTH;
//        shared_memory shared_system_mem = getUioMemoryArea("/dev/uio1",0x80000);//getSharedMemoryArea(source, length);//getUioMemoryArea("/dev/uio1", length);//=
//        if(shared_system_mem == NULL){
//                printf("Error getting shared system memory pointer");
//                return -1;
//        }
//        int destOffset = 16*data_length +16;
//        int dest = source + destOffset;

//        for(i=0; i<0x1000; i++){
//                ((char*)shared_system_mem->ptr)[i] = 0;
//        }

//        unsigned int output;
//        unsigned int current, currentTotal, k;
//        for(i=0; i<data_length; i++){
//                for(j=0; j<16; j++){
//                        ((char*)shared_system_mem->ptr)[i*16 + (15-j)] = data_to_encrypt3[i*16 + j];
//                }
//	}
	FPGA_AES *cipher = fpga_aes_new(key, 16, 0x1f410000, "qam", "axi-reset");
        data_pointer = data_to_encrypt3;
        encrypted_dest = encrypted_data_openssl;

        begin = clock();
        for(i=0; i<data_length; i++){
                Aes_encrypt_memcpy(cipher, data_pointer, 16, encrypted_dest);    
                data_pointer = data_pointer + 16;
                encrypted_dest = encrypted_dest + 16;
        }
	end = clock();
	ticks = (double)(end - begin);
        seconds =(double)(end - begin)/CLOCKS_PER_SEC;
        printf ("It took %f clicks (%f seconds) in openssl.\n",ticks,seconds);

	printf("\nChecking");
        ticks = clock();

	char bin_buffer[33];
	bin_buffer[32] = '\0';
	int incorrectCount = 0;
        for(i=0; i<data_length; i++){
//              printf("0x");
                for(j=0; j<16; j++){
                        char openssl = encrypted_data_openssl[i*16 + j];
                        int2bin(openssl, bin_buffer, 32);
//                      printf("%02x",openssl);
                        char fabric = encrypted_data_fabric[i*16+j];
			//((char*)shared_system_mem->ptr)[i*16 + (15- j) + destOffset];
//                      printf("\n%02x\t\t|\t%02x", fabric, openssl);
                        if(openssl != fabric){
                                printf("\nChar at index %i is not encrypted correctly. It is %02x in openssl, %02x in fabric", i*16+j, openssl, fabric);
                                incorrectCount++;
                        } 
                }
//              printf(" ");
//              printf("\n-------------------------------------");
        }
        ticks = clock() - ticks;
        printf ("\nIt took %f clicks (%f seconds) to check.\n",(float)ticks,((float)ticks)/CLOCKS_PER_SEC);
	return 0;
}
