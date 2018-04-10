#ifndef UTENTEGOLD_H
#define UTENTEGOLD_H

#include "utente.h"

#include <QVector>
#include <QString>
#include <QList>


   class UtenteGold : public Utente {
private:
	static const QString tipologiaAbbonamento;
public:
    UtenteGold(QString, QString, QString, QString, bool, int);
    QString getTipologiaAbbonamento() const;
    bool hasInfiniteSearch() const;
    int getRicercheDisponibili() const;
    void diminuisciRicercheDisponibili();
    virtual int getTipoRicerca() const;
};

#endif
