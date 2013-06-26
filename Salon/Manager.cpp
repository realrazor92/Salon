#include "Manager.h"

Manager::Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short czas, const unsigned int podwladni)
	:Osoba(imie,nazwisko,telefon), Wynagrodzenie(wynagrodzenie), CzasPracy(czas), IloscPodwladnych(podwladni)
{
	if(wynagrodzenie < 0 || czas < 0 || podwladni < 0)
	{
		throw UjemnaWartosc();
	}
}

std::ostream & operator <<(std::ostream &Strumien, const Manager &M)
{
	Strumien <<M.Imie<<" "<<M.Nazwisko<<" "<<M.Dataur<< " "<< M.Telefon <<" "<< M.Wynagrodzenie <<" "<<M.CzasPracy <<" "<<M.IloscPodwladnych<<std::endl; 
	return Strumien;
}