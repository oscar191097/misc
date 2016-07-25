// trainGame.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int trainCalc(int one, int two, int three, int four);
int multiply (int a, int b);
int divid (int a, int b);

int main (int argc, char *argv[]) {
	int one, two, three, four;

	printf("Input a four digit number (format eg 1.2.3.4): ");
	scanf("%d.%d.%d.%d", &one, &two, &three, &four);

	printf("Total = %d\n", trainCalc(one,two,three,four));


	return EXIT_SUCCESS;
}

int trainCalc(int one, int two, int three, int four) {
	// test addition
	// test subtraction
	// test mutliplication
	// test division 


	if (one + two + three + four == 10) {
		total++;
	}




	return total;
}

int multiply (int a, int b) {
	int result = a * b;
	return result;
}

int divid (int a, int b) {
	assert(a%b == 0);
	int result = a/b;
	return result;
}