#ifndef SQUARE_H
#define SQUARE_H
#include "Model/support.h"

using namespace std;

namespace diaballik
{
/*!
 * \brief The Square class represents a square of the board.
 */
class Square
{

    Support supp_;
public:
    /*!
     * \brief Square construct a square.
     */
    Square();

    /*!
     * \brief Square construct a squaer with a color.
     * \param color represents the color of the support.
     */
    Square(PlayerColor color);

    /*!
     * \brief getSupp get support.
     * \return the support.
     */
    Support& getSupp();

    /*!
     * \brief isEmpty verify if the suqre is empty.
     * \return true if the square is empty.
     */
    bool isEmpty() ;

    /**
     * @brief removeSupport
     */
    void removeSupport();

    /**
     * @brief addSupport
     * @param supp
     */
    void addSupport(Support supp);

    /*!
     * \brief isMyOwn check if the square color is the same as the player.
     * \param color is the color of the support we will check.
     * \return true if the square has the same color.
     */
    bool isMyOwn(PlayerColor color);

    /*!
     * \brief operator << of injecting an Square into an output stream.
     * \param outputStream stream in which to inject a.
     * \param a Square to inject.
     *
     * \return ostream after injection.
     */
    friend ostream& operator <<(ostream& outputStream, const Square &a);

};
}

#endif // SQUARE_H
