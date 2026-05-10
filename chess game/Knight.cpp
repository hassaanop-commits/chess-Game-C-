#include "Knight.h"
#include <cmath>

Knight::Knight(char s) : Piece(s, 'N') {}

bool Knight::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    int rowJump = abs(r2 - r1);
    int colJump = abs(c2 - c1);

    // knight jumps in L shape - no path blocking applies
    bool validShape = (rowJump == 2 && colJump == 1) || (rowJump == 1 && colJump == 2);
    if (!validShape) return false;

    if (chessBoard[r2][c2] == nullptr || chessBoard[r2][c2]->getSide() != side)
        return true;

    return false;
}
