// mostWondrous.c


#include <stdio.h>
#include <stdlib.h> 

unsigned long long int wondrousLength(unsigned long long int start);

int main(int argc, char *argv[]) {

	// smallest num with wondrous length of 1234

	unsigned long long int n = 1341234558;

	while (wondrousLength(n) < 1234) {
		n++;
	}
	printf("%llu", n);


	return EXIT_SUCCESS;

}

unsigned long long int wondrousLength(unsigned long long int start) {
	unsigned long long int i = 1;
	
	while (start != 1) {
		if (start % 2 == 0) {
    		start = start/2;
    	}
    	else {
   		    start = 3 * start + 1;
        }
        i++;
    }
    return i;
 }