#include "container.h"
//#include"utente.h"

Container::Container()  {
  //  loadTracks();
}

Container::~Container() {
    //deleteroni utenti
}


//QList<Utente*>::iterator Container::getBeginUsersList() {}

//QList<Utente*>::iterator Container::getEndUsersList()   {}
/*
bool Container::login(const QString& email, const QString& password) const   {
    bool riuscito=false;
    for ( QList<Utente*>::const_iterator it=accountList.begin() ; it != accountList.end() && !riuscito  ; it++ ) {
        if ( (*it)->getEmail()==email && (*it)->getPassword()==password )   {
            riuscito=true;
        }   
    }

    if( riuscito )  {
        std::cout<<"login riuscito"<<std::endl;
        return riuscito;
    }   else    {
        std::cout<<"login non riuscito"<<std::endl;
        return riuscito;
    }
}
*/
