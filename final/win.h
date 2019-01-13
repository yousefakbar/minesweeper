#ifndef WIN_H
	#define WIN_H
	
	bool gameOver(Board gameBoard, int* result);
	bool lose(Board gameBoard);
	bool win(Board gameBoard);
	bool allRevealed(Board gameBoard);
	void endResult(Board gameBoard, int result);

#endif