#ifndef UTENTE_H
#define UTENTE_H

#include <QString>
#include "brano.h"

using std::endl;
using std::cout;

class Utente	{
private:
	QString nome;
	QString cognome;
	QString email;
    QString password;

protected:
    bool haRicercheInfinite;
    int numeroRicerchePossibili;
    static QString myToLower(QString input);

public:
    Utente(QString , QString="", QString="", QString="", bool=false, int=0);
    virtual ~Utente() {}
	
	//getters
	QString getNome() const;
	QString getCognome() const;
	QString getEmail() const;
    QString getPassword() const;

    virtual QString getTipologiaAbbonamento() const=0;
    virtual bool hasInfiniteSearch() const=0;
    virtual int getRicercheDisponibili() const=0;
    virtual void diminuisciRicercheDisponibili() =0;
    virtual int getTipoRicerca() const=0;

	//printers
	void printNome() const;
	void printCognome() const;
	void printEmail() const;
	void printTutteInformazioniUtente() const;
};

#endif
