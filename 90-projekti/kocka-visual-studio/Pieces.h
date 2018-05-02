#ifndef _PIECES_
#define _PIECES_


class Pieces
{
public:
	int GetBlockType		(int pPiece, int pRotation, int pX, int pY);
	int GetXInitialPosition (int pPiece, int pRotation);
	int GetYInitialPosition (int pPiece, int pRotation);
	bool IsEmptyPart(int pPiece, int pRotation, int j2, int i2);
	bool IsPivot(int pPiece, int pRotation, int pX, int pY);
};

#endif // _PIECES_
