#include "Piece.h"

Piece::Piece(char s, char l) {
    side = s;
    logo = l;
}

char Piece::getSide() {
    return side;
}

char Piece::getLogo() {
    return logo;
}
