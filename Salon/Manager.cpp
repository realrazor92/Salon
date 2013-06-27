#include "Manager.h"

Manager::Manager(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, 
				 const unsigned short czas, const unsigned int podwladni)
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

void Manager::Wyswietl() const
{
	std::cout<<std::setw(10)<<Imie<<" "
			 <<std::setw(10)<<Nazwisko<<" "
			 <<std::setw(10)<<Dataur<<" "
			 <<std::setfill(' ')<<std::setw(9)<<Telefon<<" "
  			 <<std::setfill(' ')<<std::setw(4)<<CzasPracy<<" "
			 <<std::setfill(' ')<<std::setw(4)<<""<<" "
			 <<std::setfill(' ')<<std::setw(11)<<IloscPodwladnych<<" "
			 <<std::setfill(' ')<<std::setw(14)<<std::fixed<<std::setprecision(2)<<Wynagrodzenie<<" "<<std::endl;

	//std::cout<<Imie<<" "<<Nazwisko<<" "<<Dataur<<" "<<Telefon<<" "<<IloscPodwladnych<<" "<<CzasPracy<<" "<<Wynagrodzenie<<std::endl;
}