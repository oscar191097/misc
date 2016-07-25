// pokedex.c 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "pokemon.h"

#define MAX_POKEMON 100

Pokemon populate (void) {
	//fill array 

	Pokemon array[MAX_POKEMON] = {NULL};

	// 1st pokemon
	Pokemon rick = newPokemon('R', 20, 1, 9, 9, 5);
	// 2nd pokemon
	Pokemon morty = newPokemon('M', 20, 1, 9, 9, 5);

	array[0] = rick;
	array[1] = morty;

	return *array;
}