/**
 * @file metaboard.cpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a meta-tic-tac-toe board.
 */

#include <iostream>
#include "metaboard.hpp"

using namespace std;

MetaBoard::MetaBoard() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = Board();
        }
    }
    metaboard = Board();
}

Piece MetaBoard::query(int metarow, int metacol, int row, int col) const {
    if (metarow < 0 || metarow > 2 || metacol < 0 || metacol > 2)
        return NO_PIECE;
    return board[metarow][metacol].query(row, col);
}

int MetaBoard::checkWin(void) const {
    // If a player has won by getting 3 in a row, they win.
    if (metaboard.checkWin())
        return metaboard.checkWin();

    // If all boards are finished, they can also win by getting more boards than
    // the other player.
    else if (metaboard.checkDraw()) {
        int player_1_boards = 0;
        int player_2_boards = 0;

        // So we count up the boards each player got.
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                switch (metaboard.query(row, col)) {
                    case X_PIECE:
                        player_1_boards++;
                        break;
                    case O_PIECE:
                        player_2_boards++;
                        break;
                }
            }
        }

        if (player_1_boards > player_2_boards)
            return 1;
        else if (player_2_boards > player_1_boards) 
            return 2;
    }

    // In all other cases nobody has won.
    return 0;
}

bool MetaBoard::checkFull(int row, int col) const {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (!board[row][col].checkFull())
                return false;

    return true;
}

bool MetaBoard::checkDraw(void) const {
    // There are cases where what looks like a draw on the metaboard is in fact
    // a win (because one player one more sub-boards) so we need to first check
    // if a player has won.
    if (metaboard.checkWin()) {
        return false;
    } else {
        return metaboard.checkDraw();
    }
}

void MetaBoard::set(int metarow, int metacol, int row, int col, Piece piece) {
    board[metarow][metacol].set(row, col, piece);

    // Keep track of which sub-boards have been won.
    metaboard.set(metarow, metacol, board[metarow][metacol].checkWin());
}

void MetaBoard::display(void) const {
    const string divider = "-------";
    const string metadivider = "+-%-%-%-+-%-%-%-+-%-%-%-+";
    for (int metarow = 0; metarow < 3; metarow++) {
        cout << metadivider << endl;
        for (int row = 0; row < 3; row++) {
            for (int metacol = 0; metacol < 3; metacol++) {
                cout << "|" << divider;
            }
            cout << "|" << endl;
            for (int metacol = 0; metacol < 3; metacol++) {
                cout << "%";
                for (int col = 0; col < 3; col++) {
                    cout << "|";
                    switch (query(metarow, metacol, row, col)) {
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
                cout << "|";
            }
            cout << "%" << endl;
        }
        for (int metacol = 0; metacol < 3; metacol++) {
            cout << "|" << divider;
        }
        cout << "|" << endl;
    }
    cout << metadivider;
}

