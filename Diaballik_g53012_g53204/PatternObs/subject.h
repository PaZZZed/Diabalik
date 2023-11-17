#ifndef SUBJECT_H
#define SUBJECT_H
#include "PatternObs/observer.h"

class Observer;

/*!
 * \brief Classe de base de tout "sujet d'observation"
 *
 * Classe dont dérive toute source d'événement
 * (ou "sujet d'observation") du modèle de conception
 * "Observateur / SujetDObservation".
 *
 * \author GOF (?).
 * \sa Observateur.
 */
class Subject
{

public:

    /*!
     * \brief Destructeur par défaut.
     */
    virtual ~Subject() = default;

    /*!
     * \brief Méthode permettant à un observateur de s'enregistrer
     * comme écouteur du sujet d'observation.
     *
     * \param obs un pointeur vers le candidat observateur.
     */
    virtual void registerObserver(Observer * obs) =0;

    /*!
     * \brief Méthode permettant à un observateur de se retirer de la
     * liste des écouteurs patentés du sujet d'observation.
     *
     * \param obs l'adresse de l'observateur désintéressé.
     */
    virtual void removeObserver(Observer * obs) =0;

protected:

    /*!
     * \brief Constructeur protégé pour éviter l'instanciation.
     */
    Subject() = default;

    /*!
     * \brief Méthode qui se charge de prévenir les observateurs d'un
     * changement d'état du sujet d'observation, en invoquant leur
     * méthode rafraichir.
     *
     * \sa Observateur::rafraichir(SujetDObservation *).
     */
    virtual void notifierChangement()=0;

};


#endif // SUBJECT_H
