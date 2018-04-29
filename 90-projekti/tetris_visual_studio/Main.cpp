// http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

#include "Game.h"
#ifndef LINUX
#include <windows.h>
#endif

#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)	// Linux users should quit this line
#else
int main()
#endif
{
	// Class for drawing staff, it uses SDL for the rendering
	IO mIO;
	int mScreenHeight = mIO.GetScreenHeight();
	Pieces mPieces;
	Board mBoard (&mPieces, mScreenHeight);
	Game mGame (&mBoard, &mPieces, &mIO, mScreenHeight);
	// Get the actual clock milliseconds (SDL)
	unsigned long mTime1 = SDL_GetTicks();

	// ----- Main Loop -----
	while (!mIO.IsKeyDown (SDLK_ESCAPE))
	{
		// ----- Draw -----
		mIO.ClearScreen (); 		// Clear screen
		mGame.DrawScene ();			// Draw staff
		mIO.UpdateScreen ();		// Put the graphic context in the screen

		// ----- Input -----
		switch (mIO.Pollkey())
		{
			case (SDLK_RIGHT): 
			{
				if (mBoard.IsPossibleMovement (mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
				break;
			}

			case (SDLK_LEFT): 
			{
				if (mBoard.IsPossibleMovement (mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;	
				break;
			}

			case (SDLK_DOWN):
			{
				if (mBoard.IsPossibleMovement (mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					mGame.mPosY++;	
				break;
			}

			case (SDLK_SPACE):
			{
				if (mBoard.IsPossibleMovement (mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
					mGame.mRotation = (mGame.mRotation + 1) % 4;
				break;
			}
		}

		// ----- Vertical movement -----
		if (SDL_GetTicks() - mTime1 > WAIT_TIME)
		{
			if (mBoard.IsPossibleMovement (mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
			{
				mGame.mPosY++;
			}
			else
			{
				mBoard.StorePiece (mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
				mBoard.DeletePossibleLines ();
				if (mBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}
				mGame.CreateNewPiece();
			}
			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}
