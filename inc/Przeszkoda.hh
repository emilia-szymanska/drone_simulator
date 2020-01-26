#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH	

#include "Prostopadloscian.hh"
#include "Obiekt_sceny.hh"
#include "Dron.hh"

class Przeszkoda: public Prostopadloscian, public Obiekt_sceny
{
	public:
		Przeszkoda (Wektor3D wektorsrodka, Macierz3x3 mobrot, double polowaa, double polowab, double polowac, bool czy_rysowac) { sr=wektorsrodka; mobrotu=mobrot; abc[0]=polowaa; abc[1]=polowab;abc[2]=polowac; czy_rysuj=czy_rysowac;};  
		bool sprawdz_czy_kolizja (Wektor3D wektor_srodka_walca, std::vector<double> dane2) const;
		//Wektor3D odleglosc_miedzy_obiektami (Wektor3D srodek_drona) const;		
};
#endif
