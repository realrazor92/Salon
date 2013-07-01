#include "Salon.h"

extern Salon nowy;

Salon::Salon(const std::string imie, const std::string nazwisko, const std::string telefon, const unsigned short czas,
			 const std::string nazwa, const double budzet, const double przychody, const double rozchody, const double czynsz)
			 :PrezesSalonu(imie , nazwisko , telefon ,(przychody*0,1) , czas), NazwaMarki(nazwa) , Budzet(budzet) , Przychody(przychody) , Rozchody(rozchody) , Czynsz(czynsz)
{

}


double Salon::BilansSalonu()
{
	Budzet = Przychody + Rozchody;
	std::cout << "----- Bilans Salonu -----" << "\n"
		<< "Przychody salonu : " << std::setw(10) << Przychody << "\n"
		<< "Rozchody salonu : " << std::setw(10) << Rozchody << "\n"
		<< std::setw(28) << std::setfill('-') << "\n"
		<< "Ogolny bilans: " << std::setw(10) << Budzet << "\n";
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
void Salon::SprzedajSamochod(Samochod &S)
{
	int min = 0;
	int max = this->Personel.size();
	int wybor = 0;
	srand(time(NULL));

	int LosowyPracownik = rand()%(max-min+1)+min;

	this->WyswietlBazeSamochodow();

	std::cout << "Zakup samochod nr ";
	std::cin >> wybor;
	if(wybor - 1 > this->BazaSamochodow.size())
	{
		std::cout << "\n Numer spoza listy, sprobuj ponownie\n";
		this->SprzedajSamochod(S);
	}
	else
	{
		this->Personel[LosowyPracownik]->SprzedajSamochod(SprzedanySamochod(S,Data()));
		this->BazaSamochodow.erase(this->BazaSamochodow.begin() + (wybor-1));
		this->ZapiszBazeSamochodow();
	}
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

//-------------------Dostêpne samochody

bool Salon::DostawaSamochodow(std::string nazwa)	//Tu trzeba dorobiæ obs³ugê b³êdów
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
	std::cout<<"---------------------Baza aktualnie dostêpnych samochodów---------------------\n\n";
	std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<" Nadwozie "<<"|"<<" Napêd "<<"|"<<" Masa "<<"|"
		<<"Masa dop"<<"|"<<"    Cena"<<std::endl;
	std::cout<<"=============================================================================="<<std::endl;

	for(int i=0; i<nowy.BazaSamochodow_Size();++i)
	{
		std::cout<<std::setw(2)<< i+1 << ". "<<std::setw(11)<<BazaSamochodow[i].getMarka()<<", "			//Marka
			<<std::setw(13)<<BazaSamochodow[i].getModel()<<", "													//Model
			<<std::setw(9)<<BazaSamochodow[i].getNadwozie()<<", "												//Nadwozie
			<<std::setw(6)<<BazaSamochodow[i].getNaped()<<", "													//Naped
			<<std::setw(5)<<std::fixed<<std::setprecision(0)<<BazaSamochodow[i].getMasaPojazdu()<<", "			//Masa
			<<std::setw(7)<<std::fixed<<std::setprecision(0)<<BazaSamochodow[i].getMasaDopuszczalna()<<", "		//Masa dopuszczalna
			<<std::setw(7)<<std::fixed<<std::setprecision(2)<<BazaSamochodow[i].getCena()<<" zl";				//Cena

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

void Salon::WyswietlPersonel() const
{
	//system("cls");
	std::cout<<"-----------------------------------Personel------------------------------------\n\n";
	std::cout<<"   Imiê   "<<"|"<<" Nazwisko "<<"|"<<" Data ur. "<<"|"<<" Telefon "<<"|"<<"Czas"<<"|"<<" ID "<<"|"<<" Podw³adni "<<"|"<<" Wynagrodzenie "<<std::endl;
	std::cout<<"==============================================================================="<<std::endl;
	for(unsigned int i=0; i<Personel.size(); ++i)
	{
		Personel[i]->Wyswietl();
	}
}

short int Salon::GetPos(const unsigned short int id) const
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
void Salon::ZapiszBazeSprzedanych()
{

	std::ofstream Plik("sprzedane.csv");
	for(unsigned short int i = 0 ; i<Personel.size() ; ++i)
	{
		if(this->Personel[i]->getType() == typeid(Pracownik*).name())
		{
			for(unsigned short int j = 0 ; j<((Pracownik&)*Personel[i]).SprzedaneSamochody_Size() ; ++j)
			{
				Plik << ((Pracownik&)*Personel[i]).GetID() << "," << ((SprzedanySamochod&)(((Pracownik&)*Personel[i])).getSprzedanySamochod(j));
			}
		}
		if(this->Personel[i]->getType() == typeid(Manager*).name())
		{
			for(unsigned short int j = 0 ; j<((Manager&)*Personel[i]).SprzedaneSamochody_Size() ; ++j)
			{
				Plik << ((Manager&)*Personel[i]).GetID() << "," << ((SprzedanySamochod&)(((Manager&)*Personel[i])).getSprzedanySamochod(j));
			}
		}
	}

}
//Zestawienia

void Salon::ZestawienieOgolne()
{
	std::cout<<"----------------Zestawienie wszystkich sprzedanych samochodów-----------------\n\n";
	std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<"    Cena    "<<"|"<<" Data sp  "<<"|"<<" ID sprzedawcy "<<"|"<<std::endl;
	std::cout<<"=============================================================================="<<std::endl;

	for(unsigned short int i=0; i<this->Personel.size(); ++i)
	{
		if(this->Personel[i]->getType() == typeid(Pracownik*).name())	//Czy Osoba jest pracownikiem
		{
			for(unsigned short int j=0; j<((Pracownik&)*Personel[i]).SprzedaneSamochody_Size(); ++j)
			{
				((Pracownik&)*Personel[i]).getSprzedanySamochod(j).Wyswietl(((Pracownik&)*Personel[i]).GetID());
			}
		}
	}
	std::cout<<std::endl;
}

void Salon::ZestawieniePracownika(const unsigned short int ID)
{
	if(this->GetPos(ID) == -1)
	{
		std::cout<<"Nie znaleziono pracownika o takim ID!";
		_getch();
		system("cls");
	}
	else
	{
		std::cout<<"---------------------Zestawienie sprzedanych samochodów----------------------\n\n";

		std::cout<<"Dane pracownika:"<<std::endl<<std::endl;
		std::cout<<"   Imiê   "<<"|"<<" Nazwisko "<<"|"<<" Data ur. "<<"|"<<" Telefon "<<"|"<<"Czas"<<"|"<<" ID "<<std::endl;
		std::cout<<"==============================================================================="<<std::endl;
		Personel[this->GetPos(ID)]->Wyswietl();
		std::cout<<std::endl;

		std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<"    Cena    "<<"|"<<" Data sp  "<<"|"<<" ID sprzedawcy "<<"|"<<std::endl;
		std::cout<<"=============================================================================="<<std::endl;
		for(unsigned short int j=0; j<((Pracownik&)*Personel[this->GetPos(ID)]).SprzedaneSamochody_Size(); ++j)
		{
			((Pracownik&)*Personel[this->GetPos(ID)]).getSprzedanySamochod(j).Wyswietl(ID);
		}
		std::cout<<std::endl;
	}
}

void Salon::ZestawienieMiesieczne(const unsigned short Miesiac, const unsigned short Rok)
{
	system("cls");
	std::cout<<std::endl<<"---------------------Zestawienie sprzedanych samochodów-----------------------\n\n";
	std::cout<<"    Marka    "<<"|"<<"     Model    "<<"|"<<"    Cena    "<<"|"<<" Data sp  "<<"|"<<" ID sprzedawcy "<<"|"<<std::endl;
	std::cout<<"=============================================================================="<<std::endl;
	for(unsigned short int i=0; i<this->Personel.size(); ++i)
	{
		if(this->Personel[i]->getType() == typeid(Pracownik*).name())	//Czy Osoba jest pracownikiem
		{
			for(unsigned short int j=0; j<((Pracownik&)*Personel[i]).SprzedaneSamochody_Size(); ++j)
			{

				if(((Pracownik&)*Personel[i]).getSprzedanySamochod(j).GetData().Rok == Rok && ((Pracownik&)*Personel[i]).getSprzedanySamochod(j).GetData().Miesiac == Miesiac)
				{	
					((Pracownik&)*Personel[i]).getSprzedanySamochod(j).Wyswietl(((Pracownik&)*Personel[i]).GetID());
				}
			}
		}
	}
	std::cout<<std::endl;
}
