#include "Klient.h"

Klient::Klient(const std::string imie , const std::string nazwisko , const std::string telefon , const double zasob)
	:Osoba(imie, nazwisko, telefon), ZasobGotowki(zasob)
{
	if(zasob < 0)
	{
		throw UjemnaWartosc();	//Nie wiem co si� pierwsze wykona, czy najpierw stworzy obiekt i dopiero potem zwr�ci b��d
								//je�eli taki b�dzie czy najpierw rzuci UjemnaWartosc().
	}
}

std::ostream & operator <<(std::ostream &Strumien, const Klient &K)
{
	Strumien <<K.Imie<<" "<<K.Nazwisko<<" "<<K.Dataur<< " "<<K.Telefon <<" "<< K.ZasobGotowki<<std::endl; 
	return Strumien;
}