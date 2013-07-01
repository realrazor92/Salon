#include "HTML.h"

extern Salon nowy;

void DrukujZestawienieDostepnychSamochodow(std::string nazwa)
{

	std::string Nazwa = nazwa + ".html";
	std::ofstream Plik(Nazwa.c_str());
	//----------------------------Pocz�tek strony
	if(Plik.good())
	{
		Plik<<"<!DOCTYPE html>\n"
			"<html lang=\"pl\">\n\n"

			"<title>Zarz�dzanie salonem samochodowym - " << nazwa <<" </title>\n"
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
			"<caption><h1>Zestawienie dost�pnych modeli</h1><h2>"<<nazwa<<"</h2></caption>\n"
			"<thead> <!-- Nag��wek tabeli -->\n"
			"<tr>\n"
			"<th>Marka</th><th>Model</th><th>Nadwozie</th><th>Nap�d</th><th>Masa</th><th>Masa dopuszczalna</th><th>Cena</th>\n"
			"</tr>\n"
			"</thead>\n\n"

			"<tbody>	<!-- Cia�o tabeli -->\n\n";

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

		std::cout << "\nEksport zako�czony pomy�lnie. \nZostanie teraz wy�wietlona utworzona strona.\n";
		Plik.close();

		system(Nazwa.c_str());
	}
	else
	{
		std::cout << "\nB��d przy tworzeniu strony, eksport nieudany!";
		Plik.close();
	}
}
