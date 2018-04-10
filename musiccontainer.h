#ifndef MUSICCONTAINTER_H
#define MUSICCONTAINTER_H

#include<vector>
using std::vector;

#include "brano.cpp"

class MusicContainer	{
private:
        vector<Brano*> vettoreDeiBrani;
public:

        MusicContainer() {}
        //~MusicContainer();

        vector<Brano*> aggiungiBrano(Brano*);

        //toglibrano è da FARE.
        vector<Brano*> togliBrano(Brano*);
        double dimensioneContainer() const;
        void printTitoliCanzoni() const;
        void printListaArtisti();

        QVector<Brano*>::const_iterator getBegin() const;
        QVector<Brano*>::const_iterator getEnd() const;

};

#endif

