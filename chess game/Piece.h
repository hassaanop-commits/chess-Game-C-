#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

// base class for all chess pieces
class Piece {
protected:
    char side;  // 'W' = white, 'B' = black
    char logo;  // letter shown on board

public:
    Piece(char s, char l);
    char getSide();
    char getLogo();
   
    virtual bool canMove(int r1, int c1, int r2, int c2, vector<vector<Piece*>>& chessBoard) = 0;
    virtual ~Piece() {}
};

#endif
