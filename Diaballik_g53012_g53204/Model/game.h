#ifndef GAME_H
#define GAME_H
#include "Model/board.h"
#include "Model/move.h"
#include "Model/player.h"
#include "PatternObs/subject.h"
#include <list>

namespace diaballik
{
/*!
 * \brief The Game class controls the game.
 */
class Game : public Subject
{

    /*!
     * \brief current_ is the current player.
     */
    Player current_;

    /*!
     * \brief opponent_ is the opponent player.
     */
    Player opponent_;

    /*!
     * \brief board_ is the board of the game.
     */
    Board board_;

    /*!
     * \brief selected_ is the selected position.
     */
    Position selected_;
public:

    /*!
     * \brief Game construct the game.
     */
    Game();

    /*!
     * \brief getBoard give us the current board.
     * \return the current board.
     */
    Board& getBoard();

    /*!
     * \brief getCurrent give us the current player.
     * \return the current player.
     */
    Player getCurrent();

    /*!
     * \brief getOpponent give us the opponent player.
     * \return the opponent player.
     */
    Player getOpponent();

    /*!
     * \brief init initialize our board with supports at defined places.
     * \param taille is the length of the board.
     * \param variante designates the style of the board.
     */
    void init(unsigned taille, bool variante);

    /*!
     *\brief moveSupport move the support.
     *
     * \param pos1 is the starting position.
     *
     * \param pos2 is the ending position.
     *
     * \param supp is the support to move.
     */
    void moveSupport(Position pos1, Position pos2, Support supp);

    /*!
     * \brief isFairPlay check if the opposite player is fair.
     *
     * \return true if there if there is anti jeu.
     */
    bool isFairPlay();

    /*!
     * \brief swapPlayer swap the players.
     */
    void swapPlayer();

    /*!
     * \brief passBall pass the ball between supports.
     *
     * \param pos is the final position of the ball.
     */
    void passBall(Position pos,bool &pass);

    /*!
     * \brief isOver check if the game is over.
     *
     * \return true if the game is over.
     */
    bool isOver();

    /*!
     * \brief start check if the game begin in good conditions.
     */
    void start();

    /*!
     * \brief getWinner gives the winner of the game.
     * \return return the winner.
     */
    Player getWinner();

    /*!
     * \brief applyMove apply the movement given in parameter.
     * \param pos is the final position of the support.
     * \param count represents the degree of movement.
     */
    void applyMove(Position pos, int &count);

    /*!
     * \brief select a position in the board.
     *
     * \param row represent the row in the board.
     *
     * \param  col represent the col in the board.
     */
    void select( int row, int col);

    /*!
     * \brief getSelected select a support at a selected position.
     *
     * \return a support at a selected position.
     */
    Support getSelected();

    /*!
     * \brief changeSelected change the selected position
     */
    void changeSelected();

    /*!
     * \brief move gives us all the possible movements for a support.
     * \param count
     * \return all the possible movements for a support.
     */
    vector<Move> move(int count);

    /*!
     * \brief getSelect gets the selected position.
     *
     * \return the selected position.
     */
    Position getSelect();

    /*!
     * \brief checkDirection check if the player can pass the ball to another support.
     *
     * \param pos is the final position.
     *
     * \param direction is the different direction.
     *
     * \return true if all the requirements are respected else return false.
     */
    bool checkDirection(Position pos,Direction direction);

    /*!
     * \brief infranchissable check if there are at least
     *  current support touching the line formed by
     *  opposing support.
     *
     * \param pos is a position inside the line.
     *
     * \return true if there are a current support touching
     * the line.
     */
    bool impassable(Position pos);

    /*!
     * \brief notifierChangement
     */
    void notifierChangement() override;

    /*!
     * \brief removeObserver
     * \param obs
     */
    void removeObserver(Observer *obs) override;

    /*!
     * \brief registerObserver
     * \param obs
     */
    void registerObserver(Observer *obs) override;

private:
    /*!
     * \brief Le vecteur d'observateurs enregistrés.
     */
    list<Observer *> mesObservateurs;
};
}
#endif // GAME_H
