// erathosthenes.c

/*
- Create an array of consecutive integers from 2 through n: (2, 3, 4, ..., n).
- Initially, let p equal 2, the smallest prime number.
- Make a while loop to go through the multiples of p by counting to n from 2p in increments of p, and mark them in 
  the list (these will be 2p, 3p, 4p, ... ; the p itself should not be marked).
- Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, 
  let p now equal this new number (which is the next prime), and repeat from step 3.
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void theSieve(int n);
int findPrime(int num);


int main(int argc, char *argv[]) {
	int n;
	printf("Enter a number (n): \n");
	scanf("%d",&n);
	
	printf("The number of primes <= n is: ");
	double start = clock();
	theSieve(n);
	double end = clock();
	printf("time taken: %lf seconds\n", (end - start)/CLOCKS_PER_SEC);
}

void theSieve(int n) {
	// start with 2
	// cross out all multiples of 2
	// then move to 3
	// cross out all mutliple of 3
	// then continue repeating

	int *numSet = malloc(n*sizeof(int));

	// populate array
	int i = 0;
	int p = 2;

	while (i <= n-2) {
		numSet[i] = p;
		i++;
		p++;
	}


	i = 0;
	int count = 0;
	int numOfPrimes = 0;

	while (i <= n-2) {
		if (numSet[i] != -1 && findPrime(numSet[i]) == TRUE) {
			numOfPrimes++;
			count = 1;
			while (count <= n-2) {
				if (numSet[i] * count == numSet[count]) {
					numSet[count] = -1;
				}
				count++;
			}
		}
		i++;
	}

	printf("%d\n", numOfPrimes );
	free(numSet);
}

int findPrime(int num) {
	int result = TRUE;
	int i = 2;

	while (i < num) {
		if (num%i == 0) {
			result = FALSE;
	   }
		i++;
	}
	return result;
}

