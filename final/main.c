#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "board.h"
#include "move.h"
#include "win.h"


void play_minesweeper(int argC, char** argV) {

	//declare variables
	Board gameBoard;					//struct array game board containing info
	int userRow, userCol, userAction;	//info about user's desired move
	int result;							//result of game determined when game is over

	//initialize game board. set up tiles. generate mines
	init_board(argC, argV, &gameBoard);

	//play game
	do {

		//info print to user
		minesLeft(gameBoard);
		displayBoard(gameBoard);
		
		//get next move position and action from user then play it
		getMove(gameBoard, &userRow, &userCol, &userAction);
		playMove(&gameBoard, userRow, userCol, userAction);

	} while (!gameOver(gameBoard, &result));

	//final touches
	revealAll(&gameBoard);			//reveal all tiles when game is over
	displayBoard(gameBoard);		//display one last time
	endResult(gameBoard, result);	//print result
	cleanUp(&gameBoard);			//clean allocated memory

}


int main(int argC, char** argV) {
	//main function

	play_minesweeper(argC, argV);
	return 0;
}