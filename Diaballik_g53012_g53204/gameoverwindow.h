#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>
#include "Model/game.h"

using namespace diaballik;

namespace Ui {
class GameOverWindow;
}
/*!
 * \brief The GameOverWindow class represent the game over screen
 */
class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief GameOverWindow is the constructor of the class
     * \param parent is the parent of the class
     */
    GameOverWindow(QWidget *parent = nullptr);

    ~GameOverWindow();
    /*!
     * \brief setGame set the game as the current game
     * \param game is the current game
     */
    void setGame(Game &game);
private slots:
    /*!
     * \brief replay start a new game of diaballik
     */
    void replay();
private:
    Ui::GameOverWindow *ui;
    /*!
     * \brief game_ is the current game of diaballik
     */
    Game game_;

};

#endif // GAMEOVERWINDOW_H
