#ifndef BOARD_H
#define BOARD_H
#include "Model/position.h"
#include "Model/square.h"
#include "vector"

namespace diaballik
{

/*!
 * \brief The Board class represent the board of the game
 * which allows to represent the board.
 */
class Board
{
    /*!
     * \brief squares_ is a vector of vector of square.
     */
    vector<vector<Square>> squares_;

public:
    /*!
     * \brief Board represent the board of the game.
     * \param length is the length of the board.
     */
    Board(unsigned length);

    /*!
     * \brief getSquares will represent our board.
     * \return a vector of vector of squares.
     */
    vector<vector<Square>> getSquares();

    /*!
     * \brief putAt put a support in a square.
     *
     * \param pos is the position where we put our support.
     *
     * \param supp is the support that we will put at the given position.
     */
    void putAt(Position pos,Support supp);

    /*!
     * \brief isInside check if our position is inside the board.
     *
     * \param pos is the position we test.
     *
     * \return true if is inside the board else return false.
     */
    bool isInside(Position pos);

    /*!
     * \brief getSquare give us the Square at a specific position.
     *
     * \param pos is the position of the square.
     *
     * \return the Square at pos.
     */
    Square& getSquare(Position pos);

    /*!
     * \brief isFree check if the square is free.
     *
     * \param pos is the position of the square.
     *
     * \return true if the square is free.
     */
    bool isFree(Position pos);

    /*!
     * \brief isMyOwn check if the support on the position have
     * the same color as the given color.
     *
     * \param pos is the position of the square.
     *
     * \param color is the color of the player.
     *
     * \return true if the support have the same color as the given color.
     *
     */
    bool isMyOwn(Position pos,PlayerColor color);

    /*!
     * \brief remove the Support from the given position.
     *
     * \param pos is the position of the square we will remove.
     */
    void remove(Position pos);

};

}
#endif // BOARD_H
