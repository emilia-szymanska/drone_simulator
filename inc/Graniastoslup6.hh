#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include "Macierz.hh"
#include "Obiekt_graficzny.hh"
#include "API3D.hh"

class Graniastoslup6: public Obiekt_graficzny
{
	Wektor3D sr; //!< wektor bedacy srodkiem graniastoslupa
	Macierz3x3 mobrotu; //!< macierz obrotu graniastoslupa
	double R; //!< dlugosc promienia okregu opisanego na podstawie
	double h; //!< polowa wysokosci bryly
  public:
	Graniastoslup6() {sr = Wektor3D(0,0,0); mobrotu = Macierz3x3(90, 'x'); R=1.5; h=1;} ;
	Graniastoslup6 (Wektor3D wektorsrodka, Macierz3x3 mobrot, double promien, double polowah) { sr=wektorsrodka; mobrotu=mobrot; R=promien; h=polowah; };  
	void przesunowektor(Wektor3D wektor);
	void obrocokat(double kat, char znak, Wektor3D srodek_obrotu);
	void obrocomacierz(Macierz3x3 macierzdopowtorki);
	std::vector<Wektor3D> pobierzpunkty() const;
	Wektor3D zwroc_srodek () const;
	int rysuj(API3D *api);
	void zmien_wymiary (double skalar);
	double zwroc_wysokosc() const;
	double zwroc_promien() const;
	void zmien_srodek (Wektor3D wektor);
};

#endif
