#include "Menu.h"
#include "Salon.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Uwaga! Wszystkie szczeble menu musz� by� nad cia�em metody Interfejs, aby ta je "widzia�a".

extern Salon nowy;

const char Menu::Glowne()
{
	char k;
	std::cout << "\n    MENU G��WNE \n" 
		"[1] Aktualnie dost�pne modele\n"		
		"[2] Opcja 2\n"
		"[3] Opcja 3\n\n"
		"[0] Zako�cz program\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Podmenu1()
{
	char k;
	std::cout << "    AKTUALNIE DOST�PNE MODELE \n\n" 
		"[1] Wy�wietl baz� aktualnie dost�pnych samochod�w\n"		
		"[2] Dostawa samochod�w\n"
		"[3] \n"
		"[0] Powr�t do menu g��wnego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu::Interfejs()
{

	char k;
	do
	{
		setlocale(LC_CTYPE,"polish");

		std::cout << "------- Program Zarz�dzanie salonem samochodowym --------\n"
			"Projekt sekcji projetowej R.04 | Politechnika �l�ska 2013 \n\n";

		k=Glowne();
		switch(k)
		{
		case '1':	//Aktualnie dost�pne modele
			{
				char k;
				do
				{
					k=Podmenu1();
					switch(k)
					{
					case '1':		//Wyswietl baze aktualnie dost�pnych samochod�w
						{
							nowy.WyswietlBazeSamochodow();
							/*
							std::cout<<"---Baza aktualnie dost�pnych samochod�w---\n\n";	//Formatowanie dorobie p�niej
							std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<" Nadwozie "<<"|"<<" Nap�d "<<"|"<<" Masa "<<"|"
								<<"Masa dop"<<"|"<<"    Cena"<<std::endl;
							std::cout<<"============================================================================="<<std::endl;
							for(int i=0; i<nowy.BazaSamochodow_Size();++i)
							{
								std::cout<<nowy.BazaSamochodow_Get(i)<<std::endl;
							}
							std::cout<<std::endl;
							*/


							break;
						}
					case '2':		//Dostawa samochod�w
						{
							std::cout<<"------------Dostawa samochod�w------------\n\n";
							std::cout<<"Wprowad� nazw� pliku z baz� samochod�w: ";
							std::string nazwa;
							std::cin>>nazwa;
							bool flaga = nowy.DostawaSamochodow(nazwa);
							if(flaga==true)
							{
								std::cout<<"Pomy�lnie dodano baz� samochod�w.\n";
							}
							else
								std::cout<<"Wyst�pi� b��d dodawania bazy danych.\n";

							nowy.ZapiszBazeSamochodow();

								break;
						}
					case '3':
						{
							std::cout<<"Wybrales 3.\n";
							break;
						}
					default:
						{
							std::cout<<"Bl�dna opcja. Spr�buj jeszcze raz.\n";
						}
					}

				}
				while(k!='0');
				system("cls");
				break;
			}
		case '2':
			{
				std::cout<<"Opcja 2\n";
				system("PAUSE");
				system("cls");
				break;
			}
		case '3':
			{
				std::cout<<"Opcja 3\n";
				system("PAUSE");
				system("cls");
				break;
			}
		case '0':
			{
				break;
			}
		default:
			{
				std::cout<<"Bl�dna opcja. Spr�buj jeszcze raz.\n\n";
				system("PAUSE");
				system("cls");
			}
		}
	}
	while(k!='0');
	system("cls");
	std::cout<<"Naci�nij dowolny klawisz aby zako�czy�\n";
}

Menu::Menu()
{
	nowy.DostawaSamochodow("auta");
	Interfejs();
}

