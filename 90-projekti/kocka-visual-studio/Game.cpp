#ifndef LINUX
#include <windows.h>
#endif
#include "Game.h"

Game::Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight) 
{
	mScreenHeight = pScreenHeight;
	mBoard = pBoard;
	mPieces = pPieces;
	mIO = pIO;
	InitGame ();
}

int Game::GetRand (int pA, int pB)
{
	return rand () % (pB - pA + 1) + pA;
}

void Game::InitGame()
{
	srand ((unsigned int) time(NULL));
	InitFirstPiece(GetRand(0, 6), GetRand(0, 3));
	InitNextPiece();
}

void Game::InitFirstPiece(int pPiece, int pRotation)
{
	mPiece = pPiece;
	mRotation = pRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);
}

void Game::InitNextPiece()
{
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
	mNextPosX = BOARD_WIDTH + 5;
	mNextPosY = 5;
}

void Game::CreateNewPiece()
{
	InitFirstPiece(mNextPiece, mNextRotation);
	mNextPiece = GetRand (0, 6);
	mNextRotation = GetRand (0, 3);
}

void Game::DrawPiece (int pX, int pY, int pPiece, int pRotation)
{
	int mPixelsX = mBoard->GetXPosInPixels (pX);
	int mPixelsY = mBoard->GetYPosInPixels (pY);

	for (int i = 0; i < PIECE_BLOCKS; i++)
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			if (!mPieces->IsEmptyPart(pPiece, pRotation, j, i)) {
				color mColor = mPieces->IsPivot(pPiece, pRotation, j, i) ? BLUE : GREEN;
				mIO->DrawRectangle(
					mPixelsX + i * BLOCK_SIZE,
					mPixelsY + j * BLOCK_SIZE,
					mPixelsX + i * BLOCK_SIZE + BLOCK_SIZE - 1,
					mPixelsY + j * BLOCK_SIZE + BLOCK_SIZE - 1,
					mColor
				);
			}
		}
}

void Game::DrawBoard ()
{
	int mX1 = BOARD_POSITION - BLOCK_SIZE * BOARD_WIDTH / 2 - 1;
	int mX2 = BOARD_POSITION + BLOCK_SIZE * BOARD_WIDTH / 2;
	int mY = mScreenHeight - BLOCK_SIZE * BOARD_HEIGHT;

	mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);
	mX1++;

	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{	
			if (!mBoard->IsPosFree(i, j)) mIO->DrawRectangle(
				mX1 + i * BLOCK_SIZE, 
				mY + j * BLOCK_SIZE, 
				mX1 + i * BLOCK_SIZE + BLOCK_SIZE - 1, 
				mY + j * BLOCK_SIZE + BLOCK_SIZE - 1, 
				RED
			);
		}
}

void Game::DrawScene ()
{
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPiece, mRotation);
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
