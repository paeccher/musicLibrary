#include "utentesilver.h"
#include <iostream>

using std::cin;

const QString UtenteSilver::tipologiaAbbonamento="Silver";

UtenteSilver::UtenteSilver(QString n, QString c, QString e, QString p, bool b, int i) : Utente( n, c, e, p, b ,i)	{

}

QString UtenteSilver::getTipologiaAbbonamento() const  {
    return tipologiaAbbonamento;
}

bool UtenteSilver::hasInfiniteSearch() const{
    return haRicercheInfinite;
}

int UtenteSilver::getRicercheDisponibili()const  {
    return numeroRicerchePossibili;
}

void UtenteSilver::diminuisciRicercheDisponibili() {
    numeroRicerchePossibili--;
}

int UtenteSilver::getTipoRicerca() const{
    return 2;
}
