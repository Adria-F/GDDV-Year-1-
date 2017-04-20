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
			piece[i++] = new Rook(color); //Torre
			piece[i++] = new Knight(color); //Cavall
			piece[i++] = new Bishop(color); //Alfil
			piece[i++] = new Queen(color); //Reina
			piece[i++] = new King(color);  //Rei
			piece[i++] = new Bishop(color); //Alfil
			piece[i++] = new Knight(color); //Cavall
			piece[i++] = new Rook(color); //Torre
			for (int j = 0; j < 8; j++)
			{
				piece[i++] = new Pawn(color); //Peons
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
		for (int k = 8; k > 6; k--)
		{
			for (int j = 0; j < 8; j++)
			{
				piece[i++]->setPosition(k, 'a' + j);
			}
		}
		for (int k = 1; k < 3; k++)
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
		for (int k = 0; k < 2; k++)
		{
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'R' : 'r';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'N' : 'n';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'B' : 'b';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'Q' : 'q';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'K' : 'k';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'B' : 'b';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'N' : 'n';
			a++;
			board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'R' : 'r';
			a++;
			for (int j = 0; j < 8; j++)
			{
				board[piece[a]->getRow() - 1][piece[a]->getColumn() - 97] = (piece[a]->getTeam()) ? 'P' : 'p';
				a++;
			}
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

	bool movePiece(int currentRow, char currentColumn, bool white, int newRow, char newColumn)
	{
		bool result = false;

		for (int i = 0; i < 32; i++)
		{
			if (piece[i]->getRow() == currentRow && piece[i]->getColumn() == currentColumn && piece[i]->getTeam() == white && piece[i]->checkMovement(newRow, newColumn))
			{
				piece[i]->setPosition(newRow, newColumn);
				result = true;
				break;
			}
		}

		return result;
	}
};

#endif // !__CHESSBOARD_H__
