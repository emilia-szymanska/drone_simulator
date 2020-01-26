#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

/*
 * \section intro_sec Opis
 * Kod jest odzwierciedleniem klasy Prostopadloscian, ktora odpowiada za jego reprezentacje oraz dzialanie metod z nim zwiazanych; dziedziczy po obiekcie graficznym.
 */


#include <iostream>
#include <vector>
#include <iomanip>
#include "Macierz.hh"
#include "Obiekt_graficzny.hh"
#include "API3D.hh"

using std::fixed;
using std::setprecision;

class Prostopadloscian: public Obiekt_graficzny
{
	protected:
		Wektor3D sr; //!< wektor reprezentujacy srodek prostopadloscianu
		Macierz3x3 mobrotu; //!< macierz obrotu bryly
		double abc[3]; //!< tablica przechowujaca polowy dlugosci bokow bryly
		bool czy_rysuj; //!< decyduje, czy mamy rysowac teraz czy nie
 	public:
		Prostopadloscian (Wektor3D wektorsrodka, Macierz3x3 mobrot, double polowaa, double polowab, double polowac, bool czy_rysowac) { sr=wektorsrodka; mobrotu=mobrot; abc[0]=polowaa; abc[1]=polowab;abc[2]=polowac; czy_rysuj=czy_rysowac;};  
		Prostopadloscian () {};
		void przesunowektor(Wektor3D wektor);
		void obrocokat(double kat, char znak);
		std::vector<Wektor3D> pobierzpunkty() const;
		std::vector<Wektor3D> zwroc4srodki(double h) const;
		Wektor3D zwroc_srodek() const;
		double zwroc_wysokosc() const;
		void wyswietl_wierzcholki() const;
		void wyswietlczypoprawne() const;
		void obrocomacierz(Macierz3x3 macierzdopowtorki);
		std::vector<double> zwroc_wymiary() const;
		void zmien_wymiary(double skalar);
		Macierz3x3 zwroc_mobrotu() const;
		int rysuj (API3D *api);
};


#endif
