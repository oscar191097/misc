/*
* * *WWWWWWW
 * * RRRRRRR
* * *WWWWWWW
RRRRRRRRRRRR
WWWWWWWWWWWW
*/

//project freedom

#include <stdio.h>
#include <stdlib.h>

void fancy (int size);

int main (int argc, char *argv[]) {

	fancy(30);

	return EXIT_SUCCESS;
}

void fancy (int size) {
	int x = 1;
	int y = 1;

	if (size%2 != 0) {
		size = size +1;
	}

	while (y <= size) {
		x = 1;
		while (x <= size*3) {
			if ((x < 3*size/2) && (y <= size/2) && (y%2 != 0)) {
				if (x%2 != 0) {
					printf("*");
				} else {
					printf(" ");
				}
			} else if ((x < 3*size/2) && (y <= size/2) && (y%2 == 0)) {
				if (x%2 == 0) {
					printf("*");
				} else {
					printf(" ");
				}

			} else {
				if (y%2 != 0) {
					printf("W");
				} else {
					printf("/");
				}
			}
			x++;	
		}
		y++;
		printf("\n");
	}

}