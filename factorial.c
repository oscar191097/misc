// factorial.c
// by Oscar Downing z5114817

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long int factorial(int num);

long double perm (int n, int r);
long double comb (int n, int r);

int main (int argc, char *argv[]) {
	int n,r;
	printf("Permutation and Combination calculator v1.0\n");
	printf("Enter a set and a number in that set (eg nCr/nPr, format: set num): ");
	scanf("%d %d",&n,&r);

	assert(n >= 0 && r >= 0);

	printf("%dC%d = %Lf\n",n,r,comb(n,r));
	printf("%dP%d = %Lf\n",n,r,perm(n,r));
	
	return EXIT_SUCCESS;
}

unsigned long long int factorial(int num) {
	unsigned long long int result = 1;

	while (num != 0) {
		result = num * result;
		num--;
	}

	return result;
}

// Permutation
//   n!/(n-r)!
// r objects in a set of n
// nPr

long double perm (int n, int r) {
	long double result = 0;

	result = factorial(n)/factorial(n - r);

	return result;
}

// Combination
//  n!/(n-r)!*r!
// r objects in a set of n
// nCr

long double comb (int n, int r) {
	long double result = 0;

	result = factorial(n)/(factorial(r) * factorial(n - r));

	return result;
}