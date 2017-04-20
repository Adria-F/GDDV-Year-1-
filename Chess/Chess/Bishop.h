#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "Piece.h"
#include <iostream>

class Bishop : public Piece
{
public:

	Bishop(bool white) : Piece(white)
	{
	}
	
	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		result = (newColumn == (column + ((isWhite) ? (newRow - row) : (row - newRow))));

		return result;
	}
};

#endif // !__BISHOP_H__r
