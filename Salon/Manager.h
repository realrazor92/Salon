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
	unsigned short int ID;
	unsigned short int CzasPracy;
	std::vector<SprzedanySamochod> SprzedaneSamochody;
public:
	Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int dzien,
		const unsigned short int miesiac, const unsigned short int rok, const unsigned short int id, const unsigned short int czas, const unsigned int podwladni);
	double NalezneWynagrodzenie();
	void SprzedajSamochod(SprzedanySamochod &S);
	friend std::ostream & operator <<(std::ostream &Strumien, const Manager &M);
	const char * getType(){	return typeid(this).name();}
	unsigned short int GetID() const {return ID;}
	void Wyswietl() const;
	int SprzedaneSamochody_Size() {return SprzedaneSamochody.size();}
	SprzedanySamochod getSprzedanySamochod(unsigned short int i) {return SprzedaneSamochody[i];}
};
