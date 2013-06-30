#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"
#include "Samochod.h"
class Manager : public Osoba
{
private:
	unsigned short int IloscPodwladnych;
	double Wynagrodzenie;
	unsigned short int CzasPracy;
	std::vector<Samochod> SprzedaneSamochody;
public:
	Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short int czas, const unsigned int podwladni);
	double NalezneWynagrodzenie();
	void SprzedajSamochod(Samochod &S);
	friend std::ostream & operator <<(std::ostream &Strumien, const Manager &M);
	const char * getType(){	return typeid(this).name();}
	void Wyswietl() const;
	void SprzedajSamochod(SprzedanySamochod &S){}
};
