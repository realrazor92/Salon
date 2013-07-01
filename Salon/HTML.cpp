#include "HTML.h"

extern Salon nowy;

void DrukujZestawienieDostepnychSamochodow(std::string &nazwa)
{

	std::string Nazwa = nazwa + ".html";
	std::ofstream Plik(Nazwa.c_str());
	//----------------------------Początek strony
	if(Plik.good())
	{
		Plik<<"<!DOCTYPE html>\n"
			"<html lang=\"pl\">\n\n"

			"<title>Zarządzanie salonem samochodowym - " << nazwa <<" </title>\n"
			"<meta charset=\"Windows-1250\" />\n"
			"<meta http-equiv=\"Content-type\" content=\"text/html; charset=Windows-1250\" />\n"
			"<style type=\"text/css\">\n"
			"table, td, th {\n"
			"margin:0 auto;\n"
			"border:1px solid black;\n"
			"text-align: center;\n"
			"padding:2px;\n"
			"}\n"
			"</style>\n"
			"</head>\n"
			"<body>\n"
			"<table>\n"
			"<caption><h1>Zestawienie dostępnych modeli</h1><h2>"<<nazwa<<"</h2></caption>\n"
			"<thead> <!-- Nagłówek tabeli -->\n"
			"<tr>\n"
			"<th>Marka</th><th>Model</th><th>Nadwozie</th><th>Napęd</th><th>Masa</th><th>Masa dopuszczalna</th><th>Cena</th>\n"
			"</tr>\n"
			"</thead>\n\n"

			"<tbody>	<!-- Ciało tabeli -->\n\n";

		if(!nowy.BazaSamochodow.empty())
		{
			
			for(unsigned int i=0 ; i<nowy.BazaSamochodow.size() ; ++i)
			{

				Plik<<"<tr>"
					"<td>"<<nowy.BazaSamochodow[i].getMarka()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getModel()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getNadwozie()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getNaped()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getMasaPojazdu()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getMasaDopuszczalna()<<"</td>"
					"<td>"<<nowy.BazaSamochodow[i].getCena()<<"</td>";
					
				Plik<<"</tr>\n\n";
			}
		}
		Plik<<"</tbody>\n\n"
			"<tfoot>	<!-- Stopka tabeli -->\n"
			"</tfoot>\n\n"
			"</table>\n\n"
			"</body>\n"
			"</html>\n";

		std::cout << "\nEksport zakończony pomyślnie. \nZostanie teraz wyświetlona utworzona strona.\n";
		Plik.close();

		system(Nazwa.c_str());
	}
	else
	{
		std::cout << "\nBłąd przy tworzeniu strony, eksport nieudany!";
		Plik.close();
	}
}


void DrukujZestawieniePersonelu(std::string &nazwa)
{

	std::string Nazwa = nazwa + ".html";
	std::ofstream Plik(Nazwa.c_str());
	//----------------------------Początek strony
	if(Plik.good())
	{
		Plik<<"<!DOCTYPE html>\n"
			"<html lang=\"pl\">\n\n"

			"<title>Zarządzanie salonem samochodowym - " << nazwa <<" </title>\n"
			"<meta charset=\"Windows-1250\" />\n"
			"<meta http-equiv=\"Content-type\" content=\"text/html; charset=Windows-1250\" />\n"
			"<style type=\"text/css\">\n"
			"table, td, th {\n"
			"margin:0 auto;\n"
			"border:1px solid black;\n"
			"text-align: center;\n"
			"padding:2px;\n"
			"}\n"
			"</style>\n"
			"</head>\n"
			"<body>\n"
			"<table>\n"
			"<caption><h1>Zestawienie personelu</h1><h2>"<<nazwa<<"</h2></caption>\n"
			"<thead> <!-- Nagłówek tabeli -->\n"
			"<tr>\n"
			"<th>Imię</th><th>Nazwisko</th><th>Data urodzenia</th><th>Telefon</th><th>Czas pracy</th><th>ID</th><th>Podwładni</th><th>Wynagrodzenie</th>\n"
			"</tr>\n"
			"</thead>\n\n"

			"<tbody>	<!-- Ciało tabeli -->\n\n";

		if(!nowy.Personel.empty())
		{
			
			for(unsigned int i=0 ; i<nowy.Personel.size() ; ++i)
			{
				Plik<<"<tr>"
					"<td>"<<nowy.Personel[i]->getImie()<<"</td>"
					"<td>"<<nowy.Personel[i]->getNazwisko()<<"</td>"
					"<td>"<<nowy.Personel[i]->getDataur()<<"</td>"
					"<td>"<<nowy.Personel[i]->getTelefon()<<"</td>"
					"<td>"<<nowy.Personel[i]->getCzasPracy()<<"</td>"
					"<td>"<<nowy.Personel[i]->GetID()<<"</td>"
					"<td>"<<nowy.Personel[i]->getIloscPodwladnych()<<"</td>"
					"<td>"<<nowy.Personel[i]->getWynagrodzenie()<<"</td>";
					
				Plik<<"</tr>\n\n";
			}
		}
		Plik<<"</tbody>\n\n"
			"<tfoot>	<!-- Stopka tabeli -->\n"
			"</tfoot>\n\n"
			"</table>\n\n"
			"</body>\n"
			"</html>\n";

		std::cout << "\nEksport zakończony pomyślnie. \nZostanie teraz wyświetlona utworzona strona.\n";
		Plik.close();

		system(Nazwa.c_str());
	}
	else
	{
		std::cout << "\nBłąd przy tworzeniu strony, eksport nieudany!";
		Plik.close();
	}
}

