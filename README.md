# ♟️ Chess Game in C++  
### OOP Lab Semester Project — FAST NUCES Faisalabad

A **console-based two-player Chess Game** built in **C++** using **Object-Oriented Programming (OOP)** concepts.  
This project implements core chess mechanics with proper movement rules, validation, and special moves.

---

## 🚀 How to Compile and Run

Make sure you have **g++** installed on your system.

### Compile:
```bash
g++ -o chess main.cpp Piece.cpp Pawn.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp Board.cpp
Run (Linux / Mac):
./chess
Run (Windows):
.\chess.exe
🎮 How to Play
Enter moves in the format:
e2 e4
First input → current position of the piece
Second input → destination position
Rules:
Columns range from a → h
Rows range from 1 → 8
White always moves first
Type exit anytime to quit the game
Input is case-insensitive
Example: E2 E4 also works
✨ Features
Full 8x8 chessboard
Piece legend for easy understanding
All 6 chess pieces implemented with correct movement logic:
Pawn
Rook
Knight
Bishop
Queen
King
Turn-based two-player gameplay
Invalid move detection with proper error messages
Move counter (updates only on valid moves)
Pawn promotion:
Queen
Rook
Bishop
Knight
En passant capture support
King capture detection
Winner announcement system
📂 File Structure
File	Description
main.cpp	Game loop and input handling
Piece.h / Piece.cpp	Base class for all pieces
Pawn.h / Pawn.cpp	Pawn movement logic
Rook.h / Rook.cpp	Rook movement logic
Knight.h / Knight.cpp	Knight movement logic
Bishop.h / Bishop.cpp	Bishop movement logic
Queen.h / Queen.cpp	Queen movement logic
King.h / King.cpp	King movement logic
Board.h / Board.cpp	Board management and move handling
🧠 OOP Concepts Used
Encapsulation

Data members are kept private/protected within classes.

Inheritance

All chess piece classes inherit from the base Piece class.

Polymorphism

canMove() is implemented as a virtual function and overridden in derived classes.

Composition

The Board class contains and manages a 2D structure of Piece objects.

📌 Project Type

Semester Project for Object Oriented Programming Lab
FAST National University of Computer and Emerging Sciences — Faisalabad Campus

👨‍💻 Author

Developed as part of academic coursework at FAST NUCES Faisalabad.


This version looks much more GitHub-ready and professional.
