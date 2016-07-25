//peasPod.c

/*
He invented the Punnett Square. The punnet square is meant to demonstrate the way that genetic traits can emerge. 
Essentially, there are two types of genes: Dominant and Recessive. If a child has two of the same gene then they get 
that trait (e.g. both parents with blue eyes, however if they have one of each, then the dominant trait kicks in
(e.g. one parent with blue (recessive) and one with brown(dominant) )

The challenge: We want to map out a special breed of Guy Segevs. 
Guy Segev's are very peculiar creatures with only two real genes for:

- hair colour: Black (Dominant) and White (Recessive)
- Handedness: Right (Dominant) and Left (Recessive)

We start off with 2 Guy Segevs with random traits (how to gen random numbers here).
We then launch a function "simulateGev(int generations)" which creates that number of generations. 
Each breeding couple makes exactly 2 children. The pairings are also chosen randomly.

Using the punnet square, determine the traits of the next generation.
 
Finally, you should be able to display all your Guy Segevs like this:

4BR 3BL 2WR 3WL (BR stands for Black hair and Right hand, you get the rest)


BIG HINT: Use structs to create a "segev" type to contain each trait
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define RIGHT 1
#define LEFT 0

#define DOMINANT 1
#define RECESSIVE 0

typedef  struct _hairTrait *HairTrait;
typedef  struct _hairTrait {
	char hairType;
	int geneType;
} hairTrait;

typedef struct _handTrait *HandTrait;
typedef struct _handTrait {
	int handType;
	int geneType;
} handTrait;

typedef struct _segev *Segev;
typedef struct _segev {
	HairTrait hair;
	HandTrait hand;
} segev;

void simulateGev(int generations);
Segev newGuy (void);

int main(int argc, char *argv[]) {
	int num;

	srand(time(NULL));

	printf("Enter generations\n");
	scanf("%d", &num);

	simulateGev(num);

	return EXIT_SUCCESS;
}

void simulateGev(int generations) {
	// starting with 2 guys, traits determined randomly 
	Segev guy1 = newGuy();
	Segev guy2 = newGuy();

	// using punnet square breed them
}

Segev newGuy (void) {
	Segev guy = malloc(sizeof(struct _segev));
	
	// determining hair
	if (rand()%2 + 1 == 1) {
		guy->hair->hairType = 'B';
		guy->hair->geneType = DOMINANT;
	} else {
		guy->hair->hairType = 'W';  
		guy->hair->geneType = RECESSIVE;
	}

	// determining hands
	if (rand()%2 + 1 == 1) {
		guy->hand->handType = RIGHT; 
		guy->hand->geneType = DOMINANT;
	} else {
		guy->hand->handType = LEFT;
		guy->hand->geneType = RECESSIVE;
	}

	return guy;
}