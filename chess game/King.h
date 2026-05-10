#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(char s);
    bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard);
};

#endif
