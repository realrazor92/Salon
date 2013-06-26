#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"

class Manager : public Osoba
{
	unsigned short int IloscPodwladnych;
	double Wynagrodzenie;
	unsigned short int CzasPracy;
public:
	Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short int czas, const unsigned int podwladni);
	//w tej klasie trzeba jeszcze cos wymyslec... narazie zostawiam same klasy w konstruktorami, metody wymyslimy pozniej
	friend std::ostream & operator <<(std::ostream &Strumien, const Manager &M);
	const char * getType(){	return typeid(this).name();}
};
