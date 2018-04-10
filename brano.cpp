
#include "brano.h"
using std::cout;
using std::endl;



unsigned int Brano::numeroBraniRegistrati=0;





Brano::Brano(/*QString id,*/ QString NB, QString A, QString alb, double DIM, int m, int s, QString G, QString Y) :
                                                                                //BID(id),
																				nomeBrano(NB),
                                                                                albumBrano(alb),
                                                                                artistaBrano(A),
																				dimensioneBrano(DIM),
																				durataBrano(m,s),
																				genereBrano(G),
																				annoBrano(Y)
                                                                                {};
																		



QString Brano::getNomeBrano() const{
	return nomeBrano;
}
QString Brano::getAlbumBrano() const    {
    return albumBrano;
}
QString Brano::getArtista() const{
    return artistaBrano;
}
QString Brano::getGenereBrano() const	{
	return genereBrano;
}
QString Brano::getAnnoBrano() const	{
	return annoBrano;
}
double Brano::getDimensioneBrano() const	{
	return dimensioneBrano;
}
QString Brano::getDurataBrano() const	{
    return Durata::toQString(durataBrano);
}


//printers
void Brano::printNomeBrano() const	{
    cout<<"Nome brano: "<<nomeBrano.toStdString()<<endl;
}
void Brano::printArtista() const	{
    cout<<"Artista: "<<artistaBrano.toStdString()<<endl;
}
void Brano::printBID() const	{
    //cout<<"BID: "<<BID<<endl;
}
void Brano::printDimensioneBrano() const	{
    cout<<"Dimensione: "<<dimensioneBrano<<" MB"<<endl;
}

void Brano::printDurataBrano() const	{
    cout<<"Durata: "<<durataBrano<<endl;
}

void Brano::printGenereBrano() const	{
    cout<<"Genere: "<<genereBrano.toStdString()<<endl;
}

void Brano::printAnnoBrano() const	{
    cout<<"Anno: "<<annoBrano.toStdString()<<endl;
}

void Brano::printTutteInformazioni() const	{
    printNomeBrano();
    printBID();
    printArtista();
    printDurataBrano();
    printDimensioneBrano();
    printGenereBrano();
    printAnnoBrano();
}
