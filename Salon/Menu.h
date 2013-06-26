#pragma once
#include "Biblioteki.h"
#include "Salon.h"


class Menu					//G��wna klasa tworz�ca menu poprzez konstruktor. Puki co menu nie zawiera �adnych konkret�w, 
							//to trzeba ustali�.
{
public:
	Menu();
private:
	void Interfejs();		//Metoda odpowiadaj�ca za dzia�anie menu, obs�uguje wszystkie szczeble menu.
	const char Glowne();	//Metoda zawieraj�ce elementy glownego menu, zwraca wybrany element.
	const char Klient();	//Metoda zawierajace elementy podmenu Klienta
	const char Salon();		//Metoda zawierajace elementy podmenu Salon
	const char Budzet();
	const char Pracownicy();
	const char Zestawienia();
};


