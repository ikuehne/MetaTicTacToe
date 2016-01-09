/**
 * @file game.hpp
 * @author Ian Kuehne
 * @date Winter 2015
 *
 * @brief A representation of a meta-tic-tac-toe game.
 */

#pragma once

#include "metaboard.hpp"

/**
 * @brief A game of meta-tic-tac-toe.
 */
class Game {
private:
    /**
     * @brief The board on which the game is played.
     */
    MetaBoard board;

    /**
     * @brief The row of the current board, or -1 if no current board.
     */
    int metarow;

    /**
     * @brief The column of the current board, or -1 if no current board.
     */
    int metacol;

    /**
     * @brief The next player to play.
     */
    int player;


    /**
     * @brief Makes a move on the active board and changes the current player.
     *
     * @param row: The row of the move.  Assumes that the row is valid.
     * @param col: The column of the move.  Assumes that the column is valid.
     */
    void makeMove(int row, int col);

    /**
     * @brief Displays the current state of the game.
     */
    void display(void) const;

    /**
     * @brief Get a valid row and column from stdin.
     *
     * Prints error messages to stdout as appropriate.  The new row and column
     * are guaranteed to be integers between 0 and 2.
     *
     * @param row: A reference to an int which will be changed to the new row.
     * @param col: A reference to an int which will be changed to the new
     *             column.
     */
    void get_row_column(int &row, int &col) const;

public:
    /**
     * @brief Creates a new game.
     */
    Game();

    /**
     * @brief Start a game.
     *
     * Allows two players to interactively play via the command line.
     */
    void run();
};
