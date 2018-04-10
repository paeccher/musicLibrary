#include "sessione.h"

Sessione::Sessione()  {

    loadTracks();
    loadUsers();
    //loadPlaylistOfUser();

}

Brano* Sessione::find(QString title)   {
    for ( QVector<Brano*>::const_iterator it=tracksVector.constBegin() ; it != tracksVector.constEnd() ; it++ )    {
        if ( (*it)->getNomeBrano() == title )  {
            return *(it);
        }
    }
}

QVector<Brano*> Sessione::cercaBrano( QString titolo, QString artista, QString album)   {
    int type;
    if ( ptr->getTipologiaAbbonamento() == "Free" ) {
        type=0;
    } else if ( ptr->getTipologiaAbbonamento() == "Silver" ) {
        type=1;
    } else if ( ptr->getTipologiaAbbonamento() == "Gold" || ptr->getTipologiaAbbonamento() == "Admin" )  {
        type=2;
    } else {
        type=3;
    }
    switch (type)   {
        case ( 0 ) :
        {
            funtoreRicerca sf(1);
            QVector<Brano*> toRet;
            for ( QVector<Brano*>::const_iterator it = tracksVector.begin() ;  it != tracksVector.end() ; it++ )	{
                if ( sf( *it, titolo, artista, album) )	{
                    toRet.push_back(*it);
                }
            }
            return toRet;
        }
        case ( 1 ):
        {
            funtoreRicerca sf(2);
            QVector<Brano*> toRet;
            for ( QVector<Brano*>::const_iterator it = tracksVector.begin() ;  it != tracksVector.end() ; it++ )	{
                if ( sf( *it, titolo, artista, album) )	{
                    toRet.push_back(*it);
                }
            }
            return toRet;
        }
        case ( 2 ):
        {
            funtoreRicerca sf(3);
            QVector<Brano*> toRet;
            for ( QVector<Brano*>::const_iterator it = tracksVector.begin() ;  it != tracksVector.end() ; it++ )	{
                if ( sf( *it, titolo, artista, album) )	{
                    toRet.push_back(*it);
                }
            }
            return toRet;
        }
        default:
        {
            QVector<Brano*> toRet;
            return toRet;
        }
    }
}