void DrukujZestawieniePracownika(std::string &nazwa, unsigned short int id)
{

	std::string Nazwa = nazwa + ".html";
	std::ofstream Plik(Nazwa.c_str());
	//----------------------------Początek strony
	if(Plik.good() && nowy.GetPos(id)!=-1)
	{
		Plik<<"<!DOCTYPE html>\n"
			"<html lang=\"pl\">\n\n"

			"<title>Zarządzanie salonem samochodowym - " << nazwa <<" </title>\n"
			"<meta charset=\"Windows-1250\" />\n"
			"<meta http-equiv=\"Content-type\" content=\"text/html; charset=Windows-1250\" />\n"
			"<style type=\"text/css\">\n"
			"table, td, th {\n"
			"margin:0 auto;\n"
			"border:1px solid black;\n"
			"text-align: center;\n"
			"padding:2px;\n"
			"}\n"
			"</style>\n"
			"</head>\n"
			"<body>\n"
			"<table>\n"
			"<caption><h1>Zestawienie pracownika</h1><h2>"<<nowy.Personel[nowy.GetPos(id)]->getImie()<< " " <<nowy.Personel[nowy.GetPos(id)]->getNazwisko()<<"</h2></caption>\n"
			"<thead> <!-- Nagłówek tabeli -->\n"
			"<tr>\n"
			"<th>Marka</th><th>Model</th><th>Cena</th><th>Data sprzedaży</th>\n"
			"</tr>\n"
			"</thead>\n\n"

			"<tbody>	<!-- Ciało tabeli -->\n\n";

		if(nowy.Personel[nowy.GetPos(id)]->getType() == typeid(Pracownik*).name())
		{
			for(unsigned int i=0 ; i<((Pracownik&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody_Size() ; ++i)
			{
				Plik<<"<tr>"
					"<td>"<<((Pracownik&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getMarka()<<"</td>"
					"<td>"<<((Pracownik&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getModel()<<"</td>"
					"<td>"<<((Pracownik&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getCena()<<"</td>"
					"<td>"<<((Pracownik&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].GetData()<<"</td>";
					
				Plik<<"</tr>\n\n";
			}
		}
		if(nowy.Personel[nowy.GetPos(id)]->getType() == typeid(Manager*).name())
		{
			for(unsigned int i=0 ; i<((Manager&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody_Size() ; ++i)
			{
				Plik<<"<tr>"
					"<td>"<<((Manager&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getMarka()<<"</td>"
					"<td>"<<((Manager&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getModel()<<"</td>"
					"<td>"<<((Manager&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].getCena()<<"</td>"
					"<td>"<<((Manager&)*nowy.Personel[nowy.GetPos(id)]).SprzedaneSamochody[i].GetData()<<"</td>";
					
				Plik<<"</tr>\n\n";
			}
		}

		Plik<<"</tbody>\n\n"
			"<tfoot>	<!-- Stopka tabeli -->\n"
			"</tfoot>\n\n"
			"</table>\n\n"
			"</body>\n"
			"</html>\n";

		std::cout << "\nEksport zakończony pomyślnie. \nZostanie teraz wyświetlona utworzona strona.\n";
		Plik.close();

		system(Nazwa.c_str());
	}
	else
	{
		std::cout << "\nBłąd przy tworzeniu strony, eksport nieudany!";
		Plik.close();
	}
}
void DrukujZestawienieMiesieczne(std::string &nazwa, unsigned short int rok, unsigned short int miesiac)
{
	std::string Nazwa = nazwa + ".html";
	std::ofstream Plik(Nazwa.c_str());
	//----------------------------Początek strony
	if(Plik.good())
	{
		Plik<<"<!DOCTYPE html>\n"
			"<html lang=\"pl\">\n\n"

			"<title>Zarządzanie salonem samochodowym - " << nazwa <<" </title>\n"
			"<meta charset=\"Windows-1250\" />\n"
			"<meta http-equiv=\"Content-type\" content=\"text/html; charset=Windows-1250\" />\n"
			"<style type=\"text/css\">\n"
			"table, td, th {\n"
			"margin:0 auto;\n"
			"border:1px solid black;\n"
			"text-align: center;\n"
			"padding:2px;\n"
			"}\n"
			"</style>\n"
			"</head>\n"
			"<body>\n"
			"<table>\n"
			"<caption><h1>Zestawienie sprzedaży</h1><h2>"<<std::fixed<<std::setfill('0')<<std::setw(2)<<miesiac<<"."<<rok<<"</h2></caption>\n"
			"<thead> <!-- Nagłówek tabeli -->\n"
			"<tr>\n"
			"<th>Marka</th><th>Model</th><th>Cena</th><th>Data sprzedaży</th><th>ID sprzedawcy</th>\n"
			"</tr>\n"
			"</thead>\n\n"

			"<tbody>	<!-- Ciało tabeli -->\n\n";
		for(unsigned short int i=0 ; i<nowy.Personel.size() ; ++i)
		{
			if(nowy.Personel[i]->getType() == typeid(Pracownik*).name())
			{
				for(unsigned short int j = 0 ; j<((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody_Size(); ++j)
				{
					if(((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData().Rok == rok && ((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData().Miesiac == miesiac)
					{
						Plik<<"<tr>"
							"<td>"<<((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].getMarka()<<"</td>"
							"<td>"<<((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].getModel()<<"</td>"
							"<td>"<<((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].getCena()<<"</td>"
							"<td>"<<((Pracownik&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData()<<"</td>"
							"<td>"<<((Pracownik&)*nowy.Personel[i]).GetID()<<"</td>";
							
						Plik<<"</tr>\n\n";
					}
				}
			}
			if(nowy.Personel[i]->getType() == typeid(Manager*).name())
			{
				for(unsigned short int j = 0 ; j<((Manager&)*nowy.Personel[i]).SprzedaneSamochody_Size(); ++j)
				{
					if(((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData().Rok == rok && ((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData().Miesiac == miesiac)
					{
						Plik<<"<tr>"
							"<td>"<<((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].getMarka()<<"</td>"
							"<td>"<<((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].getModel()<<"</td>"
							"<td>"<<((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].getCena()<<"</td>"
							"<td>"<<((Manager&)*nowy.Personel[i]).SprzedaneSamochody[j].GetData()<<"</td>"
							"<td>"<<((Manager&)*nowy.Personel[i]).GetID()<<"</td>";
							
						Plik<<"</tr>\n\n";
					}
				}
			}
		}

		Plik<<"</tbody>\n\n"
			"<tfoot>	<!-- Stopka tabeli -->\n"
			"</tfoot>\n\n"
			"</table>\n\n"
			"</body>\n"
			"</html>\n";

		std::cout << "\nEksport zakończony pomyślnie. \nZostanie teraz wyświetlona utworzona strona.\n";
		Plik.close();

		system(Nazwa.c_str());
	}
	else
	{
		std::cout << "\nBłąd przy tworzeniu strony, eksport nieudany!";
		Plik.close();
	}
}