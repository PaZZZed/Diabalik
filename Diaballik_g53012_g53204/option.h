#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include "mwdiaballik.h"

namespace Ui {
class Option;
}
/*!
 * \brief The Option class represent the screen option of the game.
 */
class Option : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Option construct the window Option.
     * \param parent is the parent of the class.
     */
    explicit Option(QWidget *parent = nullptr);

    /*!
     * \brief getVal: Gets the current value of QComboBox.
     */
    unsigned getVal();

    /*!
     * \brief getTaille:Gets the size of the board.
     */
    unsigned getTaille();

    /*
     * \brief getVariante: Gets the mode of the game.
     * \return
     */
    bool getVariante();
    ~Option();

private slots:
    /*!
     * \brief ouverture: Open the principal Window.
     */
    void ouverture();


private:
    Ui::Option *ui; /**< TODO: describe */

    /*!
     * \brief jeu_ is the MainWindow.
     */
    MWDiaballik *jeu_;
};

#endif // OPTION_H
