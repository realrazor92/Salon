#pragma once

#include "Biblioteki.h"
#include "UjemnaWartosc.h"
#include "Osoba.h"
#include "Prezes.h"
#include "Samochod.h"
#include "Pracownik.h"
#include "Manager.h"
#include "Klient.h"

class Salon
{
private:
	Prezes PrezesSalonu;
	std::vector<Osoba*> Personel;
	double Budzet;
	double Przychody;
	double Rozchody;	
	std::string NazwaMarki;
	std::vector<Samochod> BazaSamochodow;
	std::vector<Samochod> SprzedaneSamochody;


public:
	Salon(const std::string imie, const std::string nazwisko , const std::string telefon, const double wynagrodzenie, const unsigned short int czas , const std::string nazwa , const double budzet , const double przychody , const double rozchody);
	void SprzedajSamochod();
	void ZatrudnijPracownika(const Pracownik &P); //ZROBIONE
	void WyplacWynagrodzenie();
	double PokazBudzet(); //ZROBIONE
	//------------------------------------// Samochody dost�pne
	bool DostawaSamochodow(std::string nazwa);// tu proponuje zrobic baze samochodow wczytana z pliku lub czegos, aby mozna by�o 
											  //sprzedawa� samochody, tak �eby by�o to dosy� wiarygodnie opracowane.
	int BazaSamochodow_Size() {return BazaSamochodow.size();}
	void WyswietlBazeSamochodow();
	void ZapiszBazeSamochodow();
	//------------------------------------
	bool ZaladujPersonel();
	void WyswietlPersonel();


};

