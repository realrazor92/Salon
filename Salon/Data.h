#pragma once
#include "Biblioteki.h"

class Data
{
public:
	unsigned short int Dzien;
	unsigned short int Miesiac;
	unsigned short int Rok;
	Data(const unsigned short int dzien=1, const unsigned short int miesiac=1, const unsigned short int rok=1900);
	friend std::ostream & operator << (std::ostream &Strumien, const Data &D);
};