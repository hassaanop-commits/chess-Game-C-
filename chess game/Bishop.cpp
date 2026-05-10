#include "Bishop.h"
#include <cmath>

Bishop::Bishop(char s) : Piece(s, 'B') {}

bool Bishop::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    // diagonal means row diff == col diff
    if (abs(r2 - r1) != abs(c2 - c1))
        return false;

    int rDir = (r2 > r1) ? 1 : -1;
    int cDir = (c2 > c1) ? 1 : -1;

    // check diagonal path is clear
    int r = r1 + rDir, c = c1 + cDir;
    while (r != r2) {
        if (chessBoard[r][c] != nullptr) return false;
        r += rDir;
        c += cDir;
    }

    if (chessBoard[r2][c2] == nullptr || chessBoard[r2][c2]->getSide() != side)
        return true;

    return false;
}
