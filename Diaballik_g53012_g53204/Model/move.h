#ifndef MOVE_H
#define MOVE_H

#include "Model/position.h"
#include "Model/support.h"

namespace diaballik
{

/*!
 * \brief The Move class represents a mouvement of a support.
 */
class Move{

    /*!
     * \brief supp_ is a support.
     */
    Support supp_;

    /*!
     * \brief start_ is the start position of a support.
     */
    Position start_;

    /*!
     * \brief end_ is the end position of a support.
     */
    Position end_;

    /*!
     * \brief degree_ represents the number of "mouvments" that a support can make.
     */
    int degree_;

public:
    /*!
     * \brief Move construct move.
     *
     * \param supp is a support of the board.
     *
     * \param start is the start position of the support.
     * \param end is the final position of the the support
     * \param degree
     */
    Move(Support supp, Position start, Position end,int degree);

    /*!
     * \brief getPositionEnd gives us the final position of a move.
     * \return the  final position of a move.
     */
    Position getPositionEnd();

    /*!
     * \brief getPositionStart gives us the starting position of a move.
     * \return the starting position of a move.
     */
    Position getPositionStart();

    /*!
     * \brief getSupport gives us the support at the starting position of a move.
     * \return the support at the starting position of a move
     */
    Support getSupport();

    /*!
     * \brief getDegree get the level of the move.
     *
     * \return the level of the move.
     */
    int getDegree();
};
}

#endif // MOVE_H
