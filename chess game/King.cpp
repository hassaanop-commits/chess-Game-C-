#include "King.h"
#include <cmath>

King::King(char s) : Piece(s, 'K') {}

bool King::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    // king moves just 1 square in any direction
    if (abs(r2 - r1) > 1 || abs(c2 - c1) > 1)
        return false;

    if (chessBoard[r2][c2] == nullptr || chessBoard[r2][c2]->getSide() != side)
        return true;

    return false;
}
