#include "Data.h"
#include "BlednaWartosc.h"

Data::Data(const unsigned short int dzien, const unsigned short int miesiac, const unsigned short int rok): Dzien(dzien), Miesiac(miesiac), Rok(rok)
{
	if(rok > 2013 || rok<1900)
		throw BlednaWartosc();

	if(miesiac > 12)
		throw BlednaWartosc();

	if((( rok%4==0 || (rok%100!=0 && rok%400==0)) && miesiac==2 && dzien>29) || (miesiac == 2 && dzien > 28) || ((miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) && dzien >30) || (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12) && dzien > 31)
		throw BlednaWartosc();
}

std::ostream & operator << (std::ostream &Strumien, const Data &D)
{
	Strumien << std::setw(4) << D.Rok << "-" << std::setfill('0') << std::setw(2) << D.Miesiac << "-" << std::setw(2) << D.Dzien;
	return Strumien;
}