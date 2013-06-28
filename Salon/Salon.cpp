#include "Salon.h"

extern Salon nowy;

Salon::Salon(const std::string imie, const std::string nazwisko, const std::string telefon, const double wynagrodzenie, const unsigned short czas,
			 const std::string nazwa, const double budzet, const double przychody, const double rozchody)
			 :PrezesSalonu(imie , nazwisko , telefon , wynagrodzenie , czas), NazwaMarki(nazwa) , Budzet(budzet) , Przychody(przychody) ,
			 Rozchody(rozchody)
{}

double Salon::PokazBudzet()
{
	Budzet = Przychody + Rozchody;	//Tu chyba jest co� nie tegez, skoro rozchody to wci�� bud�et.
	return Budzet;
}

void Salon::WyplacWynagrodzenie()
{

}

void Salon::SprzedajSamochod()
{

}

void Salon::ZatrudnijPracownika(const Pracownik &P)
{
	Personel.push_back(new Pracownik(P));
}

void SprawdzPrzecinki(std::string &buff, std::istringstream &linestream)	//Sprawdza wyst�powanie przecink�w w nazwie
{		
	if(buff[buff.length()-1]=='"')	//Sprawdza czy ostatni znak jest "
	{
		std::string temp;
		getline(linestream,temp,',');	//Pobiera nast�pny kawa�ek linii do przecinka
		if(temp[0]=='"')	//Sprawdza czy pierwszy znak pobranego nast�pnego kawa�ka linni jest ". W ten spos�b wy�apuje przypadku typu: ",".
		{
			buff.erase(buff.length()-1);	//Usuwa " z pierwszego kawa�ka
			temp.erase(0,1);				//Usuwa " z drugiego kawa�ka
			buff+=',';						//Dodaje rzeczony przecinek
			buff+=temp;						//Skleja dwa kawa�ki
		}
	}
}

//-------------------Dost�pne samochody

