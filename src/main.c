#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "address.h"

int main(int argc, char **argv){

	if(argc == 3){
		int len = atoi(argv[1]);
		int step = atoi(argv[2]);

		double d = log2(step);
		int w = (d == (int)d && step <=32) && len < 256;

		if(!w){
			printf("Error: length=%d, step=%d\nLength must be less than 256\nStep must be one of 1,2,4,8,16,32 aborting...\n", len, step);
			return -1;
		}
		unsigned char *a = generateRandomAddress(len, step);


		cracker(len, step, a);
		free(a);
	}else{
		puts("cracker: <length> <step>");
		return -1;
	}
}
