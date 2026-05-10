#include "Rook.h"

Rook::Rook(char s) : Piece(s, 'R') {}

bool Rook::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    // must stay in same row or same column
    if (r1 != r2 && c1 != c2)
        return false;

    // check nothing is blocking the path horizontally
    if (r1 == r2) {
        int dir = (c2 > c1) ? 1 : -1;
        for (int col = c1 + dir; col != c2; col += dir)
            if (chessBoard[r1][col] != nullptr) return false;
    }

    // check nothing is blocking the path vertically
    if (c1 == c2) {
        int dir = (r2 > r1) ? 1 : -1;
        for (int row = r1 + dir; row != r2; row += dir)
            if (chessBoard[row][c1] != nullptr) return false;
    }

    if (chessBoard[r2][c2] == nullptr || chessBoard[r2][c2]->getSide() != side)
        return true;

    return false;
}
