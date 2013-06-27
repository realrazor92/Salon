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
		"[1] Klient\n"	
		"[2] Salon\n\n"
		"[0] Zakoñcz program\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Klient()
{
	char k;
	std::cout << "    MENU KLIENTA \n\n" 
		"[1] Baza aktualnie dostêpnych samochodów\n"		
		"[2] Zakup samochodu\n\n"
		"[0] Powrót do menu g³ównego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Salon()
{
	char k;
	std::cout << "    MENU SALONU \n\n" 
		"[1] Bud¿et\n"		
		"[2] Pracownicy\n"
		"[3] Zestawienia sprzeda¿y\n"
		"[4] Dostawa samochodów\n\n"

		"[0] Powrót do menu g³ównego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Budzet()
{
	char k;
	std::cout << "    MENU BUD¯ETU \n\n" 
		"[1] Przychody\n"		
		"[2] Rozchody\n\n"

		"[0] Powrót do menu g³ównego\n"			
		"\nWybierz: ";
	std::cin >> k;
	system("cls");
	return k;
}

const char Menu::Zestawienia()
{
	char k;
	std::cout << "    MENU ZESTAWIEÑ \n\n" 
		"[1] Zestawienie miesiêczne\n"		
		"[2] Zestawienie ogólne\n"
		"[3] Zestawienie pracownika\n\n"

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
		case '1':	//Klient
			{
				char k;
				do
				{
					k=Klient();
					switch(k)
					{
					case '1':		//Wyswietl baze aktualnie dostêpnych samochodów
						{
							nowy.WyswietlBazeSamochodow();
							break;
						}
					case '2':		//Zakup samochodu
						{
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
		case '2':	//Salon
			{
				char k;
				do
				{
					k=Salon();
					switch(k)
					{
					case '1':		//Bud¿et
						{
							char k;
							do
							{
								k=Budzet();
								switch(k)
								{
								case '1':		//Przychody
									{
										break;
									}
								case '2':		//Rozchody
									{
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
					case '2':		//Pracownicy
						{
							nowy.ZaladujPersonel();	//To docelowo bêdzie gdzieœ na pocz¹tku menu.
							nowy.WyswietlPersonel();
							break;
						}
					case '3':		//Zestawienia sprzeda¿y
						{

							char k;
							do
							{
								k=Zestawienia();
								switch(k)
								{
								case '1':		//Zestawienie miesiêczne
									{
										break;
									}
								case '2':		//Zestawienie ogólne
									{
										break;
									}
								case '3':		//Zestawienie pracownika
									{
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
					case '4':		//Dostawa samochodów
						{
							std::cout<<"------------Dostawa samochodów------------\n\n";
							std::cout<<"WprowadŸ nazwê pliku z baz¹ samochodów: ";
							std::string nazwa;
							std::cin>>nazwa;
							if(nowy.DostawaSamochodow(nazwa))
							{
								std::cout<<"Pomyœlnie dodano bazê samochodów.\n";
							}
							else
							{
								std::cout<<"Wyst¹pi³ b³¹d dodawania bazy danych.\n";
							}	
							nowy.ZapiszBazeSamochodow();
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
		case '0':
			{
				break;
			}
		default:
			{
				std::cout<<"Blêdna opcja. Spróbuj jeszcze raz.\n\n";
				//system("PAUSE");
				//system("cls");
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

