#ifndef LISTENER_H
#define LISTENER_H

/**
 * \file listener.h
 * \brief Listener
 * \author ACU
 * \version 0.4
 * \date 26/11/2018
 *
 * Démarre un thread d'écoute de client
 *
 */

#include <QThread>
#include <string>

using namespace std;

class Listener : public QThread
{
    //Q_OBJECT

public:
    Listener();

private:
    void run();

    /*!
    *  \brief Ecoute
    *
    *  Ouvre un socket qui écoute des messages provenants de clients
    *
    */
    void listenForClient();

};

#endif // LISTENER_H
