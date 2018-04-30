#include "Board.h"

Board::Board (Pieces *pPieces, int pScreenHeight)
{
	mScreenHeight = pScreenHeight;
	mPieces = pPieces; // pointer to the pieces class
	InitBoard();
}

void Board::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++) mBoard[i][j] = POS_FREE;
}

void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)
{
	for (int i = pX, i2 = 0; i < pX + PIECE_BLOCKS; i++, i2++)
	{
		for (int j = pY, j2 = 0; j < pY + PIECE_BLOCKS; j++, j2++)
		{	
			if (!IsEmptyPart(pPiece, pRotation, j2, i2)) mBoard[i][j] = POS_FILLED;
		}
	}
}

bool Board::IsGameOver()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (IsPosFilled(i, 0)) return true;
	}
	return false;
}

void Board::DeleteLine (int pY)
{
	for (int j = pY; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
			mBoard[i][j] = mBoard[i][j-1];
	}
}

void Board::DeletePossibleLines ()
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (IsPosFree(i, j)) break;
			i++;
		}
		if (i == BOARD_WIDTH) DeleteLine (j);
	}
}

int Board::GetXPosInPixels (int pPos)
{
	return  BOARD_POSITION - BLOCK_SIZE * BOARD_WIDTH / 2 + pPos * BLOCK_SIZE;
}

int Board::GetYPosInPixels (int pPos)
{
	return mScreenHeight - BLOCK_SIZE * BOARD_HEIGHT + pPos * BLOCK_SIZE;
}

bool Board::IsPossibleMove(int pX, int pY, int pPiece, int pRotation)
{
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			if (IsOutOfBounds(i1, j1) && !IsEmptyPart(pPiece, pRotation, j2, i2) ||
				IsCollision(pPiece, pRotation, j2, i2, i1, j1)) return false;
		}
	return true;
}

bool Board::IsCollision(int pPiece, int pRotation, int j2, int i2, int i1, int j1)
{
	return j1 >= 0 && !IsPosFree(i1, j1) && !IsEmptyPart(pPiece, pRotation, j2, i2);
}

bool Board::IsPosFilled(int pX, int pY)
{
	return mBoard[pX][pY] == POS_FILLED;
}

bool Board::IsPosFree(int pX, int pY)
{
	return mBoard[pX][pY] == POS_FREE;
}

bool Board::IsEmptyPart(int pPiece, int pRotation, int pX, int pY)
{
	return mPieces->IsEmptyPart(pPiece, pRotation, pX, pY);
}

bool Board::IsOutOfBounds(int pX, int pY)
{
	return (pX < 0 || pX > BOARD_WIDTH - 1 || pY > BOARD_HEIGHT - 1);
}
