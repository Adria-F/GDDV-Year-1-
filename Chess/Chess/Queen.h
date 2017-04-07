#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "Piece.h"
#include <iostream>

class Queen : public Piece
{
public:

	Queen(bool white) : Piece(white)
	{
	}

	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		result = ((row == newRow || column == newColumn) || (newColumn == (column + abs(row - newRow))));

		return result;
	}
};

#endif // !__QUEEN_H__