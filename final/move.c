#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs.h"
#include "board.h"
#include "move.h"


void getMove(Board gameBoard, int* userRow, int* userCol, int* userAction) {

	do {

		getPosition(gameBoard, userRow, userCol);
		if (!validPosition(gameBoard, userRow, userCol)) {
			if (checkPosition(gameBoard, userRow, userCol) && !checkTile(gameBoard, userRow, userCol)) {
				printf("This tile is already revealed.\n");
			}
			continue;
		}

		getAction(gameBoard, *userRow, *userCol, userAction);
		if (!validAction(gameBoard, *userRow, *userCol, *userAction)) {
			continue;
		}

	} while (!validPosition(gameBoard, userRow, userCol) || !validAction(gameBoard, *userRow, *userCol, *userAction));

}


void getPosition(Board gameBoard, int* userRow, int* userCol) {

	
	printf("Enter row a row between 0-%d and a column between 0-%d: ", gameBoard.numRows - 1, gameBoard.numCols - 1);
	scanf(" %d %d", userRow, userCol);
	

}


bool validPosition(Board gameBoard, int* userRow, int* userCol) {
	return checkPosition(gameBoard, userRow, userCol) && checkTile(gameBoard, userRow, userCol);
}


bool checkPosition(Board gameBoard, int* userRow, int* userCol) {
	return *userRow >= 0 && *userRow < gameBoard.numRows && *userCol >= 0 && *userCol < gameBoard.numCols;
}


bool checkTile(Board gameBoard, int* userRow, int* userCol) {
	return gameBoard.tiles[*userRow][*userCol].status == '!' || gameBoard.tiles[*userRow][*userCol].status == '?' || gameBoard.tiles[*userRow][*userCol].status == '#';
}


void getAction(Board gameBoard, int userRow, int userCol, int* userAction) {

	printf("Enter Action\n");

	if (gameBoard.tiles[userRow][userCol].status == '?') {
		printf("0. UnQuestion\n");
		printf("1. Cancel\n");
	}
	else if (gameBoard.tiles[userRow][userCol].status == '!') {
		printf("0. UnMark\n");
		printf("1. Cancel\n");
	}
	else if (gameBoard.tiles[userRow][userCol].status == '#') {
		printf("0. Reveal\n");
		printf("1. Question\n");
		printf("2. Mark\n");
		printf("3. Cancel\n");
	}

	printf("Action: ");
	scanf(" %d", userAction);

}


bool validAction(Board gameBoard, int userRow, int userCol, int userAction) {

	if (gameBoard.tiles[userRow][userCol].status == '?' || gameBoard.tiles[userRow][userCol].status == '!') {
		if (userAction == 1) {
			return false;
		}
		return userAction == 0;
	}
	else if (gameBoard.tiles[userRow][userCol].status == '#') {
		if (userAction == 3) {
			return false;
		}
		return userAction >= 0 && userAction <= 2;
	}
	else {
		return false;
	}

}


void playMove(Board* gameBoard, int userRow, int userCol, int userAction) {

	if (gameBoard->tiles[userRow][userCol].status == '#') {

		if (userAction == 0) {
			revealTile(gameBoard, userRow, userCol);
		}
		else if (userAction == 1) {
			gameBoard->tiles[userRow][userCol].status = '?';
		}
		else if (userAction == 2) {
			gameBoard->tiles[userRow][userCol].status = '!';
			gameBoard->numMines--;
		}
	}
	else if (gameBoard->tiles[userRow][userCol].status == '?' || gameBoard->tiles[userRow][userCol].status == '!') {
		if (userAction == 0) {
			if (gameBoard->tiles[userRow][userCol].status == '!') {
				gameBoard->numMines++;
			}

			gameBoard->tiles[userRow][userCol].status = '#';
		}
	}

}


void revealTile(Board* gameBoard, int userRow, int userCol) {

	int i, j;

	if (gameBoard->tiles[userRow][userCol].mine) {
		gameBoard->tiles[userRow][userCol].status = '*';
	}
	else {
		gameBoard->tiles[userRow][userCol].status = 'R';

		if (gameBoard->tiles[userRow][userCol].minesAround == 0) {

			for (i = userRow-1; i <= userRow+1; i++) {
				for (j = userCol-1; j <= userCol+1; j++) {

					if (i == userRow && j == userCol) {
						continue;
					}
					else if (checkBoundary(gameBoard, i, j) && gameBoard->tiles[i][j].status == '#') {
						revealTile(gameBoard, i, j);
					}

				}
			}

		}
	}

}


bool checkBoundary(Board* gameBoard, int i, int j) {
	return i >= 0 && i < gameBoard->numRows && j >= 0 && j < gameBoard->numCols;
}







