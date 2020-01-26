#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Obiekt_graficzny.hh"
#include "Graniastoslup6.hh"
#include <unistd.h>
#include "Obiekt_sceny.hh"

/*
 * \section intro_sec Opis
 * Klasa odpowiadajaca za reprezentacje drona i zawierajaca jego metody. Dziedziczy po obiekcie graficznym
 */ 

class Dron: public Obiekt_graficzny, public Obiekt_sceny
{
	Wektor3D sr; //!< wektor bedacy srodkiem drona
	double kat; //!< kat o jaki obrocony jest dron wzgledem swojego pierwotnego polozenia w plaszczyznie osi Z
	Prostopadloscian korpus; //!< prostopadloscian bedacy korpusem drona
	Graniastoslup6 wirniki[4];  //!< graniastoslupy szesciokatne bedace wirnikami drona
	int tab_id[5];
	double predkosc;
	int ID;
	static int ile_jest_dronow;
	static int ile_bylo_dronow;

	public:
		Dron (Wektor3D wektorsrodka, double alfa, double a, double b, double c, double h, double R, int id);
		void animuj_ruch_przod (API3D *api, double odleglosc, double alfa);
		void animuj_obrot (API3D *api, double alfa);
		void przod (double odleglosc, double alfa); 
		void obrot (double alfa);
		int rysuj (API3D *api);
		void przypisz_predkosc (double jak_szybko);
		void zmien_rozmiar (double skalar, API3D *api);
		int zwroc_id() const;
		Wektor3D zwroc_srodek() const;
		Wektor3D zwroc_srodek_kolizja() const;
		std::vector<double> pobierz_dane_kolizja() const;
		bool sprawdz_czy_kolizja (Wektor3D wektor_srodka_walca, std::vector<double> dane2) const;
};


//		static void statystyka_dronow();
//		~Dron() {ile_jest_dronow--;};
//		Dron (const Dron & droniszcze);
//		void animuj (API3D *api, int co_robic, double odleglosc, double alfa);

#endif 
