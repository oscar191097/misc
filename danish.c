// show danish

/*
** *********
** *********

** *********
** *********
*/

#include <stdio.h>
#include <stdlib.h>

void showDanish (void) {
	int x = 1;
	int y = 1;

	while (y <= 5) {
		x = 1;
		while (x <= 12){
			if ((x == 3) || (y == 3)) {
				printf(" ");
			} else {
				printf("*");	
			}
			x++;
		}
		y++;
		printf("\n");
	}
}