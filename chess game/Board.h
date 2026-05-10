#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"
using namespace std;

// Board class uses composition - it holds all the pieces
class Board {
private:
    vector<vector<Piece*>> chessBoard;
    bool wKingAlive;
    bool bKingAlive;
    int totalMoves;  // move counter
    int enPassantCol; // column where en passant is possible (-1 if none)
    int enPassantRow; // row of the pawn that can be captured via en passant

public:
    Board();
    void placePieces();
    void printBoard();
    bool doMove(int r1, int c1, int r2, int c2, char player);
    bool gameEnded();
    char whoWon();
    ~Board();
};

#endif
