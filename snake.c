// snake.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_LENGTH 20

#define OVER 0
#define NOT_OVER 1

#define FALSE 0
#define TRUE 1


typedef struct _game * Game;

typedef struct _game {
	int board[MAX_LENGTH][MAX_LENGTH];
	int score;
	int snake;
} game;

void runGame (void);
Game newGame (void);
void drawBoard (Game g);
int getScore (Game g);
void drawApple (Game g);
void growSnake (Game g);
int checkState (Game g);
int eat (Game g);
void getMove (Game g);

int main(int argc, char *argv[]) {
	
	printf("~~~Snake~~~\n");

	srand(time(NULL));

	runGame();

	return EXIT_SUCCESS;
}

void runGame (void) {
	Game g = newGame();

	drawBoard(g);
	drawApple(g);
	while (checkState(g) == NOT_OVER) {
		getMove(g);
		drawBoard(g);
		if (eat(g) == TRUE) {
			growSnake(g);
			drawApple(g);
		}
	}
}

Game newGame (void) {
	Game g = malloc(sizeof(struct _game));

	g->score = 0;
	g->snake = 1;

	int x = 0;
	int y = 0;

	while (y < MAX_LENGTH) {
		x = 0;
		while (x < MAX_LENGTH) {
			if (x == MAX_LENGTH-1 || y == MAX_LENGTH-1 || x == 0 || y == 0) {
				g->board[x][y] = -1;	
			} else if (x == MAX_LENGTH/2 && y == MAX_LENGTH/2 ) {
				g->board[x][y] = 1;
			} else {
				g->board[x][y] = 0;
			}
			x++;
		}
		y++;
	}
	return g;
}

void drawBoard (Game g) {
	int x = 0;
	int y = 0;

	while (y < MAX_LENGTH) {
		x = 0;
		while (x < MAX_LENGTH) {
			if (g->board[x][y] == -1) {
				printf("#");
			} else if (g->board[x][y] == 0) {
				printf(" ");
			} else {
				printf("@");
			}
			x++;
		}
		y++;
		printf("\n");
	}
}

int getScore (Game g) {
	return g->score;
}

void drawApple (Game g) {
	int x = rand()%100;
	int y = rand()%100;

	g->board[x][y] = 2;
}

void growSnake (Game g) {
	g->snake += 2;
}

int checkState (Game g) {

	return NOT_OVER;
}

int eat (Game g) {
	return FALSE;
}

void getMove (Game g) {
	
	char move;
	scanf(" %c", &move);

	int x = 0;
	int y = 0;

	int posX = 0;
	int posY = 0;

	while (y <= MAX_LENGTH) {
		x = 0;
		while (x <= MAX_LENGTH) {
			if (g->board[x][y] == 1) {
				posX = x;
				posY = y;
			}
			x++;
		}
		y++;
	}

	x = posX;
	y = posY;



	if (move == 'a') {
		g->board[x-1][y] = 1;
		g->board[x][y] = 0;
	} else if (move == 'w') {
		g->board[x][y-1] = 1;
		g->board[x][y] = 0;
	} else if (move == 'd') {
		g->board[x+1][y] = 1;
		g->board[x][y] = 0;
	} else if (move == 's') {
		g->board[x][y+1] = 1;
		g->board[x][y] = 0;
	}
}