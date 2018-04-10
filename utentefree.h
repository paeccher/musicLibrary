#ifndef UTENTEFREE_H
#define UTENTEFREE_H

#include "utente.h"
#include "sessione.h"
//class Sessione;

class UtenteFree : public Utente	{
private:
    static const  int numeroCanzoniAscoltabiliPerSessione;
	static const QString tipologiaAbbonamento;
	int numeroCanzoniAscoltateSessione;
public:
    UtenteFree(QString, QString, QString, QString, bool, int);
    QString getTipologiaAbbonamento() const;
    bool hasInfiniteSearch() const;
    int getRicercheDisponibili() const;
    void diminuisciRicercheDisponibili();
        virtual int getTipoRicerca() const;
};


#endif
