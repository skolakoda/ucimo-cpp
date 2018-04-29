#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

const int WAIT_TIME = 700; // before going 1 block down


class Game
{
public:
	Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

	void DrawScene ();
	void CreateNewPiece ();

	int mPosX, mPosY;
	int mPiece, mRotation;

private:
	int mScreenHeight;
	int mNextPosX, mNextPosY;
	int mNextPiece, mNextRotation;

	Board *mBoard;
	Pieces *mPieces;
	IO *mIO;

	int GetRand (int pA, int pB);
	void InitGame();
	void DrawPiece (int pX, int pY, int pPiece, int pRotation);
	void DrawBoard ();
};

#endif // _GAME_
