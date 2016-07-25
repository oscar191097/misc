// warmupPracExam.c


/*

#-#
-#-
#-#

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void cross (int size);

int main (int argc, char *argv[]) {

	int n;
	scanf("%d", &n);
		
	assert(n>0);
	assert(n%2 != 0);

	cross(n);

	return EXIT_SUCCESS;
}

void cross (int size) {
	int x = 0;
	int y = 0;

	int posX = 0;
	int posY = 0;

	size--;


	while (posY <= size) {
		y = posY - size/2.0;
		posX = 0;
		while (posX <= size) {
			x = posX - size/2.0;
			if ((y == abs(x)) || (y == -abs(x))) {
				printf("#");
			} else {
				printf("-");
			}
			posX++;
		}
		posY++;
		printf("\n");
	}
}