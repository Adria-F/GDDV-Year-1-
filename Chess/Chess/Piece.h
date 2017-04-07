#ifndef __PIECE_H__
#define __PIECE_H__

class Piece
{
protected:

	int row;
	char column;
	bool isWhite;

public:

	Piece(bool white, int prow = 0, char pcolumn = 'a'): isWhite(white), row(prow), column(pcolumn)
	{
	}

	int getRow() const
	{
		return row;
	}

	char getColumn() const
	{
		return column;
	}

	bool getTeam()
	{
		return isWhite;
	}

	void setPosition(int prow, char pcolumn)
	{
		row = prow;
		column = pcolumn;
	}

	virtual bool checkMovement(int newRow, char newColumn) = 0;
};

#endif // !__PIECE_H__
