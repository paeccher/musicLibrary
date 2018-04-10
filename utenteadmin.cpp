#include "utenteadmin.h"

const QString UtenteAdmin::tipologiaAbbonamento="Admin";


UtenteAdmin::UtenteAdmin(QString n, QString c, QString e, QString p, bool b, int i) : Utente( n, c, e, p, b, i )	{

}

QString UtenteAdmin::getTipologiaAbbonamento() const   {
    return tipologiaAbbonamento;
}

bool UtenteAdmin::hasInfiniteSearch() const {
    return haRicercheInfinite;
}

int UtenteAdmin::getRicercheDisponibili() const {
    return numeroRicerchePossibili;
}

void UtenteAdmin::diminuisciRicercheDisponibili() {
}

int UtenteAdmin::getTipoRicerca() const{
    return 3;
}
