#include "utentegold.h"
#include <iostream>

using std::cout;
using std::endl;

const QString UtenteGold::tipologiaAbbonamento="Gold";


UtenteGold::UtenteGold(QString n, QString c, QString e, QString p, bool b, int i) : Utente( n, c, e, p, b,i )	{
}

QString UtenteGold::getTipologiaAbbonamento() const   {
    return tipologiaAbbonamento;
}

bool UtenteGold::hasInfiniteSearch() const {
    return haRicercheInfinite;
}

int UtenteGold::getRicercheDisponibili()  const{
    return numeroRicerchePossibili;
}

void UtenteGold::diminuisciRicercheDisponibili() {
}

int UtenteGold::getTipoRicerca() const{
    return 3;
}
