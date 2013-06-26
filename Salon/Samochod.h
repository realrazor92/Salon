#pragma once
#include "Biblioteki.h"
#include "UjemnaWartosc.h"

enum Typ
{
	Hatchback =0,
	Sedan = 1,
	Kombi =2,
	SUV = 3,
	Dostawczy = 4
};

std::ostream & operator <<(std::ostream &Strumien, const Typ &T);


enum Rodzaj
{
	Przód = 0,
	Ty³ = 1,
	Obie_osie = 2
};

std::ostream & operator <<(std::ostream &Strumien, const Rodzaj &R);

class Samochod
{
private:
	//proponowa³bym zrobic enum, ktory bedzie obs³ugiwa³ rodzaj napêdu, na przód, na ty³ i 4x4
	double MasaPojazdu;
	double MasaDopuszczalna;
	double Cena;
	std::string Marka;
	std::string Model;
	Rodzaj Naped;
	Typ Nadwozie;	//Myœle, ¿e nie ma sensu robiæ osobnych klas dla ka¿dego typu nadwozia dlatego zrobi³em tak.
public:
	Samochod(const double masaPojazdu=0 , const double masaDopuszczalna=0 , const double cena=0 , const std::string marka=" ", const std::string model=" ", const Rodzaj naped=Przód, const Typ nadwozie=Hatchback);
	friend std::ostream & operator <<(std::ostream &Strumien, const Samochod &S);
	std::string getMarka() {return Marka;}
	std::string getModel() {return Model;}
	Rodzaj getNaped() {return Naped;}
	Typ getNadwozie() {return Nadwozie;}
	double getMasaPojazdu() {return MasaPojazdu;}
	double getMasaDopuszczalna() {return MasaDopuszczalna;}
	double getCena() {return Cena;}
};
