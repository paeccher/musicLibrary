#ifndef DURATA_H
#define DURATA_H

#include<iostream>
#include<QString>

class Durata	{
	private:
		unsigned int secondi;
	public:
		Durata(int=0, int=0);
		unsigned int getMinuti() const;
		unsigned int getSecondi() const;
        static QString toQString(Durata d);
};

std::ostream& operator<<(std::ostream& os, const Durata& d);

#endif
