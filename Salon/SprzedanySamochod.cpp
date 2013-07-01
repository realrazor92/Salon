#include "SprzedanySamochod.h"

SprzedanySamochod::SprzedanySamochod(Samochod samochod, Data data)
	:Samochod(samochod), DataSprzedazy(data)
{}

void SprzedanySamochod::Wyswietl(unsigned short int ID)
{
	std::cout<<std::fixed<<std::setfill(' ')<<std::setw(13)<<this->getMarka()<<", "				//Marka
			<<std::fixed<<std::setfill(' ')<<std::setw(13)<<this->getModel()<<", "				//Model
			<<std::setw(9)<<std::fixed<<std::setprecision(2)<<this->getCena()<<" zl,"			//Cena
			<<std::setw(16)<<DataSprzedazy<<", "												//Data sprzedazy
			<<std::fixed<<std::setfill(' ')<<std::setw(14)<<ID									//ID sprzedawcy
			<<std::endl;																		//Cena

}

std::string SprPrzecinki (std::string bufor)
{
	size_t pos = bufor.find(",");
	if( pos == std::string::npos )
		return bufor;
	else
	{
		std::string przecinek = "\",\"";
		std::string temp1 = bufor.substr(0,pos);
		std::string temp2 = bufor.substr(pos+1,bufor.size());
		bufor.clear();
		bufor=temp1 + przecinek + temp2;
		return bufor;
	}
}

std::ostream & operator <<(std::ostream &Strumien, SprzedanySamochod &S)
{
	Strumien <<std::fixed<<std::setfill('0') << std::setw(2) << S.DataSprzedazy.Dzien<< "," 
		<< std::fixed<<std::setfill('0') << std::setw(2) << S.DataSprzedazy.Miesiac << "," 
		<< S.DataSprzedazy.Rok << "," 
		<< SprPrzecinki(S.getMarka()) << "," << SprPrzecinki(S.getModel()) << ","
		<< S.getNadwozie() << "," << S.getNaped() << "," 
		<< std::setprecision(2) << S.getMasaPojazdu() << ","
		<< std::setprecision(2) << S.getMasaDopuszczalna() << ","
		<< std::setprecision(2) << S.getCena() << std::endl;
	return Strumien;
}