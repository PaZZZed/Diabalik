#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "squareview.h"
#include "Model/game.h"
#include <QGraphicsScene>

/*!
 * \brief The BoardView class represent the board of the game
 */
class BoardView : public QGraphicsScene
{
    /*!
     * \brief game_ is the current Game
     */
    Game &game_;
    /*!
     * \brief count_ is the number of moves the player has done
     */
    int &count_;
    /*!
     * \brief canPass_ if the ball is already passed
     */
    bool &canPass_;
public:
    /*!
     * \brief BoardView is the constructor of the class
     * \param game is the game we want to draw the board
     * \param count is the moves the current player has done
     * \param canPass check if the current player has passed the ball already
     */
    BoardView(Game &game,int &count,bool &canPass);
    /*!
     * \brief draw: draw the current board of the game
     */
    void draw();
    /*!
     * \brief moves color the squares the player can move to
     * \param pos  position of the square that the player can move to
     * \param sv squareView that will be colored
     */
    void moves(Position pos,SquareView *sv);

};

#endif // BOARDVIEW_H
