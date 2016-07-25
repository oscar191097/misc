// contacts.c

/*
Your Challenge: Build a contact list in c.

Each contact should have these elements:

First Name
Last Name
Phone Number
Address
Email

You are free to:

Design your own UI
For creating contacts
For accessing contacts 

Extra features:

Searching functionality (this might help)
Random prank call functionality (this might help)
Gives you a random number from the contact list to call
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define FG_RED     "\x1b[31m"
#define FG_GREEN   "\x1b[32m"
#define FG_YELLOW  "\x1b[33m"
#define FG_BLUE    "\x1b[34m"
#define FG_MAGENTA "\x1b[35m"
#define FG_CYAN    "\x1b[36m"
#define FG_RESET   "\x1b[0m"

#define BG_RESET "\e[m"
#define BG_RED "\e[41m"
#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"
#define BG_BLUE "\e[44m"
#define BG_PINK "\e[45m"
#define BG_CYAN "\e[46m"
#define BG_GREY "\e[100m"
#define BG_SKY_BLUE "\e[104m"

#define MAX_LENGTH 100

typedef struct _contact * Contact;

typedef struct _contact {
	char firstName[MAX_LENGTH];
	char lastName[MAX_LENGTH];
	int phoneNum;
	char address[MAX_LENGTH];
	char email[MAX_LENGTH];
} contact;

Contact newContact ();
void displayContact ();
void interface ();

int main(int argc, char *argv[]) {
	//array of contacts instead
	interface();

	return EXIT_SUCCESS;
}

Contact newContact () {
	Contact c = malloc(sizeof(struct _contact));

	printf("Enter first name: ");
	scanf("%s", c->firstName);

	printf("Enter last name: ");
	scanf("%s", c->lastName);

	printf("Enter phone number: ");
	scanf("%d", &c->phoneNum);

	printf("Enter address name: ");
	scanf("%s", c->address);

	printf("Enter email: ");
	scanf("%s", c->email);
	
	printf("\n");

	return c;
}

void displayContacts () {

}

void interface () {
	Contact array[MAX_LENGTH];

	printf("~~~Contact Application~~~\n");
	printf("1. Display Contacts \n2. New Contacts \n");

	int num;
	scanf("%d", &num);

	if (num == 1) {
		displayContacts();	
	} else if (num == 2) {
		array[0] = newContact();		
	}

	printf("%s\n", array[0]);

	// enter new 
}