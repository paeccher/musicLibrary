#include "utentefree.h"


const  int UtenteFree::numeroCanzoniAscoltabiliPerSessione=5;

const QString UtenteFree::tipologiaAbbonamento="Free";

QString UtenteFree::getTipologiaAbbonamento() const  {
    return tipologiaAbbonamento;
}

UtenteFree::UtenteFree(QString n, QString c, QString e, QString p, bool b, int i) : Utente(n,c,e,p,b,i)	{
}

bool UtenteFree::hasInfiniteSearch() const {
    return haRicercheInfinite;
}

int UtenteFree::getRicercheDisponibili() const {
    return numeroRicerchePossibili;
}

void UtenteFree::diminuisciRicercheDisponibili() {
    numeroRicerchePossibili--;
}


int UtenteFree::getTipoRicerca() const{
    return 1;
}
