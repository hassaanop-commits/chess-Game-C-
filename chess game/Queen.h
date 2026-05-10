#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(char s);
    bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard);
};

#endif
