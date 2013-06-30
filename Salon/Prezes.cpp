#include "Prezes.h"

Prezes::Prezes(const std::string imie, const std::string nazwisko , const std::string telefon, const double wynagrodzenie, const unsigned short int czas)
	:Osoba(imie , nazwisko , telefon), Wynagrodzenie(wynagrodzenie), CzasPracy(czas)
{
	if(wynagrodzenie < 0 || czas < 0)
	{
		throw UjemnaWartosc();
	}

}
double Prezes::NalezneWynagrodzenie()
{
	unsigned short int StawkaGodzinowa = 15;
	Wynagrodzenie += CzasPracy * StawkaGodzinowa;
	return Wynagrodzenie;
}
std::ostream & operator <<(std::ostream &Strumien, const Prezes &P)
{
	Strumien <<P.Imie<<" "<<P.Nazwisko<<" "<<P.Dataur<< " "<<P.Telefon <<" "<< P.CzasPracy <<" "<<P.Wynagrodzenie<<std::endl; 
	return Strumien;
}

void Prezes::Wyswietl() const
{

}