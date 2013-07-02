#include "Pracownik.h"

Pracownik::Pracownik(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int dzien,
					 const unsigned short int miesiac, const unsigned short int rok, const unsigned short int id, const unsigned short int czas
					 /*, const unsigned int sprzedane*/)
					 :Osoba(imie,nazwisko,telefon,dzien,miesiac,rok), ID(id), CzasPracy(czas)/*, SprzedaneSamochody(sprzedane)*/
{
		if(ID < 0 || czas < 0)
	{
		throw UjemnaWartosc();
	}
}

double Pracownik::NalezneWynagrodzenie()
{
	double SumaSprzedazy = 0;
	unsigned short int StawkaGodzinna = 10;
	double PremiaZaSprzedaz = 0.01;
	Wynagrodzenie = 0;

	for(int i = 0 ; i < SprzedaneSamochody.size(); ++i)
	{
		SumaSprzedazy += SprzedaneSamochody[i].getCena();
	}
	Wynagrodzenie = (CzasPracy * StawkaGodzinna) + (SumaSprzedazy * PremiaZaSprzedaz);
	return Wynagrodzenie;
}
void Pracownik::SprzedajSamochod(SprzedanySamochod &S)
{
	SprzedaneSamochody.push_back(S);
}

std::ostream & operator <<(std::ostream &Strumien, const Pracownik &P)	//TODO: do zmiany!!!
{
	Strumien <<P.Imie<<" "<<P.Nazwisko<<" "<<P.Dataur<< " "<<P.Telefon <<" "<< P.CzasPracy;

	for(int i = 0 ; i < P.SprzedaneSamochody.size() ; ++i)
	{
		Strumien<<P.SprzedaneSamochody[i];
	}

	Strumien<<std::endl; 
	return Strumien;
}

void  Pracownik::Wyswietl()const
{
	std::cout<<std::setw(10)<<Imie<<" "
			 <<std::setw(10)<<Nazwisko<<" "
			 <<std::setw(10)<<Dataur<<" "
			 <<std::setfill(' ')<<std::setw(9)<<Telefon<<" "
  			 <<std::setfill(' ')<<std::setw(4)<<CzasPracy<<" "
			 <<std::setfill(' ')<<std::setw(4)<<ID<<" "
			 <<std::setw(12)<<std::setfill(' ')<<" "
			 <<std::setfill(' ')<<std::setw(14)<<std::fixed<<std::setprecision(2)<<Wynagrodzenie<<" ";
}
