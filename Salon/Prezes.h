#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"

class Prezes : public Osoba
{
private:
	double Wynagrodzenie;
	unsigned short int CzasPracy;
public:
	Prezes(const std::string imie, const std::string nazwisko , const std::string telefon, const double wynagrodzenie, const unsigned short int czas);
	double NalezneWynagrodzenie();
	friend std::ostream & operator <<(std::ostream &Strumien, const Prezes &P);
	const char * getType(){	return typeid(this).name();}
	void Wyswietl() const;
	void SprzedajSamochod(SprzedanySamochod &S){}
};
