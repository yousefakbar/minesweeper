#ifndef MOVE_H
	#define MOVE_H
	
	void getMove(Board gameBoard, int* userRow, int* userCol, int* userAction);
	void getPosition(Board gameBoard, int* userRow, int* userCol);
	bool validPosition(Board gameBoard, int* userRow, int* userCol);
	bool checkPosition(Board gameBoard, int* userRow, int* userCol);
	bool checkTile(Board gameBoard, int* userRow, int* userCol);
	void getAction(Board gameBoard, int userRow, int userCol, int* userAction);
	bool validAction(Board gameBoard, int userRow, int userCol, int userAction);
	void playMove(Board* gameBoard, int userRow, int userCol, int userAction);
	void revealTile(Board* gameBoard, int row, int col);
	bool checkBoundary(Board* gameBoard, int i, int j);

#endif