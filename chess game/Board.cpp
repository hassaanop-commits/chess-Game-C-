#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

Board::Board() {
    chessBoard.resize(8, vector<Piece*>(8, nullptr));
    wKingAlive = true;
    bKingAlive = true;
    totalMoves = 0;
    enPassantCol = -1;
    enPassantRow = -1;
    placePieces();
}

void Board::placePieces() {
    // black side - rows 0 and 1
    chessBoard[0][0] = new Rook('B');
    chessBoard[0][1] = new Knight('B');
    chessBoard[0][2] = new Bishop('B');
    chessBoard[0][3] = new Queen('B');
    chessBoard[0][4] = new King('B');
    chessBoard[0][5] = new Bishop('B');
    chessBoard[0][6] = new Knight('B');
    chessBoard[0][7] = new Rook('B');
    for (int i = 0; i < 8; i++)
        chessBoard[1][i] = new Pawn('B');

    // white side - rows 6 and 7
    for (int i = 0; i < 8; i++)
        chessBoard[6][i] = new Pawn('W');
    chessBoard[7][0] = new Rook('W');
    chessBoard[7][1] = new Knight('W');
    chessBoard[7][2] = new Bishop('W');
    chessBoard[7][3] = new Queen('W');
    chessBoard[7][4] = new King('W');
    chessBoard[7][5] = new Bishop('W');
    chessBoard[7][6] = new Knight('W');
    chessBoard[7][7] = new Rook('W');
}

void Board::printBoard() {
    totalMoves++;
    cout << "\n--- Move " << totalMoves << " ---\n";

    // Piece Names
    cout << "+-----------------------------------------+\n";
    cout << "|              PIECE  NAMES              |\n";
    cout << "+-----------------------------------------+\n";
    cout << "|  K = King    Q = Queen   R = Rook       |\n";
    cout << "|  B = Bishop  N = Knight  P = Pawn       |\n";
    cout << "|  UPPERCASE = White   lowercase = Black  |\n";
    cout << "+-----------------------------------------+\n\n";

    cout << "     a    b    c    d    e    f    g    h\n";
    cout << "   +----+----+----+----+----+----+----+----+\n";
    for (int row = 0; row < 8; row++) {
        cout << " " << (8 - row) << " |";
        for (int col = 0; col < 8; col++) {
            if (chessBoard[row][col] == nullptr) {
                cout << "    |";
            } else {
                char s = chessBoard[row][col]->getSide();
                char l = chessBoard[row][col]->getLogo();
                // black pieces shown in lowercase
                if (s == 'B') l = tolower(l);
                cout << " " << s << l << " |";
            }
        }
        cout << " " << (8 - row) << "\n";
        cout << "   +----+----+----+----+----+----+----+----+\n";
    }
    cout << "     a    b    c    d    e    f    g    h\n";
    cout << " W=White  B=Black  uppercase=White  lowercase=Black\n\n";
}

bool Board::doMove(int r1, int c1, int r2, int c2, char player) {
    // bounds check
    if (r1 < 0 || r1 > 7 || c1 < 0 || c1 > 7 || r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7) {
        cout << ">> That square doesn't exist on the board!\n";
        return false;
    }

    Piece* selected = chessBoard[r1][c1];

    if (selected == nullptr) {
        cout << ">> No piece on that square!\n";
        return false;
    }

    if (selected->getSide() != player) {
        cout << ">> Hey that piece belongs to your opponent!\n";
        return false;
    }

    if (!selected->canMove(r1, c1, r2, c2, chessBoard)) {
        // check en passant before rejecting the move
        bool isEnPassant = false;
        if (selected->getLogo() == 'P' && enPassantCol == c2 && enPassantRow == r1) {
            // pawn is moving diagonally to the en passant square
            int moveDir = (player == 'W') ? -1 : 1;
            if (r2 == r1 + moveDir && abs(c2 - c1) == 1) {
                isEnPassant = true;
            }
        }

        if (!isEnPassant) {
            cout << ">> That move is not allowed for this piece!\n";
            return false;
        }

        // en passant capture
        cout << ">> En passant capture!\n";
        delete chessBoard[enPassantRow][enPassantCol]; 
        chessBoard[enPassantRow][enPassantCol] = nullptr;
        chessBoard[r2][c2] = selected;
        chessBoard[r1][c1] = nullptr;
        enPassantCol = -1;
        enPassantRow = -1;
        return true;
    }

    
    enPassantCol = -1;
    enPassantRow = -1;

    
    if (selected->getLogo() == 'P' && abs(r2 - r1) == 2) {
        enPassantCol = c1;
        enPassantRow = r2; 
    }

    
    if (chessBoard[r2][c2] != nullptr) {
        char capturedLogo = chessBoard[r2][c2]->getLogo();
        char capturedSide = chessBoard[r2][c2]->getSide();

        if (capturedLogo == 'K') {
            if (capturedSide == 'W') wKingAlive = false;
            else bKingAlive = false;
        }

        cout << ">> Piece captured!\n";
        delete chessBoard[r2][c2];
    }

    //  piece moving logic
    chessBoard[r2][c2] = selected;
    chessBoard[r1][c1] = nullptr;

    // pawn promotion - white reaches row 0, black reaches row 7
    if (chessBoard[r2][c2]->getLogo() == 'P') {
        if ((player == 'W' && r2 == 0) || (player == 'B' && r2 == 7)) {
            char choice;
            cout << "\n>> Pawn reached the other side! Choose promotion:\n";
            cout << "   Q = Queen   R = Rook   B = Bishop   N = Knight\n";
            cout << ">> Enter choice: ";

            // keep asking until valid input
            while (true) {
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Q' || choice == 'R' || choice == 'B' || choice == 'N')
                    break;
                cout << ">> Invalid! Enter Q, R, B or N: ";
            }

            // delete the pawn and replace with chosen piece
            delete chessBoard[r2][c2];
            if (choice == 'Q') chessBoard[r2][c2] = new Queen(player);
            else if (choice == 'R') chessBoard[r2][c2] = new Rook(player);
            else if (choice == 'B') chessBoard[r2][c2] = new Bishop(player);
            else if (choice == 'N') chessBoard[r2][c2] = new Knight(player);

            cout << ">> Pawn promoted to " << choice << "!\n";
        }
    }

    return true;
}

bool Board::gameEnded() {
    return !wKingAlive || !bKingAlive;
}

char Board::whoWon() {
    if (!wKingAlive) return 'B';
    if (!bKingAlive) return 'W';
    return '?';
}

Board::~Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (chessBoard[i][j] != nullptr)
                delete chessBoard[i][j];
}
