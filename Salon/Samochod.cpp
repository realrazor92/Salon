#include "Samochod.h"

Samochod::Samochod(const double masaPojazdu, const double masaDopuszczalna, const double cena, const std::string marka, 
				   const std::string model, const Rodzaj naped, const Typ nadwozie)
{
	if(masaPojazdu < 0 || masaDopuszczalna < 0 || cena < 0)
	{
		throw UjemnaWartosc();
	}
	else
	{
		MasaPojazdu=masaPojazdu;
		MasaDopuszczalna=masaDopuszczalna;
		Cena=cena;
		Marka=marka;
		Model=model;
		Naped=naped;
		Nadwozie=nadwozie;
	}
}

std::ostream & operator <<(std::ostream &Strumien, const Typ &T)
{
	if(T==Hatchback) Strumien<<"Hatchback";
	if(T==Sedan) Strumien<<"Sedan";
	if(T==Kombi) Strumien<<"Kombi";
	if(T==SUV) Strumien<<"SUV";
	if(T==Dostawczy) Strumien<<"Dostawczy";
	return Strumien;
}

std::ostream & operator <<(std::ostream &Strumien, const Rodzaj &R)
{
	if(R==Przód) Strumien<<"Przód";
	if(R==Ty³) Strumien<<"Ty³";
	if(R==Obie_osie) Strumien<<"4x4";	//Obie_osie
	return Strumien;
}

std::string Przecinki (std::string bufor)
{
	size_t pos = bufor.find(",");
	if( pos == std::string::npos )
		return bufor;
	else
	{
		std::string przecinek = "\",\"";
		std::string temp1 = bufor.substr(0,pos);
		std::string temp2 = bufor.substr(pos+1,bufor.size());
		bufor.clear();
		bufor=temp1 + przecinek + temp2;
		return bufor;
	}
}

std::ostream & operator <<(std::ostream &Strumien, const Samochod &S)
{
	
	Strumien
		<<Przecinki(S.Marka)<<","									//Marka
		<<Przecinki(S.Model)<<","									//Model
		<<S.Nadwozie<<","											//Nadwozie
		<<S.Naped<<","												//Naped
		<<S.MasaPojazdu<<","										//Masa
		<<S.MasaDopuszczalna<<","									//Masa dopuszczalna
		<<S.Cena;													//Cena

	return Strumien;
}
/*
std::ostream & operator <<(std::ostream &Strumien, const Samochod &S)
{
Strumien<<std::setw(13)<<S.Marka<<", "												//Marka
<<std::setw(13)<<S.Model<<", "												//Model
<<std::setw(9)<<S.Nadwozie<<", "											//Nadwozie
<<std::setw(6)<<S.Naped<<", "												//Naped
<<std::setw(5)<<std::fixed<<std::setprecision(0)<<S.MasaPojazdu<<", "		//Masa
<<std::setw(7)<<std::fixed<<std::setprecision(0)<<S.MasaDopuszczalna<<", "	//Masa dopuszczalna
<<std::setw(7)<<std::fixed<<std::setprecision(2)<<S.Cena<<" zl";			//Cena
return Strumien;
}
*/