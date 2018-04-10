#ifndef CONTAINER_H
#define CONTAINER_H

#include<fstream>
#include<QXmlStreamReader>
#include<QList>
#include<QSharedPointer>
#include<QString>

#include"brano.h"

//class Utente;

class Container
{
private:
    //lista o QVector accounts
    //QList<Utente*> accountList;

    void readInput(std::string);

public:
    Container();
    ~Container();
    //QList<Utente*>::iterator getBeginUsersList();
    //QList<Utente*>::iterator getEndUsersList();

   // bool login(const QString &, const QString&) const;
};

#endif // CONTAINER_H
