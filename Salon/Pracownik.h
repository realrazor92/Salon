#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"

class Pracownik : public Osoba
{
private:
	//dla pracownika mozna by dorobic jeszcze klase pesel
	unsigned short int CzasPracy;
	unsigned short int SprzedaneSamochody;
public:
	Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int czas, const unsigned int sprzedane);
	double NalezneWynagrodzenie();
	static void ZwiekszID(static int &ID);
	friend std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P);
	const char * getType(){	return typeid(this).name();}
	
};
