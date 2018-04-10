#ifndef UTENTESILVER_H
#define UTENTESILVER_H


#include "utente.h"
#include<QVector>
#include<QString>


class UtenteSilver : public Utente 	{
private:
    static const QString tipologiaAbbonamento;
public:
    UtenteSilver(QString, QString, QString, QString, bool, int);
    QString getTipologiaAbbonamento() const;
    bool hasInfiniteSearch() const;
    int getRicercheDisponibili() const;
    void diminuisciRicercheDisponibili();
    int getTipoRicerca() const;
};

#endif

