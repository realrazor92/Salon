#pragma once
#include "Biblioteki.h"
#include "Data.h"

class Osoba
{
protected:
	std::string Imie;
	std::string Nazwisko;
	std::string Telefon;
	Data Dataur;
public:
	Osoba(const std::string imie=" ", const std::string nazwisko=" ", const std::string telefon=" ", const unsigned short int dzien=1, const unsigned short int miesiac=1, const unsigned short int rok=1900);
	//friend std::ostream & operator << (std::ostream &Strumien, const Osoba &O);
	virtual const char * getType()=0;
	virtual void Wyswietl()const =0;
};
