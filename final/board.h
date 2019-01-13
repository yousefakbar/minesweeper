#ifndef BOARD_H
	#define BOARD_H
	#include <stdbool.h>

	void validateArgs(int argC);
	void setupTiles(Board* gameBoard);
	void setMines(Board* gameBoard);
	int countMines(Board* gameBoard, int i, int j);
	bool withinBoundary(Board* gameBoard, int i, int j);
	//void determineVicinity(Board* gameBoard);
	void init_board(int argC, char** argV, Board* gameBoard);
	void displayBoard(Board gameBoard);
	void minesLeft(Board gameBoard);
	void revealAll(Board* gameBoard);
	void cleanUp(Board* gameBoard);

#endif