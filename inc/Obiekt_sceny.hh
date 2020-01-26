#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH

#include <iostream>
#include "Wektor.hh"
#include "API3D.hh"

class Obiekt_sceny
{
	static int ile_jest_obiektow;
	static int ile_bylo_obiektow;
	
	public:
		Obiekt_sceny() {ile_jest_obiektow++; ile_bylo_obiektow++;};
		~Obiekt_sceny() {ile_jest_obiektow--; };
		Obiekt_sceny(const Obiekt_sceny & obiekcik) {ile_jest_obiektow++; ile_bylo_obiektow++;};
		static void statystyka_obiektow();
		virtual bool sprawdz_czy_kolizja (Wektor3D wektor_srodka_walca, std::vector<double> dane2) const {return false;};
		//virtual Wektor3D odleglosc_miedzy_obiektami (Wektor3D srodek_drona) const {return Wektor3D();};
};

#endif
