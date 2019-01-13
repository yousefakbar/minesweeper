#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "structs.h"
#include "board.h"


void validateArgs(int argC) {
	//validates command line arguments. [seed] is optional

	if (argC < 4) {
		printf("Not enough arguments. ");
		printf("Usage:\n ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit(0);
	}
	else if (argC > 5) {
		printf("Too many arguments. ");
		printf("Usage:\n ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit(0);
	}

}


void setupTiles(Board* gameBoard) {
	//allocates memory for each tile and sets them as concealed tiles

	int i, j;

	gameBoard->tiles = (Tile**)malloc((gameBoard->numRows) * sizeof(Tile*));

	for (i=0; i < gameBoard->numRows; i++) {
		gameBoard->tiles[i] = (Tile*)malloc((gameBoard->numCols) * sizeof(Tile));

		for (j=0; j < gameBoard->numCols; j++) {
			gameBoard->tiles[i][j].mine = false;
			gameBoard->tiles[i][j].status = '#';
		}
	}

}


void setMines(Board* gameBoard) {
	//randomly generate mine positions and place if not already a mine tile

	int numMines = 0;
	int mineRow, mineCol;

	if (gameBoard->seedVal == -1) { //if no seed is input
		srand(time(0));
	}
	else {
		srand(gameBoard->seedVal);
	}

	while (numMines < gameBoard->numMines) {

		mineRow = rand() % gameBoard->numRows;
		mineCol = rand() % gameBoard->numCols;

		if (gameBoard->tiles[mineRow][mineCol].mine == false) {
			printf("Placing mine at %d, %d\n", mineRow, mineCol);

			gameBoard->tiles[mineRow][mineCol].mine = true;
			numMines++;
		}

	}

}


int countMines(Board* gameBoard, int i, int j) {
	//for a specified tile, counts number of mines in surrounding tiles

	int row, col;
	int numMines = 0;

	for (row = i-1; row <= i+1; row++) {
		for (col = j-1; col <= j+1; col++) {

			if(row == i && col == j) { //if checking the original specified tile
				continue;
			}

			if (withinBoundary(gameBoard, row, col) && gameBoard->tiles[row][col].mine) {
				numMines++;
			}
			else {
				continue;
			}

		}
	}

	return numMines;
}


bool withinBoundary(Board* gameBoard, int i, int j) {
	return i >= 0 && i < gameBoard->numRows && j >= 0 && j < gameBoard->numCols;
}


void init_board(int argC, char** argV, Board* gameBoard) {
	//initialize all aspects of the board, command line arguments

	int i, j;

	validateArgs(argC);

	gameBoard->numRows = atoi(argV[1]);
	gameBoard->numCols = atoi(argV[2]);
	gameBoard->numMines = atoi(argV[3]);
	
	if (argC == 5) {
		gameBoard->seedVal = atoi(argV[4]);
	}
	else {
		gameBoard->seedVal = -1;
	}

	setupTiles(gameBoard);
	setMines(gameBoard);

	for (i=0; i < gameBoard->numRows; i++) {
		for (j=0; j < gameBoard->numCols; j++) {
			gameBoard->tiles[i][j].minesAround = countMines(gameBoard, i, j);
		}
	}

}


void displayBoard(Board gameBoard) {

	int i, j;

	for (i = gameBoard.numRows - 1; i >= 0; i--) {
		
		printf("%d ", i);

		for (j=0; j < gameBoard.numCols; j++) {
			
			if (gameBoard.tiles[i][j].status == 'R') {
				printf("%d ", gameBoard.tiles[i][j].minesAround);
			}
			else {
				printf("%c ", gameBoard.tiles[i][j].status);
			}
		}

		printf("\n");
	}

	printf("  ");

	for (j=0; j < gameBoard.numCols; j++) {
		printf("%d ", j);
	}

	printf("\n");

}


void minesLeft(Board gameBoard) {
	printf("There are %d mines left\n", gameBoard.numMines);
}


void revealAll(Board* gameBoard) {

	int i, j;

	for (i=0; i < gameBoard->numRows; i++) {
		for (j=0; j < gameBoard->numCols; j++) {

			if (gameBoard->tiles[i][j].mine) {
				gameBoard->tiles[i][j].status = '*';
			}
			else{
				gameBoard->tiles[i][j].status = 'R';
			}

		}
	}

}


void cleanUp(Board* gameBoard) {

	int i;

	for (i=0; i < gameBoard->numRows; i++) {
		free(gameBoard->tiles[i]);
	}

	free(gameBoard->tiles);

}










