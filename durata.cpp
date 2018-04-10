
#include "durata.h"

		
Durata::Durata(int min, int sec) : secondi(min*60+sec) {};


unsigned int Durata::getMinuti() const	{
	return (secondi/60);
}
unsigned int Durata::getSecondi() const	{
	return (secondi%60);
}

std::ostream& operator<< (std::ostream& os, const Durata& d)	{
	if ( d.getSecondi()>9 )	{
		os<<d.getMinuti()<<":"<<d.getSecondi();
	} else	{
		os<<d.getMinuti()<<":0"<<d.getSecondi();
	}
}

QString Durata::toQString(Durata d) {
    QString output ;
    QString min, sec;
    if ( d.getSecondi()>9 )	{
        min= QString::number(d.getMinuti());
        sec= QString::number(d.getSecondi());
        output.append( min );
        output.append(":");
        output.append( sec );
    } else	{
        min= QString::number( d.getMinuti() );
        sec= QString::number( d.getSecondi() );
        output.append( min );
        output.append(":0");
        output.append( sec );
    }
    return output;

}
