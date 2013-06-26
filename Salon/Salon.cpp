#include "Salon.h"

extern Salon nowy;

Salon::Salon(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short czas,
			 const std::string nazwa, const double budzet, const double przychody, const double rozchody, const double czynsz)
			 :PrezesSalonu(imie , nazwisko , telefon ,(przychody*0,1) , czas), NazwaMarki(nazwa) , Budzet(budzet) , Przychody(przychody) , Rozchody(rozchody) , Czynsz(czynsz)
{

}

double Salon::PokazBudzet()
{
	Budzet = Przychody + Rozchody;
	return Budzet;
}

void Salon::WyplacWynagrodzenie()
{
	Rozchody -= PrezesSalonu.NalezneWynagrodzenie();

	for(int i = 0 ; i < Personel.size() ; ++i)
	{
		Rozchody -= Personel[i]->NalezneWynagrodzenie();
	}

	Rozchody -= Czynsz;
}

void Salon::SprzedajSamochod()
{
	
}

void Salon::ZatrudnijPracownika(const Pracownik &P)
{
	Personel.push_back(new Pracownik(P));
}

void SprawdzPrzecinki(std::string &buff, std::istringstream &linestream)	//Sprawdza wystêpowanie przecinków w nazwie
{		
	if(buff[buff.length()-1]=='"')	//Sprawdza czy ostatni znak jest "
	{
		std::string temp;
		getline(linestream,temp,',');	//Pobiera nastêpny kawa³ek linii do przecinka
		if(temp[0]=='"')	//Sprawdza czy pierwszy znak pobranego nastêpnego kawa³ka linni jest ". W ten sposób wy³apuje przypadku typu: ",".
		{
			buff.erase(buff.length()-1);	//Usuwa " z pierwszego kawa³ka
			temp.erase(0,1);				//Usuwa " z drugiego kawa³ka
			buff+=',';						//Dodaje rzeczony przecinek
			buff+=temp;						//Skleja dwa kawa³ki
		}
	}
}

bool Salon::DostawaSamochodow(std::string nazwa)	//Tu trzeba dorobiæ obs³ugê b³êdów
{
	try
	{
		std::fstream plik;
		std::string linia;
		nazwa+=".csv";
		plik.open(nazwa.c_str(), std::ios::in | std::ios::out);

		if(plik.good())
		{
			while(plik.good())
			{
				if (getline(plik, linia))
				{
					std::string Marka, Model, nadwozie, naped, masa, masadop, cena, temp;
					double Masa, MasaDop, Cena;
					Typ Nadwozie;
					Rodzaj Naped;

					std::istringstream linestream(linia);

					getline(linestream,Marka,',');
					SprawdzPrzecinki(Marka,linestream);	//Sprawdza wystêpuj¹ce przecinki. Je¿eli s¹ w " " to je dodaje do nazwy.

					getline(linestream,Model,',');
					SprawdzPrzecinki(Model,linestream);

					getline(linestream,nadwozie,',');
					getline(linestream,naped,',');
					getline(linestream,masa,',');
					getline(linestream,masadop,',');
					getline(linestream,cena,'\n');

					Masa=atof(masa.c_str());
					MasaDop=atof(masadop.c_str());
					Cena=atof(cena.c_str());

					if(naped=="Przód")Naped=Przód;
					if(naped=="Ty³")Naped=Ty³;
					if(naped=="Obie_osie")Naped=Obie_osie;

					if(nadwozie=="Hatchback")Nadwozie=Hatchback;
					if(nadwozie=="Sedan")Nadwozie=Sedan;
					if(nadwozie=="Kombi")Nadwozie=Kombi;
					if(nadwozie=="SUV")Nadwozie=SUV;
					if(nadwozie=="Dostawczy")Nadwozie=Dostawczy;

					BazaSamochodow.push_back(Samochod(Masa,MasaDop,Cena,Marka,Model,Naped,Nadwozie));
				}
			}
		}
		plik.close();
		return true;
	}
	catch(...)
	{
		return false;
	}
}

void Salon::ZapiszBazeSamochodow()
{
	std::ofstream Plik("auta.csv");
	for(int i=0 ; i<BazaSamochodow.size(); i++)
		Plik<<BazaSamochodow[i]<<"\n";   
}

void Salon::WyswietlBazeSamochodow()
{
	std::cout<<"---Baza aktualnie dostêpnych samochodów---\n\n";
	std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<" Nadwozie "<<"|"<<" Napêd "<<"|"<<" Masa "<<"|"
		<<"Masa dop"<<"|"<<"    Cena"<<std::endl;
	std::cout<<"============================================================================="<<std::endl;

	for(int i=0; i<nowy.BazaSamochodow_Size();++i)
	{
		//Skalowanie ramki powinno byæ robione na podstawie pobieranych faktycznych wartosci najdluzszego elementu dla danego typu.

		std::cout<<std::setw(13)<<BazaSamochodow[i].getMarka()<<", "											//Marka
			<<std::setw(13)<<BazaSamochodow[i].getModel()<<", "													//Model
			<<std::setw(9)<<BazaSamochodow[i].getNadwozie()<<", "												//Nadwozie
			<<std::setw(6)<<BazaSamochodow[i].getNaped()<<", "													//Naped
			<<std::setw(5)<<std::fixed<<std::setprecision(0)<<BazaSamochodow[i].getMasaPojazdu()<<", "			//Masa
			<<std::setw(7)<<std::fixed<<std::setprecision(0)<<BazaSamochodow[i].getMasaDopuszczalna()<<", "		//Masa dopuszczalna
			<<std::setw(7)<<std::fixed<<std::setprecision(2)<<BazaSamochodow[i].getCena()<<" zl"<<std::endl;	//Cena

	}
	std::cout<<std::endl;
}