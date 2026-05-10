#include <iostream>
#include <string>
#include <cctype>
#include "Board.h"
using namespace std;

// converts column letter (a-h) to index (0-7) - handles uppercase too
int letterToCol(char ch) { return tolower(ch) - 'a'; }

// converts row number (1-8) to array index
int numToRow(int n) { return 8 - n; }

// converts whole string to lowercase so input is not case sensitive
string toLowerStr(string s) {
    for (int i = 0; i < (int)s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main() {
    cout << "*******************************\n";
    cout << "*    Chess Game  - OOP Lab    *\n";
    cout << "*******************************\n\n";
    cout << "Instructions:\n";
    cout << "  - Enter moves as: e2 e4\n";
    cout << "  - First square = from, second = to\n";
    cout << "  - Type 'exit' to quit anytime\n\n";

    Board myBoard;
    myBoard.printBoard();

    char currentPlayer = 'W';
    string sq1, sq2;

    while (true) {
        if (currentPlayer == 'W')
            cout << "[ White ] Enter move: ";
        else
            cout << "[ Black ] Enter move: ";

        cin >> sq1;
        sq1 = toLowerStr(sq1); // make it lowercase so EXIT, Exit, exit all cases work

        if (sq1 == "exit") {
            cout << "\nGame closed. Goodbye!\n";
            break;
        }

        cin >> sq2;
        sq2 = toLowerStr(sq2); 

        // format checking
        if (sq1.length() != 2 || sq2.length() != 2) {
            cout << ">> Wrong format! Example: e2 e4\n\n";
            continue;
        }

        char colFrom = sq1[0];
        int  rowFrom = sq1[1] - '0';
        char colTo   = sq2[0];
        int  rowTo   = sq2[1] - '0';

        int c1 = letterToCol(colFrom);
        int r1 = numToRow(rowFrom);
        int c2 = letterToCol(colTo);
        int r2 = numToRow(rowTo);

        if (myBoard.doMove(r1, c1, r2, c2, currentPlayer)) {
            myBoard.printBoard();

            if (myBoard.gameEnded()) {
                char winner = myBoard.whoWon();
                cout << "============================\n";
                if (winner == 'W')
                    cout << "  White player wins! GG :)\n";
                else
                    cout << "  Black player wins! GG :)\n";
                cout << "============================\n";
                break;
            }

            // switch turn
            currentPlayer = (currentPlayer == 'W') ? 'B' : 'W';
        }
        cout << "\n";
    }

    return 0;
}
