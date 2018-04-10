#include "album.h"

Album::Album(QString art, QString anno, QString genere, int ntracce, int m, int s, double dim):
			artista(art),
			annoAlbum(anno),
			genereAlbum(genere),
			numeroTracceAlbum(ntracce),
			durataAlbum(m, s),
			dimensioneAlbum(dim)
			{};

void Album::aggiungiBranoAdAlbum(Brano* ptr)	{
	listaTracce.push_back(ptr)
;
}
QString Album::getAnnoAlbum() const	{
	return annoAlbum;
}			
QString Album::getGenereAlbum() const	{
	return genereAlbum; 
}
double Album::getDimensioneAlbum() const	{
	return dimensioneAlbum;
}
Durata Album::getDurataAlbum() const	{
	return durataAlbum;
}
