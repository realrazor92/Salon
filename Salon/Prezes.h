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
	unsigned short int GetID() const {return 0;}
	std::string getImie() {return Imie;}
	std::string getNazwisko() {return Nazwisko;}
	std::string getTelefon() {return Telefon;}
	Data getDataur() {return Dataur;}
	unsigned short int getCzasPracy() {return CzasPracy;}
	double getWynagrodzenie() {return Wynagrodzenie;}
	unsigned short int getIloscPodwladnych() {return 0;}
};
