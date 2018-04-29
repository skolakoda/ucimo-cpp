#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

const int BOARD_LINE_WIDTH = 6;			// Width of each of the two lines that delimit the board
const int BLOCK_SIZE = 16;				// Width and Height of each block of a piece
const int BOARD_POSITION = 320;			// Center position of the board from the left of the screen
const int BOARD_WIDTH = 10;				// Board width in blocks 
const int BOARD_HEIGHT = 20;			// Board height in blocks
const int MIN_VERTICAL_MARGIN = 20;		// Minimum vertical margin for the board limit 		
const int MIN_HORIZONTAL_MARGIN = 20;	// Minimum horizontal margin for the board limit
const int PIECE_BLOCKS = 5;				// Number of horizontal and vertical blocks of a matrix piece


class Board
{
public:
	Board						(Pieces *pPieces, int pScreenHeight);
	int GetXPosInPixels			(int pPos);
	int GetYPosInPixels			(int pPos);
	bool IsFreeBlock			(int pX, int pY);
	bool IsPossibleMovement		(int pX, int pY, int pPiece, int pRotation);
	void StorePiece				(int pX, int pY, int pPiece, int pRotation);
	void DeletePossibleLines	();
	bool IsGameOver				();

private:
	enum { POS_FREE, POS_FILLED };
	int mBoard [BOARD_WIDTH][BOARD_HEIGHT];
	Pieces *mPieces;
	int mScreenHeight;
	void InitBoard();
	void DeleteLine (int pY);
};

#endif // _BOARD_
