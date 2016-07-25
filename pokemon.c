// pokemon.c

/*
Setup:

In our Pokemon.c land, pokemon have a set of (simplified) distinct traits:

Trait	Description	How to define
Health	How much health you pokemon has	a number between 10 and 100
Type	The pokemon's type	Either: Water, fire, Wind or Earth
Attack	How much potential damage your pokemon can deal	a number between 1 and 20
Defense	How good your pokemon's defence is 	a number between 0 and 10
Luck	How lucky your pokemon is (in both attack and defense)	a number between 20 and 100
Your Challenge:

Write a program that lets you:

Define Pokemon types.
In an "pokedex.c" file
Pit two types against one another
Have a play by play printed out (example down below)

Rules (how the fighting works):

In terms of types: Water beats Fire. Fire beats Wind, Wind beats Earth and Earth beats water.

How to measure damage:

Damagedealt = attackerLuckFactor * attackTypeAdvantage * attack - defence*defendantLuckFactor*defendTypeAdvantage

How to measure luck (this will help)

Luck factor = (rand()%pokemon.luck)/100;

e.g. if bulbasaur has 60 luck, then (rand()%bulbasaur.luck) is anywhere between 0 and 60. Therefore the luck factor is anywhere between 0 and 0.6 (0 is counted as a miss). The same goes for 

Type advantage:

If the attacker/defender has the type advantage (e.g. is water against fire), then their attackTypeAdvantage/defendTypeAdvantage is made = 2;

Otherwise, they are = 1 (i.e. no change is made) 

Note: This is a really complex game here. You are free to change what you like and to expand this game as you wish. There are no limits as to what you're allowed to do. 

And as always, you are free to collaborate and share code, but don't be afraid to have a crack at it first!

Good luck catching them all!

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "pokemon.h"

#define MAX_POKEMON 100

#define WATER 1
#define EARTH 2
#define FIRE 3
#define WIND 4

typedef struct _pokemon {
	char name;
	int health;
	int type;
	int attack;
	int defense;
	int luck;
} pokemon;

int main(int argc, char *argv[]) {
	
	system("clear");

	printf("Welcome to the pokemon battle area!\n\n");

	srand(time(NULL));

	Pokemon *array = malloc(sizeof(struct _pokemon));

	*array = populate();
	battle (array[0], array[1]);

	return EXIT_SUCCESS;
}

Pokemon newPokemon (char name, int health, int type, int attack, int defense, int luck) {
	Pokemon p = malloc(sizeof(struct _pokemon));

	p->name = name;
	p->health = health;
	p->type = type;
	p->attack = attack;
	p->defense = defense;
	p->luck = luck;

	return p;
}

void battle(Pokemon a, Pokemon b) {
// Water > Fire. Fire > Wind, Wind > Earth,Earth > water.
// double damage

//int Damagedealt = attackerLuckFactor * attackTypeAdvantage * attack - defence*defendantLuckFactor*defendTypeAdvantage

//Luck factor = (rand()%pokemon->luck)/100;
	int advantageA;
	int advantageB;

	if (a->type == WATER && b->type == FIRE || a->type == FIRE && b->type == WATER 
		|| a->type == WIND && b->type == EARTH || a->type == EARTH && b->type == WATER) {
		advantageA = 2;
	} else {
		advantageA = 1;
	}

	if (b->type == WATER && a->type == FIRE || b->type == FIRE && a->type == WATER 
		|| b->type == WIND && a->type == EARTH || b->type == EARTH && a->type == WATER) {
		advantageB = 2;
	} else {
		advantageB = 1;
	}

	int damageA = ( a->luck * advantageA * a->attack ) - ( b->luck * advantageB * b->defense);
	int damageB = ( b->luck * advantageB * b->attack ) - ( a->luck * advantageA * a->defense);




}