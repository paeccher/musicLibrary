#ifndef SESSIONE_H
#define SESSIONE_H

#include<QString>
#include<QVector>
#include<QMessageBox>
#include<QLabel>

#include<brano.h>

#include"utente.h"
#include"utentefree.h"
#include"utentesilver.h"
#include"utentegold.h"
#include"utenteadmin.h"

#include<dirent.h>
#include <stdlib.h>
#include<stdio.h>
#include<fstream>


class Sessione
{
private:
    QString tipo;
    Utente* ptr;

public:
    Sessione();

    QVector<Brano*> tracksVector;
    QVector<Utente*> usersVector;
    
    Brano* find(QString title);
    QString matchIdTitolo(QString id);

    void loadTracks();
    void loadUsers();

    void addTrack(QString, QString, QString, QString, QString, QString, QString, QString);

    void removeUser(QString);
    void removeTrack(QString);

    bool checkAdmin(QString email);

    void setType(QString type);
    void setPtr(Utente* p);
    QString getType();
    Utente* getPtr();

    class funtoreRicerca	{
    public:
        int tipoRicerca;
        funtoreRicerca(int x=0)	: tipoRicerca(x)	{}
        bool operator() ( Brano* vec, QString titolo="", QString artista="", QString album="") const	{
            //per rendere ricerca case insensitive converto tutte le QStringe in minuscolo
            QString titoloLower=myToLower(titolo);
            QString artistaLower=myToLower(artista);
            QString albumLower=myToLower(album);
            int i=0;
            if ( titolo!="" )   {
                i=i+1;
            }
            if ( artista!="" )  {
                i=i+2;
            }
            if ( album!="" )    {
                i=i+4;
            }

            switch( tipoRicerca ) {
            case 1:

                return ( myToLower( vec->getNomeBrano() ) == titoloLower );

            case 2:

                if ( i==3 )   {
                   return ( myToLower( vec->getNomeBrano() ) == titoloLower && myToLower( vec->getArtista() ) == artistaLower );
                }
                else if ( i==2 )   {
                    return ( myToLower( vec->getArtista() ) == artistaLower );
                }
                else if ( i==1 )    {
                    return ( myToLower( vec->getNomeBrano() ) == titoloLower );
                }

            case 3:
                if ( i==7 )   {
                    return ( myToLower( vec->getNomeBrano() ) == titoloLower && myToLower( vec->getArtista() ) == artistaLower
                                                                             && myToLower( vec->getAlbumBrano() ) == albumLower );
                }
                else if ( i==6 )  {
                    return ( myToLower( vec->getArtista() ) == artistaLower && myToLower( vec->getAlbumBrano() ) == albumLower );
                }
                else if ( i==5 )  {
                    return ( myToLower( vec->getNomeBrano() ) == titoloLower && myToLower( vec->getAlbumBrano() ) == albumLower );
                }
                else if ( i==4 )    {
                    return ( myToLower( vec->getAlbumBrano() ) == albumLower );
                }
                else if ( i==3 )    {
                    return ( myToLower( vec->getNomeBrano() ) == titoloLower && myToLower( vec->getArtista() ) == artistaLower);
                }
                else if ( i==2 )    {
                    return ( myToLower( vec->getArtista() ) == artistaLower );
                }
                else if ( i==1 )    {
                    return (myToLower( vec->getNomeBrano() ) == titoloLower );
                }
            default:
                return false;
            }
        }
    };


    QVector<Brano*> cercaBrano(QString titolo ="", QString artista ="", QString album ="");
    QVector<Utente*> cercaUtente(QString email="", QString nome="", QString cognome="");

    Utente* findUser(QString email);


private:
    static QString myToLower(QString input);



};

#endif // SESSIONE_H
