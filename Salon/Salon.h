#pragma once

#include "Biblioteki.h"
#include "UjemnaWartosc.h"
#include "Osoba.h"
#include "Prezes.h"
#include "Samochod.h"
#include "Pracownik.h"
#include "Manager.h"
#include "Klient.h"
#include "SprzedanySamochod.h"

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

public:
	Salon(const std::string imie, const std::string nazwisko , const std::string telefon, const double wynagrodzenie, const unsigned short int czas , const std::string nazwa , const double budzet , const double przychody , const double rozchody);
	void SprzedajSamochod();
	void ZatrudnijPracownika(const Pracownik &P); //ZROBIONE
	void WyplacWynagrodzenie();
	double PokazBudzet(); //ZROBIONE
	//------------------------------------// Samochody dostêpne
	bool DostawaSamochodow(std::string nazwa);
	int BazaSamochodow_Size() {return BazaSamochodow.size();}
	void WyswietlBazeSamochodow();
	void ZapiszBazeSamochodow();
	//------------------------------------//Personel
	bool ZaladujPersonel();
	void WyswietlPersonel() const;
	//------------------------------------//Sprzedane samochody
	bool ZaladujBazeSprzedanych();
	short int GetPos(const unsigned short int id) const;
	//------------------------------------//Zestawienia
	void ZestawienieOgolne();
	void ZestawieniePracownika(const unsigned short int ID);
	void ZestawienieMiesieczne(const unsigned short int Miesiac, const unsigned short int Rok);
};

