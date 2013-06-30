#include "SprzedanySamochod.h"

SprzedanySamochod::SprzedanySamochod(Samochod samochod, Data data)
	:Samochod(samochod), DataSprzedazy(data)
{}

void SprzedanySamochod::Wyswietl(unsigned short int ID)
{
	std::cout<<std::fixed<<std::setfill(' ')<<std::setw(13)<<this->getMarka()<<", "				//Marka
			<<std::fixed<<std::setfill(' ')<<std::setw(13)<<this->getModel()<<", "				//Model
			<<std::setw(7)<<std::fixed<<std::setprecision(2)<<this->getCena()<<" zl,"			//Cena
			<<std::setw(16)<<DataSprzedazy<<", "												//Data sprzedazy
			<<std::fixed<<std::setfill(' ')<<std::setw(14)<<ID									//ID sprzedawcy
			<<std::endl;																		//Cena

}