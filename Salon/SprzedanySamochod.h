#pragma once
#include "Biblioteki.h"
#include "Samochod.h"
#include "Data.h"

class SprzedanySamochod: public Samochod
{
private:
	Data DataSprzedazy;
	//unsigned short int IDsprzedawcy;
public:
	SprzedanySamochod(Samochod samochod, Data data);
	void Wyswietl(unsigned short int ID);
	Data GetData() {return DataSprzedazy;}
};
