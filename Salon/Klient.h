#pragma once
#include "Biblioteki.h"
#include "Osoba.h"
#include "UjemnaWartosc.h"

class Klient : public Osoba
{
private:
	double ZasobGotowki;
public:
	Klient(const std::string imie, const std::string nazwisko, const std::string telefon, const double zasob);
	friend std::ostream & operator <<(std::ostream &Strumien, const Klient &K);
	const char * getType(){	return typeid(this).name();}
};