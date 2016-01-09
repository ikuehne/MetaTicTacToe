/**
 * @file metaboard.hpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a meta-tic-tac-toe board.
 */

#pragma once

#include "board.hpp"

/**
 * @brief A board for a game of meta-tic-tac-toe.
 */
class MetaBoard {
private:
    /**
     * @brief The full board, containing 9 sub-boards.
     */
    Board board[3][3];

    /**
     * @brief Records the winners on each sub-board.
     */
    Board metaboard;

public:

    /**
     * @brief Create an empty metaboard.
     */
    MetaBoard();

    /**
     * @brief Returns the piece at the given square.
     *
     * @param metarow The row of the board to use.
     * @param metacol The column of the board to use.
     * @param row The row on the inner board to use.
     * @param col The column on the inner board to use.
     */
    Piece query(int metarow, int metacol, int row, int col) const;

    /**
     * @brief Returns the winner of the game.
     *
     * @return 0 if no player has won yet, 1 if player 1 has won, and 2
     *         otherwise.
     */
    int checkWin(void) const;

    /**
     * @brief Returns whether the game has ended in a draw.
     *
     * @return `true` if a draw, `false` otherwise.
     */
    bool checkDraw(void) const;

    /**
     * @brief Returns whether there are any empty squares at the given
     *        sub-board.
     *
     * @param row The row of the sub-board to check.
     * @param col The column of the sub-board to check.
     */
    bool checkFull(int row, int col) const;

    /**
     * @brief Set the piece at a given square.
     *
     * Overrides any existing piece in the specified square.  If the square is
     * not on the board, does nothing.  If given an invalid piece, sets the
     * square to NO_PIECE.
     *
     * @param metarow The row of the board to use, an integer between 0 and 2
     *                inclusive.
     * @param metacol The column of the board to use, an integer between 0 and 2
     *                inclusive.
     * @param row The row on the sub-board to set, an integer between 0 and 2
     *            inclusive.
     * @param col The column on the sub-board to set, an integer between 0 and 2
     *            inclusive.
     * @param piece The piece to put at the given square.
     *
     * @return X_PIECE or O_PIECE if the corresponding piece is on the given
     *         square, or NO_PIECE if the square is empty.  If the rows or
     *         columns given are invalid, returns NO_PIECE.
     */
    void set(int metarow, int metacol, int row, int col, Piece piece);   

    /**
     * @brief Pretty-print the current board to stdout.
     */
    void display(void) const;
};