QVector<Utente*> Sessione::cercaUtente(QString email, QString nome, QString cognome) {
    QString emailLower=myToLower(email);
    QString nomeLower=myToLower(nome);
    QString cognomeLower=myToLower(cognome);
    int it=0;
    if ( email!="" )   {
        it=it+1;
    }
    if ( nome!="" )  {
        it=it+2;
    }
    if ( cognome!="" )    {
        it=it+4;
    }

    QVector<Utente*> toReturn;
    for ( int i = 0 ; i < usersVector.size() ; i++ )    {
        if ( it==7 )   {
            if ( myToLower( usersVector[i]->getEmail() ) == emailLower && myToLower( usersVector[i]->getNome() ) == nomeLower
                                                                       && myToLower( usersVector[i]->getCognome() ) == cognomeLower )   {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==6 )  {
            if ( myToLower( usersVector[i]->getNome() ) == nomeLower && myToLower( usersVector[i]->getCognome() ) == cognomeLower )    {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==5 )  {
            if ( myToLower( usersVector[i]->getEmail() ) == emailLower && myToLower( usersVector[i]->getCognome() ) == cognomeLower )   {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==4 )    {
            if ( myToLower( usersVector[i]->getCognome() ) == cognomeLower ) {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==3 )    {
            if ( myToLower( usersVector[i]->getNome() ) == nomeLower && myToLower( usersVector[i]->getEmail() ) == emailLower )   {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==2 )    {
            if ( myToLower( usersVector[i]->getNome() ) == nomeLower )   {
                toReturn.push_back( usersVector[i] );
            }
        }
        else if ( it==1 )    {
            if ( myToLower( usersVector[i]->getEmail() ) == emailLower )   {
                toReturn.push_back( usersVector[i] );
            }
        }
    }
    return toReturn;
}

void Sessione::addTrack(QString title,QString artist,QString album,QString genre,QString minutes,QString seconds,QString dimension ,QString year ) {

}

QString Sessione::myToLower (QString input)	{
    QString qOutput;
    for ( int i = 0 ; i < input.length() ; ++i )	{
        QChar inputChar=(input[i]);
        QChar inputCharLowered=inputChar.QChar::toLower() ;
        qOutput.push_back(inputCharLowered) ;
    }
    return qOutput;
}

void Sessione::setType(QString type)  {
    tipo=type;
}

void Sessione::loadTracks()   {
    DIR* dir;
    struct dirent *ent;

    QString p="tracks/";
    const char* path = p.toLatin1();
    std::string path1 = p.toStdString();
    dir = opendir(path);

    if ( dir != NULL )  {
        while ( (ent = readdir(dir)) != NULL )  {
            if ( strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 )   {
                std::string line, titolo, autore, genere, anno, album;
                double dimensione;
                int min=0, sec=0;
                std::fstream in;
                std::string pp=ent->d_name;
                path1.append(pp);
                in.open( path1 );
                if ( in )   {
                    while ( getline( in, line ) ) {
                        for ( int i = 0 ; i < 8 && !in.eof() ; i++ )    {
                            getline(in, line);
                            switch(i)   {
                                case 0 :
                                    titolo=line;
                                    break;

                                case 1 :
                                    autore=line;
                                    break;

                                case 2 :
                                    {
                                    std::string aux=line;
                                    const char* c=aux.c_str();
                                    //dimensione = atof(aux.c_str());
                                    dimensione = std::strtod(c, NULL);
                                    break;
                                    }

                                case 3 :
                                    {
                                    std::string aux=line;
                                    min=std::stoi(aux);
                                    break;
                                    }

                                case 4 :
                                    {
                                    std::string aux=line;
                                    sec=std::stoi(aux);
                                    break;
                                    }

                                case 5 :
                                    genere=line;
                                    break;

                                case 6 :
                                    anno=line;
                                    break;

                                case 7:
                                    album=line;
                                    break;
                                default:
                                    break;

                            }
                        }
                        Brano* brano = new Brano( /*QString::fromStdString(bid),*/
                                                  QString::fromStdString(titolo),
                                                  QString::fromStdString(autore),
                                                  QString::fromStdString(album),
                                                  dimensione,
                                                  min, sec,
                                                  QString::fromStdString(genere),
                                                  QString::fromStdString(anno)  );

                        tracksVector.push_back(brano);
                        int size=pp.size();
                        path1.erase( path1.size()-size, path1.size() );
                    }
                }
            }
        }
    }
}


void Sessione::loadUsers()  {

    DIR* dir;
    struct dirent *ent;

    QString p="users/";
    const char* path = p.toLatin1();
    std::string path1 = p.toStdString();
    dir = opendir(path);
    if ( dir != NULL )  {
        while ( (ent = readdir(dir)) != NULL )  {
            if ( strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 )   {
                std::fstream in;
                std::string pp=ent->d_name;
                QString qemail, psw, type, nome, cognome;
                path1.append(pp);
                in.open( path1 );
                if ( in )   {
                    std::string line, text;
                    int i=0;
                    for ( int i = 0 ; i < 5 ; i ++ )    {
                        getline(in, line);
                        switch ( i )    {
                        case 0 :
                            qemail=QString::fromStdString(line);
                            break;
                        case 1 :
                            psw=QString::fromStdString(line);
                            break;
                        case 2 :
                            type=QString::fromStdString(line);
                            break;
                        case 3 :
                            nome=QString::fromStdString(line);
                            break;
                        case 4:
                            cognome=QString::fromStdString(line);
                            break;
                        }
                    }
                    Utente* user;
                    if ( type == "Free")    {
                        user = new UtenteFree( nome, cognome, qemail, psw, false, 5 );
                    } else if ( type == "Silver" )  {
                        user = new UtenteSilver( nome, cognome, qemail, psw, false, 10 );
                    } else if ( type == "Gold" )    {
                        user = new UtenteGold( nome, cognome, qemail, psw, true, 0 );
                    } else if ( type == "Admin" )   {
                        user = new UtenteAdmin( nome, cognome, qemail, psw, true, 0 );
                    }
                    usersVector.push_back(user);
                    int size=pp.size();
                    path1.erase( path1.size()-size, path1.size() );
                }


            }
        }
   }
}

void Sessione::removeUser(QString email)  {
    QString p="users/";
    p.append(email);
    const char* path= p.toLatin1();
    if ( remove(path) !=0 )    {
        //QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione non riuscita!"), tr("Errore!"), QMessageBox::Ok, this);
        //fail->show();
    }
}
void Sessione::removeTrack(QString bid) {

    DIR* dir;
    struct dirent *ent;
    QString p="tracks/";
    const char* path = p.toLatin1();
    std::string path1 = p.toStdString(), line;
    dir = opendir(path);

    if ( dir != NULL )  {
        while ( (ent = readdir(dir)) != NULL )  {
            if ( strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 )   {
                std::fstream in;
                std::string pp=ent->d_name;
                std::string first, second;

                path1.append(pp);
                const char* pathToDelete=path1.c_str();
                in.open( path1 );
                if ( in )   {
                    getline(in, line);
                    first = line;
                    getline(in, line);
                    second = line;
                    if ( first=="" && second==bid.toStdString() )   {
                        std::cout<<first<<endl<<bid.toStdString();
                        in.close();
                        remove( pathToDelete );
                    }
                }
                int size=pp.size();
                path1.erase( path1.size()-size, path1.size() );
            }
        }
    }
}



bool Sessione::checkAdmin(QString email)    {
    Utente* usr=findUser(email);
    return usr->getTipologiaAbbonamento()=="Admin";
}

Utente* Sessione::findUser(QString email)   {
    for ( int i = 0 ; i < usersVector.size() ; i++ )    {
        if ( usersVector[i]->getEmail() == email )  {
            return usersVector[i];
        }
    }

    return nullptr;
}


QString Sessione::getType() {
    return tipo;
}

Utente* Sessione::getPtr()  {
    return ptr;
}

void Sessione::setPtr(Utente *p) {
    ptr=p;
}

QString Sessione::matchIdTitolo(QString id) {
    for ( QVector<Brano*>::const_iterator it=tracksVector.constBegin() ; it != tracksVector.constEnd() ; it++ )    {
        if ( (*it)->getNomeBrano() == id )  {

            QString toReturn=(*it)->getNomeBrano();
            return toReturn;
        }
    }
}
