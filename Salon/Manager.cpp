#include "Manager.h"

Manager::Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short int dzien,
				 const unsigned short int miesiac, const unsigned short int rok, const unsigned short int id, const unsigned short int czas, const unsigned int podwladni)
:Osoba(imie,nazwisko,telefon,dzien,miesiac,rok), ID(id) , CzasPracy(czas), IloscPodwladnych(podwladni)
{
	if(czas < 0 || podwladni < 0 || id < 0)
	{
		throw UjemnaWartosc();
	}
}
void Manager::SprzedajSamochod(SprzedanySamochod &S)
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
	Wynagrodzenie = (CzasPracy * StawkaGodzinna) + (SumaSprzedazy * PremiaZaSprzedaz) + (IloscPodwladnych * BonusZaPodwladnego);
	return Wynagrodzenie;
}

std::ostream & operator <<(std::ostream &Strumien, const Manager &M)
{
	Strumien <<M.Imie<<" "<<M.Nazwisko<<" "<<M.Dataur<< " "<< M.Telefon <<" "<< M.ID <<" "<<M.CzasPracy <<" "<<M.IloscPodwladnych<<std::endl; 
	return Strumien;
}

void Manager::Wyswietl() const
{
	std::cout<<std::setw(10)<<Imie<<" "
			 <<std::setw(10)<<Nazwisko<<" "
			 <<std::setw(10)<<Dataur<<" "
			 <<std::setfill(' ')<<std::setw(9)<<Telefon<<" "
  			 <<std::setfill(' ')<<std::setw(4)<<CzasPracy<<" "
			 <<std::setfill(' ')<<std::setw(4)<<ID<<" "
			 <<std::setfill(' ')<<std::setw(11)<<IloscPodwladnych<<" "
			 <<std::setfill(' ')<<std::setw(14)<<std::fixed<<std::setprecision(2)<<Wynagrodzenie<<" "<<std::endl;
}