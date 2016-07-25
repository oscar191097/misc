// ticTacToe.c

/*
Your aim is: to write a Tic-Tac-Toe game in C

 Hint: use three arrays to create the board (one for each row)

Point tiers:

Basic (30 pts) 

-Reads in input as coordinates (e.g. 1 1 is the center) note: the count starts at 0 
-Automatically cycles through players X and O
-Prints out board after every move
-Detects incorrect moves, and lets you move again
-Detects end of game (Win or draw)

Hella Rad (50 pts) 

-Make a bot that plays against you.
-Choose what player you are 
-Have different levels of difficulty (Easy, Moderate, EVIL) 
-Feel free to share your bots and organise a Tic-Tac-Toe FIGHT TO THE DEATH! >:D
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define OVER 0
#define NOT_OVER 1
#define MAX_LENGTH 3
#define TRUE 1
#define FALSE 0
#define NO_ONE -1
#define DRAW 2

typedef struct _game *Game;

typedef struct _game {
	char board[MAX_LENGTH+1][MAX_LENGTH+1];
	int turnNum;
	int state;
	int winner;
} game;

typedef struct _botMove *BotMove;

typedef struct _botMove {
	int x;
	int y;
} botMove;


void drawBoard(Game g);
int isWinner(Game g);
int whoseTurn(Game g);
Game newGame(void);
void makeMove(Game g, char choice);
int isLegal(Game g, int x, int y);
BotMove makeMoveBot(Game g);

int main (int argc, char *argv[]) {
	printf("~~~Tic-Tac-Toe~~~\n");
	Game g = newGame();

	int diff;
	char icon;


	printf("Enter level of AI difficulty: \n");

	printf("Enter level of AI difficulty and preference: Noughts (O's) or Crosses (X's) (format eg: 1 X) \n");
	scanf("%d %c",&diff, &icon);

	int result = FALSE;
	while (result == FALSE) {
		printf("Turn Number: %d\n", g->turnNum);
		printf("Player %d's turn\n", whoseTurn(g)+1);
		drawBoard(g);
		makeMove(g,icon);
		result = isWinner(g);
		if (g->turnNum >= 9) {
			result = DRAW;
		}
	}

	if (result == DRAW) {
		printf("~~~Draw!!!~~~\n");
	} else {
		printf("~~~Player %d's has won!!!~~~\n", whoseTurn(g)+1);
	}
}

Game newGame(void) {
	Game g = malloc(sizeof(struct _game));

	int y = 0;
	int x = 0;
	while (y <= MAX_LENGTH) {
		x = 0;
		while (x <= MAX_LENGTH) {
			g->board[x][y] = '-';
			x++;
		}
		y++;
	}	

	g->turnNum = 0;
	g->state = NOT_OVER;
	g->winner = NO_ONE;

	return g;
}

void drawBoard(Game g) {
	int y = 0;
	int x = 0;

	while (y <= MAX_LENGTH) {
		x = 0;
		while (x <= MAX_LENGTH) {
			if(y == 0){
				printf("[%d]",x);
			} else if (x == 0) {
				printf("[%d]",y);
			} else {
				printf("[%c]",g->board[x][y]);
			}
			x++;
		}
		y++;
		printf("\n");
	}
}

int isWinner(Game g){
	int player = whoseTurn(g);
	char icon = ' ';
	int result = FALSE;
	if (player == 0) {
		icon = 'X';
	} else if (player == 1) {
		icon = 'O';
	}

	int n;

	// checks rows
	n = 1;
	while (n <= 3) {
		if (g->board[n][1] == icon && g->board[n][2] == icon && g->board[n][3] == icon) {
			g->winner = player;
			result = TRUE;
		}
		n++;
	}

	// checks cols
	n = 1;
	while (n <= 3) {
		if (g->board[1][n] == icon && g->board[2][n] == icon && g->board[3][n] == icon) {
			g->winner = player;
			result = TRUE;
		}
		n++;
	}

	// checks diagonals

	if (g->board[1][1] == icon && g->board[2][2] == icon && g->board[3][3] == icon) {
		g->winner = player;
		result = TRUE;
	}

	if (g->board[3][1] == icon && g->board[2][2] == icon && g->board[1][3] == icon) {
		g->winner = player;
		result = TRUE;
	}


	return result;
}

int whoseTurn(Game g) {
	int turn = (g->turnNum)%2;
	return turn;
}

void makeMove(Game g, char choice) {
	if (whoseTurn(g) == 0) {
		int x, y;
		printf("Enter coordinates (format x,y): ");
		scanf("%d,%d", &x, &y);

		if (isLegal(g,x,y) == TRUE) {
			g->board[x][y] = choice;
			g->turnNum++;	
		} else {
			printf(">>>Not a legal action, please enter valid coordinates!\n");
		}
	} else {
		BotMove move = makeMoveBot(g);
		if (isLegal(g,move->x,move->y) == TRUE) {
			if (choice == 'X'){
				g->board[move->x][move->y]  = choice - 9;
			} else {
				g->board[move->x][move->y]  = choice + 9;
			}
			
			g->turnNum++;	
		}
	}
}

int isLegal(Game g, int x, int y) {
	int result = FALSE;
	if (g->board[x][y] != '-' || x > 4 || x < 1 || y > 4 || y < 1) {
		result = FALSE;
	} else {
		result = TRUE;
	}
	return result;
}

BotMove makeMoveBot(Game g) {
	BotMove move = malloc(sizeof(struct _botMove));

	// easy
	srand(time(NULL));
	move->x = rand()%3 + 1;
	move->y = rand()%3 + 1;

	while (isLegal(g, move->x, move->y) != TRUE) {
		move->x = rand()%3 + 1;
		move->y = rand()%3 + 1;
	}

	return move;
}