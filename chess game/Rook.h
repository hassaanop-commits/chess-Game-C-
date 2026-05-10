#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(char s);
    bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard);
};

#endif
