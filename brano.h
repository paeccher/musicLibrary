#ifndef BRANO_H
#define BRANO_H

#include<QString>

#include "durata.h"

class Brano	{
private:
    static unsigned int numeroBraniRegistrati;
    //QString BID;
    QString nomeBrano;
    QString artistaBrano;
    QString albumBrano;
	double dimensioneBrano;	//in MB
	Durata durataBrano;
    QString genereBrano;
    QString annoBrano;
//	Album album;
public:
    Brano( /*QString ="",*/QString ="-", QString="-", QString="-", double=0, int=0, int=0 , QString="-" , QString="-");
	//Brano(const Brano&);
	//~Brano();

	//uguaglianza tra brani
    //bool operator==(const Brano& ) const;

	//getters
    //QString getBID() const;
    QString getNomeBrano() const;
    QString getArtista() const;
    QString getAlbumBrano() const;
	double getDimensioneBrano() const;
    QString getDurataBrano() const;
    QString getGenereBrano() const;
    QString getAnnoBrano() const;

	//printers
	void printNomeBrano() const;
	void printArtista() const;
	void printBID() const;
	void printDimensioneBrano() const;
	void printDurataBrano() const;
	void printGenereBrano() const;
	void printAnnoBrano() const;
	void printTutteInformazioni() const;
};

#endif
