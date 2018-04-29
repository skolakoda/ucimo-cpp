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

/* 
Parameters:
>> pX:		Horizontal position in blocks
>> pY:		Vertical position in blocks
>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
*/
void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)
{
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{	
			// Store only the blocks of the piece that are not holes
			if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)		
				mBoard[i1][j1] = POS_FILLED;	
		}
	}
}


bool Board::IsGameOver()
{
	//If the first line has blocks, then, game over
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return true;
	}
	return false;
}


/* 			
Parameters:
>> pY:		Vertical position in blocks of the line to delete
*/
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
	// Checks collision with pieces already stored in the board or the board limits
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{	
			// Check if the piece is outside the limits of the board
			if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
			{
				if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
					return 0;		
			}

			// Check if the piece have collisioned with a block already stored in the map
			if (j1 >= 0)	
			{
				if ((mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0) &&
					(!IsFreeBlock (i1, j1))	)
					return false;
			}
		}
	}
	return true;
}
