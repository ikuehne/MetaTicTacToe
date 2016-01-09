/**
 * @file game.cpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a meta-tic-tac-toe game.
 */

#include "game.hpp"
#include <iostream>
#include <limits>

using namespace std;

Game::Game() {
    player = 1;
    metarow = -1;
    metacol = -1;
}

void Game::makeMove(int row, int col) {
    // First make the move.
    if (player == 1) {
        board.set(metarow, metacol, row, col, X_PIECE);
        player = 2;
    } else {
        board.set(metarow, metacol, row, col, O_PIECE);
        player = 1;
    }

    // If the new board is full, the next player can do whatever.
    if (board.checkFull(row, col)) {
        metarow = -1;
        metacol = -1;

    // Otherwise, move to the new board.
    } else {
        metarow = row;
        metacol = col;
    }
}

void Game::display(void) const {
    board.display();
    if (metarow == -1) {
        cout << endl << "The board may be chosen by the next player." << endl;
    } else {
        cout << endl << "Current row: " << metarow << "." << endl;
        cout << "Current column: " << metacol << "." << endl;
    }
    cout << "Current player: " << player << "." << endl;
}

void Game::get_row_column(int &row, int &col) const {
    while (1) {
        // Figure out what is going on if there is an error.
        if (!(cin >> row >> col)) {
            // If there is no more input, should gracefully exit.
            if (cin.eof()) return;

            // If there is another problem, print a message and recover.
            cout << "Input should be two integers representing the row and "
                 << "column of the move." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Try again: ";
            continue;
        }

        // If the row is wrong, print an error message.
        if (row < 0 || row > 2) {
            cout << "Row must be an integer between 0 and 2." << endl;
            cout << "Try again: ";
            continue;
        }

        // Ditto with the column.
        if (col < 0 || col > 2) {
            cout << "Column must be an integer between 0 and 2." << endl;
            cout << "Try again: ";
            continue;
        }

        return;
    }
}

void Game::run(void) {
    int row, col;
    while (!(board.checkWin() || board.checkDraw())) {
        display();

        // If there is no current board, get one.
        if (metarow == -1) {
            cout << "Enter the board to play on: ";
            get_row_column(metarow, metacol);
            if (board.checkFull(metarow, metacol)) {
                cout << "That board is already full." << endl;
                continue;
            }
        }

        cout << "Enter a move: ";
        get_row_column(row, col);

        // The corresponding square should not already have a piece.
        if (board.query(metarow, metacol, row, col)) {
            cout << "There is already a piece there." << endl;
            continue;
        }

        makeMove(row, col);
    }

    display();

    // Print a message for the winner.
    if (board.checkWin())
        cout << "Player " << board.checkWin() << " has won.  All of midgard "
             << "will sing of her deeds." << endl;
    else cout << "Draw.  So it goes." << endl;
}
