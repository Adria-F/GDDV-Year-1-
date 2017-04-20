#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Piece.h"
#include <iostream>

class Knight : public Piece
{
public:

	Knight(bool white) : Piece(white)
	{
	}
	
	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		result = (abs(row - newRow) == 2 && abs(column - newColumn) == 1);
		if (result == false)
		{
			result = (abs(column - newColumn) == 2 && abs(row - newRow) == 1);
		}

		return result;
	}
};

#endif // !__KNIGHT_H__