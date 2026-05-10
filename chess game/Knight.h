#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(char s);
    bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard);
};

#endif
