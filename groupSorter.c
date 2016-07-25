// groupSorter.c

// to write a program that sorts out your students into groups. 
// your program must read in students, and sort them into groups. 

/*
Basic (10 pts) reads in 12 student names and sorts them into either 2, 3, 4 or 6 
groups (user inputs their preferred group number.

e.g. input is Aaron, Stacy.....Steven. Input number of groups = 4

Output:

Group 1 = Aaron, Ronda....

Group 2 = Bill, Ted....

Group 3 = Steven, Lucy...

Group 4 = Nathan, Dominic...

Cool(20 pts) reads in number of students, as well as group size (only needs to handle factors) 

e.g. Input: 10 students, Aaron, Stacy...Steven. num groups = 5

Output (same as above)

Rad (25 pts) Same as the "Cool" tier, but can handle groups that aren't factors, 
e.g. 12 kids sorted into 5 groups. This solution MUST make the groups as EVEN AS POSSIBLE 
(e.g. 8 kids in 3 groups would be groups of 2, 3 and 3)

No group should be more than 1 person larger than another

Hella Rad (30 pts) Same as all of the above, but also reads in Roll from an external file. 
Program reads in only the number of groups
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LENGTH 1000

void sort(char *students);

int main (int argc, char *argv[]) {
	// format: Name Name Name...Name 10
	// parse names and final number

	char *students = malloc(1000*sizeof(char));
	printf("Enter student names (format: Name Name... Name 10): ");
	fgets(students, MAX_LENGTH-1, stdin);

	sort(students);
}

void sort(char *students) {
	int i = 0;
	int n = 0;
	char *array = malloc(1000*sizeof(char));


	students[i] = array[n];

	i++;
	n++;

	int length = strlen(students);

	while (i < length) {
		if (students[i] == ' ') {
			students[i+1] = array[n];
			n++;
		}
		i++;
	}

	i = 0;
	length = strlen(array);
	while (i < length) {
		printf("%c\n", array[i]);
		i++;
	}
}