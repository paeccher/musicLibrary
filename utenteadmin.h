#ifndef UTENTEADMIN_H
#define UTENTEADMIN_H

#include "utente.h"
#include <QString>

class UtenteAdmin : public Utente
{
private:
    static const QString tipologiaAbbonamento;
public:
    UtenteAdmin(QString, QString, QString, QString, bool, int);
    QString getTipologiaAbbonamento() const;
    bool hasInfiniteSearch() const;
    int getRicercheDisponibili() const;
    void diminuisciRicercheDisponibili();
    virtual int getTipoRicerca() const;

};

#endif // UTENTEADMIN_H
