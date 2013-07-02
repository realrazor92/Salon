#pragma once
#include "Biblioteki.h"
#include "Salon.h"
#include "HTML.h"
#include "BladWprowadzenia.h"
#include "BlednyIndeks.h"


class Menu					
{
public:
	Menu();
private:
	void Interfejs();		//Metoda odpowiadaj¹ca za dzia³anie menu, obs³uguje wszystkie szczeble menu.
	const char Glowne();	//Metoda zawieraj¹ce elementy glownego menu, zwraca wybrany element.
	const char Klient();	//Metoda zawierajace elementy podmenu Klienta
	const char Salon();		//Metoda zawierajace elementy podmenu Salon
	const char Budzet();
	const char Pracownicy();
	const char Zestawienia();
};


