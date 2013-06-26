#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"
#include "Samochod.h"

class Pracownik : public Osoba
{
private:
	unsigned short int CzasPracy;
	std::vector<Samochod> SprzedaneSamochody;
public:
	Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int czas, const unsigned int sprzedane);
	double NalezneWynagrodzenie();
	static void ZwiekszID(static int &ID);
	friend std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P);
	const char * getType(){	return typeid(this).name();}
	void SprzedajSamochod(Samochod &S);
	
};
