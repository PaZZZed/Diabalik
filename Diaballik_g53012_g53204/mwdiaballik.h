 #ifndef MWDIABALLIK_H
#define MWDIABALLIK_H

#include <QMainWindow>
#include "PatternObs/observer.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QGraphicsScene>
#include "boardview.h"
#include "gameoverwindow.h"

using namespace diaballik;

QT_BEGIN_NAMESPACE
namespace Ui { class MWDiaballik; }
QT_END_NAMESPACE

/*!
 * \brief The MWDiaballik class reprensent the mainWindow
 */
class MWDiaballik : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    /*!
     * \brief MWDiaballik construct the window.
     * \param parent is the parent of the class.
     */
    MWDiaballik(QWidget *parent = nullptr,bool=false,unsigned =5);

    /*!
     * \brief connexion connects buttons with method.
     */
    void connexion();

    /*!
     * \brief update updates the board.
     * \param sdo is the subject.
     */
    void update(Subject * sdo) override;

     ~MWDiaballik();


private slots:

    /*!
     * \brief AfficheAide display the rules of the game.
     */
    void AfficheAide();

    /*!
     * \brief swap: Swap the player
     */
    void swap();

    /*!
     * \brief fairPlay check if the game is fair.
     */
    void fairPlay();
private:

    Ui::MWDiaballik *ui; /**< TODO: describe */

    /*!
     * \brief action_Aide
     */
    QAction *action_Aide;

    /*!
     * \brief game is the current game.
     */
    Game game;

    /*!
     * \brief board is the View of the board.
     */
    BoardView * board;

    /*!
     * \brief count_ is number of movement of a player.
     */
    int count_=0;

    /*!
     * \brief canPass_ check if the ball can pass
     */
    bool canPass_=true;

    /*!
     * \brief anti_jeu_ check if there is anti_game.
     */
    bool anti_jeu_=false;

};
#endif // MWDIABALLIK_H
