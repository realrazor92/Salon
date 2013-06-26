#include "Pracownik.h"

Pracownik::Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int czas, const unsigned int sprzedane)
:Osoba(imie,nazwisko,telefon), CzasPracy(czas), SprzedaneSamochody(sprzedane)
{

}

double Pracownik::NalezneWynagrodzenie()
{
	double SumaSprzedazy = 0;
	unsigned short int StawkaGodzinna = 10;
	double PremiaZaSprzedaz = 0.01;

	for(int i = 0 ; i < SprzedaneSamochody.size(); ++i)
	{
		SumaSprzedazy += SprzedaneSamochody[i].getCena();
	}

	return (CzasPracy * StawkaGodzinna) + (SumaSprzedazy * PremiaZaSprzedaz);
}
void Pracownik::SprzedajSamochod(Samochod &S)
{
	SprzedaneSamochody.push_back(S);
}
std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P)
{
	Strumien <<P.Imie<<" "<<P.Nazwisko<<" "<<P.Dataur<< " "<<P.Telefon <<" "<< P.CzasPracy;

	for(int i = 0 ; i < P.SprzedaneSamochody.size() ; ++i)
	{
	Strumien<<P.SprzedaneSamochody[i];
	}
	Strumien<<std::endl; 
	return Strumien;
}

