#ifndef POSITION_H
#define POSITION_H
#include "iostream"
#include "Model/direction.h"

using namespace std;
namespace diaballik
{
/*!
 * \brief The Position class represent the x and y
 * coordinate of the board.
 */
class Position
{
    /*!
     * \brief row_ represents the row of the board.
     */
    int row_;

    /*!
     * \brief col_ represents of column the board.
     */
    int col_;

public:
    /*!
     * \brief Position construct an empty position.
     */
    Position();

    /*!
     * \brief Position construct a position with board coordinates
     * \param row represents the row of the board
     * \param col represents the col of the board
     */
    Position(int row,int col);

    /*!
     * \brief getRow gives us the row of the position.
     * \return the row of the position
     */
    int getRow();

    /*!
     * \brief getCol gives us the col of the position.
     * \return the col of the position.
     */
    int getCol();

    /*!
     * \brief next change the current position to a new position in the given direction.
     *
     * \param dir is the direction in which we will change our position.
     */
    void next(Direction dir);

    /*!
     * \brief operator << of injecting an Position into an output stream.
     * \param outputStream stream in which to inject a.
     * \param a Position to inject.
     *
     * \return ostream after injection.
     */
    friend ostream& operator <<(ostream& outputStream, const Position &a);

};
}
#endif // POSITION_H

