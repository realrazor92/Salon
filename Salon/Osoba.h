#pragma once
#include "Biblioteki.h"
#include "Data.h"
#include "SprzedanySamochod.h"

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
	virtual double NalezneWynagrodzenie() = 0;
	virtual const char * getType()=0;
	virtual void Wyswietl()const =0;
	virtual unsigned short int GetID() const = 0;
	virtual void SprzedajSamochod(SprzedanySamochod &S) = 0;
	virtual std::string getImie() = 0;
	virtual std::string getNazwisko() = 0;
	virtual std::string getTelefon() = 0;
	virtual Data getDataur() = 0;
	virtual unsigned short int getCzasPracy() =0;
	virtual double getWynagrodzenie() = 0;
	virtual unsigned short int getIloscPodwladnych() = 0;
};
