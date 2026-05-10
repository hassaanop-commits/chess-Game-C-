Chess Game in C++
OOP Lab Semester Project — FAST NUCES Faisalabad
A console-based two-player Chess Game built in C++ using Object Oriented Programming concepts.

How to Compile and Run
Make sure you have g++ installed, then run:
g++ -o chess main.cpp Piece.cpp Pawn.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp Board.cpp
./chess
On Windows:
.\chess.exe

How to Play

Enter moves in format: e2 e4 (from square then to square)
Columns are a-h, rows are 1-8
White always goes first
Type exit to quit anytime
Input is not case sensitive — E2 E4 works too


Features

Full 8x8 chessboard with piece legend
All 6 pieces with correct movement rules
Turn-based two player gameplay
Invalid move detection with error messages
Move counter (only updates on valid moves)
Pawn promotion — choose Queen, Rook, Bishop or Knight
En passant capture
King capture detection and winner announcement


File Structure
FileDescriptionmain.cppGame loop and input handlingPiece.h / .cppBase class for all piecesPawn.h / .cppPawn movement rulesRook.h / .cppRook movement rulesKnight.h / .cppKnight movement rulesBishop.h / .cppBishop movement rulesQueen.h / .cppQueen movement rulesKing.h / .cppKing movement rulesBoard.h / .cppBoard management, move handling

OOP Concepts Used

Encapsulation — data members are private/protected inside each class
Inheritance — all piece classes inherit from base Piece class
Polymorphism — canMove() is a virtual function overridden by each piece
Composition — Board class contains a 2D vector of Piece objects
