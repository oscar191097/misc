// backwardsName.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 100

char *backwards(char *name);
char *jumble(char *name);

int main (int argc, char *argv[]) {
	char *name = malloc(100*sizeof(char));
	printf("Please enter your name: ");
	
	fgets(name, MAX_LENGTH-1, stdin);

	char *reversed = backwards(name);
	printf("Your name reversed is: %s\n",reversed);
	printf("And your name jumbled is: %s\n", jumble(reversed));
}

char *backwards(char *name) {
	int count = 0;
	while (name[count] != '\0') {
		count++;
	}
	char *reverse = malloc((count+1)*sizeof(char));

	int length = count;
	count--;
	int i = 0;
	while (i <= length) {
		reverse[i] = name[count];

		if (reverse[i] >= 'A' && reverse[i] <= 'Z') {
			reverse[i] += 32;
		}

		count--;
		i++;
	}
	return reverse;
}

// work in progress

char *jumble(char *name) {
	int count = 0;
	while (name[count] != '\0') {
		count++;
	}
	char *jumbled = malloc((count+1)*sizeof(char));

	int length = count;
	int i = 0;
	int n = 0;

	if (length%2 == 0){
		count++;
	}


	while (i <= length) {
		if (i <= count/2) {
			jumbled[i] = name[i + count/2];
		} else if (i > count/2 && n <= length){
			jumbled[i] = name[n];
			n++;
		}
		i++;
	}
	return jumbled;
}