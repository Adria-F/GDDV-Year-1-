#include "Chessboard.h"

int main()
{
	Chessboard Board;

	Board.start();
	Board.movePiece(2, 'g', false, 3, 'g'); //Pawn
	Board.movePiece(8, 'b', true, 6, 'c'); //Knight
	Board.movePiece(6, 'c', true, 5, 'a'); //Knight
	Board.movePiece(1, 'd', false, 3, 'b'); //Queen
	Board.movePiece(3, 'b', false, 3, 'd'); //Queen
	Board.movePiece(8, 'f', true, 4, 'b'); //Bishop
	Board.printBoard();

	system("pause");
	return 0;
}