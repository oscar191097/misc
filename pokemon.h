//pokemon.h

#define MAX_LENGTH 100
#define MAX_TYPE_LENGTH 10

typedef struct _pokemon *Pokemon;

Pokemon newPokemon (char name, int health, int type, int attack, int defense, int luck);
Pokemon populate(void);

void battle(Pokemon a, Pokemon b);