#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(char s);
    bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard);
};

#endif
