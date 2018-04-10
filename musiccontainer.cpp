#include "musiccontainer.h"


vector<Brano*> MusicContainer::aggiungiBrano(Brano* b)	{
	//std::cout<<"b= "<<b<<std::endl;
	vettoreDeiBrani.push_back(b);
	return vettoreDeiBrani;
}


void MusicContainer::printTitoliCanzoni() const	{
	int i=1;
	for ( vector<Brano*>::const_iterator it=vettoreDeiBrani.begin() ; it != vettoreDeiBrani.end() ; ++it , i++ )	{
		std::cout<<i<<") "<<(*it)->getNomeBrano()<<" - "<<(*it)->getArtista()<<std::endl;
	}
}

double MusicContainer::dimensioneContainer() const {
	double dim;
	for ( vector<Brano*>::const_iterator it=vettoreDeiBrani.begin() ; it != vettoreDeiBrani.end() ; ++it )	{
		dim+=(*it)->getDimensioneBrano	();
	}
	return dim;
}

vector<Brano*>::const_iterator MusicContainer::getBegin() const {
 	return vettoreDeiBrani.begin();
}
vector<Brano*>::const_iterator MusicContainer::getEnd() const {
 	return vettoreDeiBrani.end();
}