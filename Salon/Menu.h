#pragma once
#include "Biblioteki.h"
#include "Salon.h"
#include "HTML.h"


class Menu					
{
public:
	Menu();
private:
	void Interfejs();		//Metoda odpowiadająca za działanie menu, obsługuje wszystkie szczeble menu.
	const char Glowne();	//Metoda zawierające elementy glownego menu, zwraca wybrany element.
	const char Klient();	//Metoda zawierajace elementy podmenu Klienta
	const char Salon();		//Metoda zawierajace elementy podmenu Salon
	const char Budzet();
	const char Pracownicy();
	const char Zestawienia();
};


