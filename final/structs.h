#ifndef STRUCTS_H
	#define STRUCTS_H
	#include <stdbool.h>
	
	typedef struct Tile_struct {

		bool mine;
		int minesAround;
		char status;

	} Tile;


	typedef struct Board_struct {
	
		int numRows;
		int numCols;
		int numMines;
		int seedVal;

		Tile** tiles;

	} Board;

#endif