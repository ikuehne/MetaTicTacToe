/**
 * @file board.cpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a tic-tac-toe board.
 */

// The documentation is in the header file so that it is not duplicated.

#include <iostream>
#include "board.hpp"

using namespace std;

Board::Board() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++)
            board[row][col] = NO_PIECE;
    }
}

Piece Board::query(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return NO_PIECE;
    return board[row][col];
}

int Board::checkWin(void) const {
    // Check rows first.
    for (int row = 0; row < 3; row++)
        if (board[row][0] == board[row][1]
         && board[row][1] == board[row][2]
         && board[row][0] != 0)
            return board[row][0];

    // Then check columns.
    for (int col = 0; col < 3; col++)
        if (board[0][col] == board[1][col]
         && board[1][col] == board[2][col]
         && board[0][col] != 0)
            return board[0][col];

    // Then top left->bottom right...
    if (board[0][0] == board[1][1]
     && board[1][1] == board[2][2]
     && board[0][0] != 0)
        return board[0][0];

    // And finally bottom left->top right.
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return 0;
}   

bool Board::checkFull(void) const {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row][col] == NO_PIECE)
                return false;
    return true;
}

bool Board::checkDraw(void) const {
    return checkFull()? checkWin() == 0: false;
}

void Board::set(int row, int col, Piece piece) {
    // Do some bounds checking as per the documentation.
    if (row < 0 || row > 2 || col < 0 || col > 2) return;
    board[row][col] = piece;
}

void Board::display(void) const {
    const string divider = "-------";
    for (int row = 0; row < 3; row++) {
        cout << divider << endl;
        for (int col = 0; col < 3; col++) {
            cout << "|";
            // Print out a piece of the board.
            switch (board[row][col]) {
            case X_PIECE:
                cout << "X";
                break;
            case O_PIECE:
                cout << "O";
                break;
            case NO_PIECE:
                cout << " ";
                break;
            }
        }
        cout << "|" << endl;
    }
    cout << divider;
}

// Unit test.
#ifdef TEST_BOARD

int main(void) {
    Board test_board = Board();

    cout << "Should be empty:" << endl;
    test_board.display();
    cout << "Should be false: " << test_board.checkDraw() << endl;
    cout << "Should be zero: " << test_board.checkWin() << endl;
    test_board.set(0, 0, X_PIECE);
    test_board.set(1, 1, X_PIECE);
    test_board.set(2, 2, X_PIECE);
    cout << "Should be false: " << test_board.checkDraw();
    cout << "Should be 1: " << test_board.checkWin();
    cout << "Should be " << X_PIECE << ": " << test_board.query(1, 1) << endl;
    cout << "Should be " << NO_PIECE << ": " << test_board.query(0, 1) << endl;
    cout << "Should be " << NO_PIECE << ": " << test_board.query(0, 4) << endl;
    cout << "Should be " << NO_PIECE << ": " << test_board.query(0, 9) << endl;
    cout << "Should have a top left-bottom right diagonal of Xs:" << endl;
    test_board.display();
    test_board.set(0, 2, O_PIECE);
    test_board.set(1, 1, O_PIECE);
    test_board.set(2, 0, O_PIECE);
    cout << "Should be " << O_PIECE << ": " << test_board.query(1, 1) << endl;
    cout << "Should be " << O_PIECE << ": " << test_board.query(0, 2) << endl;
    cout << "Should have a bottom left-top right diagonal of Os and Xs in the "
         << "remaining corners: " << endl;
    test_board.display();
    cout << "Should be false: " << test_board.checkDraw() << endl;
    cout << "Should be 2: " << test_board.checkWin() << endl;
    test_board.set(0, 2, X_PIECE);
    test_board.set(1, 2, O_PIECE);
    test_board.set(2, 1, X_PIECE);
    test_board.set(1, 0, X_PIECE);
    test_board.set(0, 1, O_PIECE);
    test_board.display();
    cout << "Should be true: " << test_board.checkDraw() << endl;
    cout << "Should be 0: " << test_board.checkWin() << endl;
}

#endif
