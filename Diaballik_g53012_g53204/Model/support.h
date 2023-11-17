#ifndef SUPPORT_H
#define SUPPORT_H
#include "Model/playerColor.h"
#include "iostream"
using namespace std;

namespace diaballik{

/*!
 * \brief The Support class represents the support of the game.
 */
class Support
{
    /*!
     * \brief bille_ represents the ball.
     */
    bool ball_;

    /*!
     * \brief color_ represents the color of the support.
     */
    PlayerColor color_;
public:

    /*!
     * \brief Support construct the support.
     */
    Support();

    /*!
     * \brief Support construct a support with a color and/or a ball.
     * \param color is the color of the support.
     * \param ball is the ball.
     */
    Support(PlayerColor color,bool ball);

    /*!
     * \brief hasBall check if the support has a ball.
     * \return true if the support has the ball.
     */
    bool hasBall();

    /*!
     * \brief getColorSupport gives us the color of the support.
     * \return the color of the support.
     */
    PlayerColor getColorSupport();

    /*!
     * \brief setColorSupport set the color of the support.
     * \param newColor is the new color of the support.
     */
    void setColorSupport(PlayerColor newColor);

    /*!
     * \brief setBallSupport change the status of the ball.
     * \param val is the new value of the ball.
     */
    void setBallSupport (bool val);

    /*!
     * \brief toString return a representation of the support.
     * \return supp.
     */
    string toString()const;

    /*!
     * \brief operator << of injecting an Support into an output stream.
     * \param outputStream stream in which to inject a.
     * \param a Support to inject.
     *
     * \return ostream after injection.
     */
    friend ostream& operator <<(ostream& outputStream, const Support &a);

};
}

#endif // SUPPORT_H
