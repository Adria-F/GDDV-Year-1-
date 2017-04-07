#ifndef __ROOK_H__
#define __ROOK_H__

#include "Piece.h"

class Rook : public Piece
{
public:

	Rook(bool white) : Piece(white)
	{
	}

	bool checkMovement(int newRow, char newColumn)
	{
		bool result = false;

		result = (row == newRow || column == newColumn);

		return result;
	}
};

#endif // !__ROOK_H__