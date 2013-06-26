#include "Pracownik.h"

Pracownik::Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int czas, const unsigned int sprzedane)
:Osoba(imie,nazwisko,telefon), CzasPracy(czas), SprzedaneSamochody(sprzedane)
{

}

std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P)
{
	Strumien <<P.Imie<<" "<<P.Nazwisko<<" "<<P.Dataur<< " "<<P.Telefon <<" "<< P.CzasPracy <<" "<<P.SprzedaneSamochody<<std::endl; 
	return Strumien;
}
double Pracownik::NalezneWynagrodzenie()
{
	return 1;
}