bool Salon::DostawaSamochodow(std::string nazwa)	//Tu trzeba dorobi� obs�ug� b��d�w
{
	try
	{
		std::fstream plik;
		std::string linia;
		nazwa+=".csv";
		plik.open(nazwa.c_str(), std::ios::in);

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
					SprawdzPrzecinki(Marka,linestream);	//Sprawdza wyst�puj�ce przecinki. Je�eli s� w " " to je dodaje do nazwy.

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

					if(naped=="Prz�d")Naped=Prz�d;
					if(naped=="Ty�")Naped=Ty�;
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
		else
		{
			plik.close();
			return false;
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
	std::cout<<"---------------------Baza aktualnie dost�pnych samochod�w---------------------\n\n";
	std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<" Nadwozie "<<"|"<<" Nap�d "<<"|"<<" Masa "<<"|"
		<<"Masa dop"<<"|"<<"    Cena"<<std::endl;
	std::cout<<"=============================================================================="<<std::endl;

	for(int i=0; i<nowy.BazaSamochodow_Size();++i)
	{
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



//------------------Personel

bool Salon::ZaladujPersonel()	
{
	try
	{
		std::string nazwa = "personel";
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
					std::string Stanowisko, Imie, Nazwisko, Telefon, dzien, miesiac, rok;
					unsigned short int Dzien, Miesiac, Rok;

					std::istringstream linestream(linia);

					getline(linestream,Stanowisko,',');

					getline(linestream,Imie,',');
					getline(linestream,Nazwisko,',');
					getline(linestream,Telefon,',');
					getline(linestream,dzien,',');
					getline(linestream,miesiac,',');
					getline(linestream,rok,',');

					Dzien=atoi(dzien.c_str());
					Miesiac=atof(miesiac.c_str());
					Rok=atof(rok.c_str());

					if(Stanowisko=="Pracownik")
					{
						//ID, Czas pracy, SprzedaneSamochody (vektor)
						std::string id, czas;
						unsigned short int ID, Czas;
						getline(linestream,id,',');
						ID = atoi(id.c_str());
						getline(linestream,czas,'\n');
						Czas = atoi(czas.c_str());

						Personel.push_back(new Pracownik(Imie,Nazwisko,Telefon,Dzien,Miesiac,Rok,ID,Czas));
					}
					if(Stanowisko=="Manager")
					{
						//Czas pracy, Ilosc podwladnych, Wynagrodzenie(?)
						std::string czas, podwladni, wynagrodzenie;
						unsigned short int Czas, Podwladni;
						double Wynagrodzenie;
						getline(linestream,wynagrodzenie,',');
						Wynagrodzenie = atof(wynagrodzenie.c_str());
						getline(linestream,czas,',');
						Czas = atoi(czas.c_str());
						getline(linestream,podwladni,'\,');
						Podwladni = atoi(podwladni.c_str());

						Personel.push_back(new Manager(Imie,Nazwisko,Telefon,Wynagrodzenie,Czas,Podwladni));
					}
					//Stanowisko Prezesa -> Prezes Salonu (???)
					//Klient ???

				}
			}
		}
		else
		{
			plik.close();
			return false;
		}
		plik.close();
		return true;
	}
	catch(...)
	{
		return false;
	}
}

void Salon::WyswietlPersonel()
{
	//system("cls");
	std::cout<<"-----------------------------------Personel------------------------------------\n\n";
	std::cout<<"   Imi�   "<<"|"<<" Nazwisko "<<"|"<<" Data ur. "<<"|"<<" Telefon "<<"|"<<"Czas"<<"|"<<" ID "<<"|"<<" Podw�adni "<<"|"<<" Wynagrodzenie "<<std::endl;
	std::cout<<"==============================================================================="<<std::endl;
	for(unsigned int i=0; i<Personel.size(); ++i)
	{
		Personel[i]->Wyswietl();
	}
}

unsigned short int Salon::GetPos(const unsigned short int id) const
{
	for(int i=0; i<this->Personel.size();++i)
	{
		if(this->Personel[i]->getType() == typeid(Pracownik*).name())	//Czy Osoba jest pracownikiem
		{
			if(((Pracownik&)*this->Personel[i]).GetID()==id)
			{
				return i;
			}
		}
	}
return -1;
}

//------------------Sprzedane samochody

bool Salon::ZaladujBazeSprzedanych()
{
	try
	{
		std::string nazwa = "sprzedane";
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
					std::string id, dzien, miesiac, rok, Marka, Model, nadwozie, naped, masa, masadop, cena, temp;
					double Masa, MasaDop, Cena;
					unsigned short int ID, Dzien, Miesiac, Rok;
					Typ Nadwozie;
					Rodzaj Naped;

					std::istringstream linestream(linia);

					getline(linestream,id,',');
					ID=atoi(id.c_str());

					getline(linestream,dzien,',');
					Dzien=atoi(dzien.c_str());
					getline(linestream,miesiac,',');
					Miesiac=atoi(miesiac.c_str());
					getline(linestream,rok,',');
					Rok=atoi(rok.c_str());

					getline(linestream,Marka,',');
					SprawdzPrzecinki(Marka,linestream);	//Sprawdza wyst�puj�ce przecinki. Je�eli s� w " " to je dodaje do nazwy.

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

					if(naped=="Prz�d")Naped=Prz�d;
					if(naped=="Ty�")Naped=Ty�;
					if(naped=="Obie_osie")Naped=Obie_osie;

					if(nadwozie=="Hatchback")Nadwozie=Hatchback;
					if(nadwozie=="Sedan")Nadwozie=Sedan;
					if(nadwozie=="Kombi")Nadwozie=Kombi;
					if(nadwozie=="SUV")Nadwozie=SUV;
					if(nadwozie=="Dostawczy")Nadwozie=Dostawczy;

					this->Personel[this->GetPos(ID)]->SprzedajSamochod(*new SprzedanySamochod(*new Samochod(Masa,MasaDop,Cena,Marka,Model,Naped,Nadwozie),*new Data(Dzien,Miesiac,Rok)));
				}
			}
		}
		else
		{
			plik.close();
			return false;
		}
		plik.close();
		return true;
	}
	catch(...)
	{
		return false;
	}
}