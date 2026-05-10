#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(char s) : Piece(s, 'Q') {}

bool Queen::canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) {
    // queen is basically rook + bishop together
    Rook r(side);
    Bishop b(side);
    return r.canMove(r1, c1, r2, c2, chessBoard) || b.canMove(r1, c1, r2, c2, chessBoard);
}
