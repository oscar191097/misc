// countMyAge.c

#include <stdio.h>
#include <stdlib.h>

#define YEAR 2016

void countAge(int age);

int main (int argc, char *argv[]) {
	int age;
	printf("How old are you?: ");
	scanf("%d",&age);
	countAge(age);
	return EXIT_SUCCESS;
}

void countAge(int age) {
	int year = YEAR - age;

	printf("In %d you were born\n",year);

	int n = 1;
	year++;
	while (n < age) {
		printf("In %d you turned %d\n", year, n);
		n++;
		year++;
	}
	printf("Now, in %d, you will turn %d years old!\n",year,n);
}