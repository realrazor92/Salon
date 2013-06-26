#pragma once
#include "Biblioteki.h"
#include "Salon.h"


class Menu					//G³ówna klasa tworz¹ca menu poprzez konstruktor. Puki co menu nie zawiera ¿adnych konkretów, 
							//to trzeba ustaliæ.
{
public:
	Menu();
private:
	void Interfejs();		//Metoda odpowiadaj¹ca za dzia³anie menu, obs³uguje wszystkie szczeble menu.
	const char Glowne();	//Metoda zawieraj¹ce elementy glownego menu, zwraca wybrany element.
	const char Podmenu1();	//Metoda zawieraj¹ce elementy podmenu menu, zwraca wybrany element. Nazwa jest do zmiany w momencie,
							//gdy bêdziemy mieli ju¿ ustalone co i jak.
};


