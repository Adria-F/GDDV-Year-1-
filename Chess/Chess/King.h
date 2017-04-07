#ifndef __KING_H__
#define __KING_H__

#include "Piece.h"
#include <iostream>

class King : public Piece
{
public:

	King(bool white) : Piece(white)
	{
	}

	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		result = ((abs(row - newRow) == 1 || abs(row - newRow) == 0) && (abs(column - newColumn) == 1 || abs(column - newColumn) == 0));

		return result;
	}
};

#endif // !__KING_H__