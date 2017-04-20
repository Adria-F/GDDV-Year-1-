#ifndef __PAWN_H__
#define __PAWN_H__

#include "Piece.h"

class Pawn : public Piece
{
public:

	Pawn(bool white): Piece(white)
	{
	}
	
	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		if (isWhite)
		{
			result = (newRow == (row - 1)) && column == newColumn;
		}
		else
		{
			result = (newRow == (row + 1)) && column == newColumn;
		}

		return result;
	}
};

#endif // !__PAWN_H__
