#include "Manager.h"

Manager::Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short czas, const unsigned int podwladni)
	:Osoba(imie,nazwisko,telefon), Wynagrodzenie(wynagrodzenie), CzasPracy(czas), IloscPodwladnych(podwladni)
{
	if(wynagrodzenie < 0 || czas < 0 || podwladni < 0)
	{
		throw UjemnaWartosc();
	}
}
void Manager::SprzedajSamochod(Samochod &S)
{
	SprzedaneSamochody.push_back(S);
}
double Manager::NalezneWynagrodzenie()
{
	double SumaSprzedazy = 0;
	unsigned short int StawkaGodzinna = 12;
	double PremiaZaSprzedaz = 0.01;
	unsigned short int BonusZaPodwladnego = 50;

	for(int i = 0 ; i < SprzedaneSamochody.size(); ++i)
	{
		SumaSprzedazy += SprzedaneSamochody[i].getCena();
	}

	return (CzasPracy * StawkaGodzinna) + (SumaSprzedazy * PremiaZaSprzedaz) + (IloscPodwladnych * BonusZaPodwladnego);
}
std::ostream & operator <<(std::ostream &Strumien, const Manager &M)
{
	Strumien <<M.Imie<<" "<<M.Nazwisko<<" "<<M.Dataur<< " "<< M.Telefon <<" "<< M.Wynagrodzenie <<" "<<M.CzasPracy <<" "<<M.IloscPodwladnych<<std::endl; 
	return Strumien;
}