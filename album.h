#ifndef ALBUM_H
#define ALBUM_H

#include <QList>
//using std::QList;
#include <QVector>
//using std::QVector;

#include "brano.h"

class Album	{
private:
    QList<Brano*> listaTracce;
    QString artista;
    QString annoAlbum;
    QString genereAlbum;
	int numeroTracceAlbum;
	Durata durataAlbum;
	double dimensioneAlbum;
public:
    Album(QString="-", QString="-", QString="-", int=0, int=0,int=0, double=0 );
/*
	~Album();
	Album(const Album&);
*/
	void aggiungiBranoAdAlbum(Brano* );
    QString getAnnoAlbum() const;
    QString getGenereAlbum() const;
	double getDimensioneAlbum() const;
	Durata getDurataAlbum() const;

};

#endif
