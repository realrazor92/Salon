#include "Osoba.h"

Osoba::Osoba(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short dzien, const unsigned short miesiac, const unsigned short rok)
	:Imie(imie), Nazwisko(nazwisko), Telefon(telefon), Dataur(dzien, miesiac, rok)
{}

/*
std::ostream & operator << (std::ostream &Strumien, const Osoba &O)
{
	
	Strumien << std::setfill(' ') << std::setw(10) << O.Imie << std::setfill(' ') << std::setw(12) << O.Nazwisko <<", tel.: "<< std::setfill(' ') << std::setw(9) << O.Telefon << ", urodzony: " << O.Dataur; 
	return Strumien;
	
}
*/