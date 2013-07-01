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
		"[1] Klient\n"	
		"[2] Salon\n\n"
		"[0] Zako�cz program\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Klient()
{
	char k;
	std::cout << "    MENU KLIENTA \n\n" 
		"[1] Baza aktualnie dost�pnych samochod�w\n"		
		"[2] Zakup samochodu\n\n"
		"[0] Powr�t do menu g��wnego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Salon()
{
	char k;
	std::cout << "    MENU SALONU \n\n" 
		"[1] Bud�et\n"		
		"[2] Pracownicy\n"
		"[3] Zestawienia sprzeda�y\n"
		"[4] Dostawa samochod�w\n\n"

		"[0] Powr�t do menu g��wnego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Budzet()
{
	char k;
	std::cout << "    MENU BUD�ETU \n\n" 
		"[1] Bilans salonu\n"		

		"[0] Powr�t do menu g��wnego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Zestawienia()
{
	char k;
	std::cout << "    MENU ZESTAWIE� \n\n" 
		"[1] Zestawienie miesi�czne\n"		
		"[2] Zestawienie og�lne\n"
		"[3] Zestawienie pracownika\n\n"

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
		case '1':	//Klient
			{
				char k;
				do
				{
					k=Klient();
					switch(k)
					{
					case '1':		//Wyswietl baze aktualnie dost�pnych samochod�w
						{
							nowy.WyswietlBazeSamochodow();
							break;
						}
					case '2':		//Zakup samochodu
						{
							nowy.SprzedajSamochod();
							nowy.ZapiszBazeSprzedanych();
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
		case '2':	//Salon
			{
				char k;
				do
				{
					k=Salon();
					switch(k)
					{
					case '1':		//Bud�et
						{
							char k;
							do
							{
								k=Budzet();
								switch(k)
								{
								case '1':		//Bilans salonu
									{
										nowy.BilansSalonu();
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
					case '2':		//Pracownicy
						{
							nowy.WyswietlPersonel();
							break;
						}
					case '3':		//Zestawienia sprzeda�y
						{

							char k;
							do
							{
								k=Zestawienia();
								switch(k)
								{
								case '1':		//Zestawienie miesi�czne
									{
										unsigned short int Rok, Miesiac;
										std::cout<<"Podaj rok: ";
										std::cin>>Rok;
										std::cout<<"Podaj miesi�c: ";
										std::cin>>Miesiac;
										nowy.ZestawienieMiesieczne(Miesiac,Rok);
										break;
									}
								case '2':		//Zestawienie og�lne
									{
										nowy.ZestawienieOgolne();
										break;
									}
								case '3':		//Zestawienie pracownika
									{

										nowy.WyswietlPersonel();
										std::cout<<std::endl<<"Wprowad� ID pracownika: ";
										unsigned short int id;
										std::cin>>id;
										system("cls");

										nowy.ZestawieniePracownika(id);
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
					case '4':		//Dostawa samochod�w
						{
							std::cout<<"------------Dostawa samochod�w------------\n\n";
							std::cout<<"Wprowad� nazw� pliku z baz� samochod�w: ";
							std::string nazwa;
							std::cin>>nazwa;
							if(nowy.DostawaSamochodow(nazwa))
							{
								std::cout<<"Pomy�lnie dodano baz� samochod�w.\n";
							}
							else
							{
								std::cout<<"Wyst�pi� b��d dodawania bazy danych.\n";
							}	
							nowy.ZapiszBazeSamochodow();
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
		case '0':
			{
				break;
			}
		default:
			{
				std::cout<<"Bl�dna opcja. Spr�buj jeszcze raz.\n\n";
				//system("PAUSE");
				//system("cls");
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
	nowy.ZaladujPersonel();
	nowy.ZaladujBazeSprzedanych();
	nowy.WyplacWynagrodzenie();
	Interfejs();
}

