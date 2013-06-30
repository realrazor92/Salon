#include <iostream>
#include <conio.h>
#include "Osoba.h"
#include "Manager.h"
#include "Pracownik.h"
#include "Prezes.h"
#include "Salon.h"
#include "Menu.h"

extern Salon nowy;


int main()
{
	Menu menu;
	
	///*
	////To jeszcze wymaga przemyslenia. Wersja baaardzo rozwojowa.
	//std::vector <Osoba*> Personel;
	//Manager nowy("Jan", "Nowak","505505505",2500,1,1);
	//Personel.push_back(&nowy);
	//Personel.push_back(new Prezes("Jan", "Inny", "555999666",777,2));
	//Personel.push_back(new Pracownik("Tomasz", "Nowak","111222333",300,23,0));
	//Personel.push_back(new Klient("Pawel","Dziwny","000111222",100000));

	//for(int i=0;i<Personel.size();++i)						
	//{
	//	if(Personel[i]->getType()==typeid(Manager*).name())
	//		std::cout<<(Manager&)*Personel[i];
	//	else if(Personel[i]->getType()==typeid(Prezes*).name())
	//		std::cout<<(Prezes&)*Personel[i];
	//	else if(Personel[i]->getType()==typeid(Pracownik*).name())
	//		std::cout<<(Pracownik&)*Personel[i];
	//	else if(Personel[i]->getType()==typeid(Klient*).name())
	//		std::cout<<(Klient&)*Personel[i];
	//}
	//*/



	_getch();
	return 0;
}