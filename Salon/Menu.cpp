#include "Menu.h"
#include "Salon.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Uwaga! Wszystkie szczeble menu musz¹ byæ nad cia³em metody Interfejs, aby ta je "widzia³a".

extern Salon nowy;

const char Menu::Glowne()
{
	char k;
	std::cout << "\n    MENU G£ÓWNE \n" 
		"[1] Aktualnie dostêpne modele\n"		
		"[2] Opcja 2\n"
		"[3] Opcja 3\n\n"
		"[0] Zakoñcz program\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Podmenu1()
{
	char k;
	std::cout << "    AKTUALNIE DOSTÊPNE MODELE \n\n" 
		"[1] Wyœwietl bazê aktualnie dostêpnych samochodów\n"		
		"[2] Dostawa samochodów\n"
		"[3] \n"
		"[0] Powrót do menu g³ównego\n"			
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

		std::cout << "------- Program Zarz¹dzanie salonem samochodowym --------\n"
			"Projekt sekcji projetowej R.04 | Politechnika Œl¹ska 2013 \n\n";

		k=Glowne();
		switch(k)
		{
		case '1':	//Aktualnie dostêpne modele
			{
				char k;
				do
				{
					k=Podmenu1();
					switch(k)
					{
					case '1':		//Wyswietl baze aktualnie dostêpnych samochodów
						{
							nowy.WyswietlBazeSamochodow();
							/*
							std::cout<<"---Baza aktualnie dostêpnych samochodów---\n\n";	//Formatowanie dorobie póŸniej
							std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<" Nadwozie "<<"|"<<" Napêd "<<"|"<<" Masa "<<"|"
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
					case '2':		//Dostawa samochodów
						{
							std::cout<<"------------Dostawa samochodów------------\n\n";
							std::cout<<"WprowadŸ nazwê pliku z baz¹ samochodów: ";
							std::string nazwa;
							std::cin>>nazwa;
							bool flaga = nowy.DostawaSamochodow(nazwa);
							if(flaga==true)
							{
								std::cout<<"Pomyœlnie dodano bazê samochodów.\n";
							}
							else
								std::cout<<"Wyst¹pi³ b³¹d dodawania bazy danych.\n";

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
							std::cout<<"Blêdna opcja. Spróbuj jeszcze raz.\n";
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
				std::cout<<"Blêdna opcja. Spróbuj jeszcze raz.\n\n";
				system("PAUSE");
				system("cls");
			}
		}
	}
	while(k!='0');
	system("cls");
	std::cout<<"Naciœnij dowolny klawisz aby zakoñczyæ\n";
}

Menu::Menu()
{
	nowy.DostawaSamochodow("auta");
	Interfejs();
}

