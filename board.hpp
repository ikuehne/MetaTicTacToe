/**
 * @file board.hpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a tic-tac-toe board.
 */

#pragma once

/**
 * @brief Defines the `Piece` type as an alias for `int`.
 */
typedef int Piece;

/**
 * @brief A constant defining the representation of X pieces on the board.
 */
const Piece X_PIECE = 1;
/**
 * @brief A constant defining the representation of O pieces on the board.
 */
const Piece O_PIECE = 2;
/**
 * @brief A constant representing no piece on the board.
 */
const Piece NO_PIECE = 0;

/**
 * A tic-tac-toe board.
 */
class Board {
private:
    /**
     * @brief The board itself, as an array of Pieces.
     */
    Piece board[3][3];

public:
    /**
     * @brief Create an empty board.
     */
    Board();

    /**
     * @brief Get the piece at a given row and column of the board.
     *
     * @param row The row on the board to get, an integer between 0 and 2
     *            inclusive.
     * @param col The column on the board to get, an integer between 0 and 2
     *            inclusive.
     *
     * @return X_PIECE or O_PIECE if the corresponding piece is on the given
     *         square, or NO_PIECE if the square is empty.  If the row and
     *         column given are invalid, returns NO_PIECE.
     */
    Piece query(int row, int col) const;

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
     * @brief Set the piece at a given row and column of the board.
     *
     * Overrides any existing piece in the specified square.  If the square is
     * not on the board, does nothing.  If given an invalid piece, sets the
     * square to NO_PIECE.
     *
     * @param row The row on the board to set, an integer between 0 and 2
     *            inclusive.
     * @param col The column on the board to set, an integer between 0 and 2
     *            inclusive.
     * @param piece The piece to put at the given square.
     *
     * @return X_PIECE or O_PIECE if the corresponding piece is on the given
     *         square, or NO_PIECE if the square is empty.  If the row and
     *         column given are invalid, returns NO_PIECE.
     */
    void set(int row, int col, Piece piece);   

    /**
     * @brief Returns whether there are any empty squares on the board.
     *
     * @returns `true` if the board is full, `false` otherwise.
     */
    bool checkFull(void) const;

    /**
     * @brief Pretty-print the board to stdout.
     */
    void display(void) const;

};
