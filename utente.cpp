#include "utente.h"

QString Utente::myToLower(QString input)	{
    QString qOutput;
    for ( int i = 0 ; i < input.length() ; ++i )	{
        QChar inputChar=(input[i]);
        QChar inputCharLowered=inputChar.QChar::toLower() ;
        qOutput.push_back(inputCharLowered) ;
    }
    return qOutput;
}


Utente::Utente(QString n, QString c, QString e, QString p, bool b, int i) :
												nome(n),
												cognome(c),
                                                email(e),
                                                password(p),
                                                haRicercheInfinite(b),
                                                numeroRicerchePossibili(i)
												{}

QString Utente::getNome() const	{
	return nome;
}
QString Utente::getCognome() const	{
	return cognome;
}
QString Utente::getEmail() const	{
	return email;
}

QString Utente::getPassword() const {
    return password;
}

void Utente::printNome() const	{
    cout<<"Nome: "<<nome.toStdString()<<std::endl;
}
void Utente::printCognome() const	{
    cout<<"Cognome: "<<cognome.toStdString()<<std::endl;
}
void Utente::printEmail() const	{
    cout<<"Email: "<<email.toStdString()<<std::endl;
}
void Utente::printTutteInformazioniUtente() const	{
    printNome();
    printCognome();
    printEmail();
	cout<<"-----------------------------------------"<<std::endl;
}

