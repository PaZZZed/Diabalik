#ifndef CASE_H
#define CASE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QtDebug>
#include "Model/game.h"

using namespace diaballik;

/*!
 * \brief The SquareView class represent the square of the board
 */
class SquareView :public QGraphicsItem
{
public:
    /*!
     * \brief SquareView is the constructor of the class, create a new square
     * \param size is the size of the squares we will create
     * \param game is the current game we will put our squares in
     * \param pos is the position of the square in the board
     * \param count the moves the square can do
     * \param canPass check if the square can pass the ball
     */
    SquareView(Game &game,int size, Position pos,int &count,bool &canPass);
    /*!
     * \brief boundingRect create our square(rectangle)
     * \return the square
     */
    QRectF boundingRect() const override;
    /*!
     * \brief paint will paint our squares
     * \param painter is the color the square will take
     * \param option
     * \param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    /*!
     * \brief setColor will set a new color
     * \param color is the new color
     */
    void setColor(bool &color);

    /*!
     * \brief checkPos check if the square can move
     * \param pos is the position we want to check if the square can move to
     * \return
     */
    bool checkPos(Position pos);


protected:
    /*!
     * \brief mousePressEvent on mouse click it will do certain actions
     * \param event on mouse click
     */

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    /*!
     * \brief game_ is the current game
     */
    Game &game_;
    /*!
     * \brief selected_ check if the quare change color
     */
    bool selected_;
    /*!
     * \brief size_ the size of the square
     */
    int size_;
    /*!
     * \brief pos_ is the position of the square in the board
     */
    Position pos_;
    /*!
     * \brief count_ count how much moves the square still have
     */
    int &count_;
    /*!
     * \brief canPass_ check if the square can still pas the ball
     */
    bool &canPass_;

};

#endif // CASE_H

