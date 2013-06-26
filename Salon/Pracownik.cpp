#include "Pracownik.h"

Pracownik::Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short int czas, const unsigned int sprzedane)
:Osoba(imie,nazwisko,telefon), Wynagrodzenie(wynagrodzenie), CzasPracy(czas), SprzedaneSamochody(sprzedane)
{
	if(wynagrodzenie < 0 || czas < 0 || sprzedane < 0)
	{
		throw UjemnaWartosc();
	}
}

std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P)
{
	Strumien <<P.Imie<<" "<<P.Nazwisko<<" "<<P.Dataur<< " "<<P.Telefon <<" "<< P.CzasPracy <<" "<<P.Wynagrodzenie<<" "<<
		P.SprzedaneSamochody<<std::endl; 
	return Strumien;
}
