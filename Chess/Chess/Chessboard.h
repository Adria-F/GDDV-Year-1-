#ifndef __CHESSBOARD_H__
#define __CEHSSBOARD_H__

#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
using namespace std;

class Chessboard
{
private:

	Piece* piece[32];

public:

	Chessboard()
	{
		int i = 0;
		bool color = true;
		for (int k = 0; k < 2; k++)
		{
			piece[i++] = new Rook(color);
			piece[i++] = new Knight(color);
			piece[i++] = new Bishop(color);
			piece[i++] = new Queen(color);
			piece[i++] = new King(color);
			piece[i++] = new Bishop(color);
			piece[i++] = new Knight(color);
			piece[i++] = new Rook(color);
			for (int j = 0; j < 8; j++)
			{
				piece[i++] = new Pawn(color);
			}
			color = false;
		}
	}

	~Chessboard()
	{
		for (int i = 0; i < 32; i++)
		{
			delete[] piece[i];
		}
	}

	void start()
	{
		int i = 0;
		for (int k = 1; k < 3; k++)
		{
			for (int j = 0; j < 8; j++)
			{
				piece[i++]->setPosition(k, 'a' + j);
			}
		}
		for (int k = 8; k > 6; k--)
		{
			for (int j = 0; j < 8; j++)
			{
				piece[i++]->setPosition(k, 'a' + j);
			}
		}
	}

	void printBoard() const
	{
		char board[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = '-';
			}
		}
		int a = 0;
		int mayus = 32;
		for (int k = 0; k < 2; k++)
		{
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'R' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'N' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'B' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'Q' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'K' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'B' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'N' + mayus;
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'R' + mayus;
			a++;
			for (int j = 0; j < 8; j++)
			{
				board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = 'P' + mayus;
				a++;
			}
			a--;
			mayus = 0;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}

	}

};

#endif // !__CHESSBOARD_H__
