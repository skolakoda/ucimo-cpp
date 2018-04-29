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
		for (int j = 0; j < BOARD_HEIGHT; j++)
			mBoard[i][j] = POS_FREE;
}


void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)
{
	for (int i = pX, i2 = 0; i < pX + PIECE_BLOCKS; i++, i2++)
	{
		for (int j = pY, j2 = 0; j < pY + PIECE_BLOCKS; j++, j2++)
		{	
			// Store only the blocks of the piece that are not holes
			if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)		
				mBoard[i][j] = POS_FILLED;	
		}
	}
}


bool Board::IsGameOver()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return true;
	}
	return false;
}


void Board::DeleteLine (int pY)
{
	// Moves all the upper lines one row down
	for (int j = pY; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			mBoard[i][j] = mBoard[i][j-1];
		}
	}	
}


void Board::DeletePossibleLines ()
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}
		if (i == BOARD_WIDTH) DeleteLine (j);
	}
}


bool Board::IsFreeBlock (int pX, int pY)
{
	return (mBoard [pX][pY] == POS_FREE);
}


int Board::GetXPosInPixels (int pPos)
{
	return  (BOARD_POSITION - BLOCK_SIZE * (BOARD_WIDTH / 2) + pPos * BLOCK_SIZE);
}


int Board::GetYPosInPixels (int pPos)
{
	return (mScreenHeight - BLOCK_SIZE * BOARD_HEIGHT + pPos * BLOCK_SIZE);
}


bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
	for (int i = pX, i2 = 0; i < pX + PIECE_BLOCKS; i++, i2++)
	{
		for (int j = pY, j2 = 0; j < pY + PIECE_BLOCKS; j++, j2++)
		{	
			if (i < 0 || i > BOARD_WIDTH - 1 || j > BOARD_HEIGHT - 1)
			{
				if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
					return 0;		
			}
			if (j >= 0)	
			{
				if ((mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0) &&
					(!IsFreeBlock (i, j))	)
					return false;
			}
		}
	}
	return true;
}
