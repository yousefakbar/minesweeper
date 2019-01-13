#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "win.h"


bool gameOver(Board gameBoard, int* result) {

	bool shutDown = false;

	if (lose(gameBoard)) {
		shutDown = true;
		*result = 0;
	}
	else if (win(gameBoard)) {
		shutDown = true;
		*result = 1;
	}

	return shutDown;

}


bool lose(Board gameBoard) {

	int i, j;

	for (i=0; i < gameBoard.numRows; i++) {
		for (j=0; j < gameBoard.numCols; j++) {

			if (gameBoard.tiles[i][j].status == '*') {
				return true;
			}

		}
	}

	return false;
}


bool win(Board gameBoard) {

	int i, j;
	bool userWins = true;;

	if (allRevealed(gameBoard)) {

		for (i=0; i < gameBoard.numRows; i++) {
			for (j=0; j < gameBoard.numCols; j++) {

				if ((gameBoard.tiles[i][j].status == '!' && gameBoard.tiles[i][j].mine) || gameBoard.tiles[i][j].status == 'R') {
					continue;
				}
				else {
					userWins = false;
				}

			}
		}
	}
	else {
		userWins = false;
	}

	return userWins;
}


bool allRevealed(Board gameBoard) {

	int i, j;

	for (i=0; i < gameBoard.numRows; i++) {
		for (j=0; j < gameBoard.numCols; ++j) {

			if (gameBoard.tiles[i][j].status == '#') {
				return false;
			}

		}
	}

	return true;
}


void endResult(Board gameBoard, int result) {

	if (result == 0) {
		printf("You Lost :(\n");
	}
	else {
		printf("You Won!!\n");
	}

}