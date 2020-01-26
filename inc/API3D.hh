#ifndef API3D_HH
#define API3D_HH

#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <map>

/********************************************************
 * code given at programming course led by 
 * Ph.D. Bogdan Kreczmer and MSc Arkadiusz Mielczarek
 * at Wroclaw University of Science and Technology
 * MIT Licence
 ********************************************************/

//uzywane funkcje z biblioteki standardowej
using std::vector;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::stringstream;
using std::map;
using std::pair;
using std::make_pair;

namespace APIrys {
  enum Kolor {domyslny = 0, fioletowy = 1, zielony = 2, blekitny = 3, pomaranczowy = 4, zolty = 5, niebieski = 6, czerwony = 7, czarny = 8};
}

//interfejs dla implementacji rysowania dla roznych platform
class API3D {
public:
  virtual int rysuj_linie(const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true) = 0;
  virtual int rysuj_prostopadloscian(const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true) = 0; //czy na pewno ma dobra nazwe/argumenty?
  virtual int rysuj_graniastoslup6(const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true) = 0; //czy na pewno ma dobra nazwe/argumenty?
  virtual void wymaz_ksztalt(int indeks, bool rysuj_od_razu = false) = 0;
  virtual void aktualizuj_linie(int indeks, const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true) = 0;
  virtual void aktualizuj_prostopadloscian(int indeks, const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true) = 0; //czy na pewno ma dobra nazwe/argumenty?
  virtual void rysuj() = 0;
};

//implementacja rysowania w GNU plocie za pomoca lacza do GNU plota
class APIGnuPlot3D : public API3D, private PzG::LaczeDoGNUPlota {

  // zmienne potrzebne do okreslania jakie pliki z danymi maja byc brane pod uwage
  int l_stworzone_ob;
  map<int,int> istniejace_obiekty; //pary (numer,kolor). Kolory wg. domyslej palety gnuplota
public:
  //konstruktor z argumentami okreslajacymi wielkosc sceny
  APIGnuPlot3D(double minX,double maxX,double minY,double maxY,double minZ,double maxZ);
  //implementacje funkcji z interfejsu - zwracany int okresla jakie id zostalo przydzielone ksztaltowi
  int rysuj_linie(const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true);
  int rysuj_prostopadloscian(const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true); //czy na pewno ma dobra nazwe/argumenty?
  
  int rysuj_graniastoslup6(const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true); //czy na pewno ma dobra nazwe/argumenty?
  
  void wymaz_ksztalt(int indeks, bool rysuj_od_razu = false);
  void aktualizuj_linie(int indeks, const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true);
  void aktualizuj_prostopadloscian(int indeks, const vector<Wektor3D> & pts, APIrys::Kolor kolor = APIrys::domyslny, bool rysuj_od_razu = true); //czy na pewno ma dobra nazwe/argumenty?
  void rysuj();
};


#endif
