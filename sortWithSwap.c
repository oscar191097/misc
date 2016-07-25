//sortWithSwp


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *swapA, int *swapB);

int main(int argc, char *argv[]) {
	int a;
	int b;
    int c;

	scanf("%d %d %d", &a, &b, &c);

	if ((a < b) && (a < c) && (b < c)) {
		// a b c
	} else if ((a < b) && (a < c) && (b > c)) {
		// a b c
		// swap c with b 
		swap(&c,&b);
	} 


	else if ((b < a) && (b < c) && (a < c)) {
		// a b c
		// b a c
		swap(&b,&a);
	} else if ((b < a) && (b < c) && (a > c)) {
		// a b c
		// b a c
		// b c a
		swap(&b,&a);
		swap(&b,&c);
	}

	else if ((c < a) && (c < b) && (b < a)) {
		// a b c
		// c b a
		swap(&c,&a);
	} else if ((c < a) && (c < b) && (a < b)) {
		// a b c
		// c b a 
		// c a b
		swap(&c,&a);
		swap(&b,&c);
	}

	printf("%d\n%d\n%d\n", a, b, c);

	return EXIT_SUCCESS;
}

void swap(int *swapA, int *swapB) {
	int temp;
	temp = *swapA;

	*swapA = *swapB;
	*swapB = temp;
}