#include "Pawn.h"
#include <cmath>

Pawn::Pawn(char s) : Piece(s, 'P') {}

bool Pawn::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    // white moves up (decreasing row), black moves down
    int moveDir = (side == 'W') ? -1 : 1;
    int homeRow = (side == 'W') ? 6 : 1;

    // simple one step forward
    if (c1 == c2 && r2 == r1 + moveDir) {
        if (chessBoard[r2][c2] == nullptr)
            return true;
    }

    // first move allowed 2 steps
    if (c1 == c2 && r1 == homeRow && r2 == r1 + 2 * moveDir) {
        if (chessBoard[r2][c2] == nullptr && chessBoard[r1 + moveDir][c2] == nullptr)
            return true;
    }

    // capture diagonally
    if (abs(c2 - c1) == 1 && r2 == r1 + moveDir) {
        if (chessBoard[r2][c2] != nullptr && chessBoard[r2][c2]->getSide() != side)
            return true;
    }

    return false;
}
