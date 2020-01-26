
/*!
 * \author Emilia Szymanska
 * \date 2019-04-13
 * \section intro_sec Opis
 * Kod odwzorowuje szablon klasy Wektor dla danego wymiaru
 */


#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;


template <unsigned int Wymiar>
class Wektor 
{
  double tab[Wymiar]; //!< tablica przechowujaca wspolrzedne klasy Wektor
  static int ile_bylo; //!< zmienna statyczna zliczajaca, ile bylo stworzonych obiektow klasy Wektor
  static int ile_jest; //<! zmienna statyczna zliczajaca, ile jest obecnie utworzonych obiektow klasy Wektor
    public:
    Wektor ();
    /*!
     * \brief Konstruktor klasy Wektor tworzacy wektor w zaleznosci od parametrow.
     * \param x wartosc pierwszej wspolrzednej
     * \param y wartosc drugiej wspolrzednej
     * \param z wartosc trzeciej wspolrzednej
     */
    Wektor (double x, double y, double z) { tab[0]=x; tab[1]=y; tab[2]=z; ile_bylo++; ile_jest++;};
    ~Wektor () {ile_jest--;};
    Wektor (const Wektor & wektorek); 
    Wektor<Wymiar> & operator += (Wektor<Wymiar> & v2);
    double & operator [] (unsigned int index);
    const double & operator [] (unsigned int index) const;
    double dlugosc() const;
    static void statystyka_wektorow();
};

//inicjalizacja zmiennej statycznej
template <unsigned int Wymiar>
int Wektor<Wymiar>::ile_bylo=0;

//inicjalizacja zmiennej statycznej
template <unsigned int Wymiar>
int Wektor<Wymiar>::ile_jest=0;

/*!
 * \brief Przeciazenie operatora dodawania dla dwoch wektorow. Funkcja zwraca wektor bedacy suma dwoch wektorow.
 * \param v1 pierwszy skladnik sumy
 * \param v2 drugi skladnik sumy
 */

template <unsigned int Wymiar>
Wektor<Wymiar> operator + (Wektor <Wymiar>v1, Wektor<Wymiar> v2)
{
	Wektor<Wymiar> v3;
	for (unsigned int i=0; i<Wymiar; i++)
	 {
		v3[i]=v1[i]+v2[i];
	 }
	return v3;
}

/*!
 * \brief Przeciazenie operatora odejmowania dla dwoch wektorow. Funkcja zwraca wektor bedacy roznica dwoch wektorow.
 * \param v1 wektor bedacy odjemna
 * \param v2 wektor bedacy odjemnikiem
 */

template <unsigned int Wymiar>
Wektor<Wymiar> operator - (Wektor<Wymiar> v1, Wektor<Wymiar> v2)
{
	Wektor <Wymiar>v3;
	for (unsigned int i=0; i<Wymiar; i++)
	 {
		v3[i]=v1[i]-v2[i];
	 }
	return v3;
}

/*!
 * \brief Przeciazenie operatora porownania dla dwoch wektorow. Funkcja zwraca wartosc 1 dla prawdy, a 0 dla falszu
 * \param v1 pierwszy wektor, ktory chcemy przyrownac z drugim
 * \param v2 drugi wektor, ktory chcemy przyrownac z pierwszym
 */

template <unsigned int Wymiar>
double operator == (Wektor<Wymiar> v1, Wektor<Wymiar> v2)
{
  	for (unsigned int i=0; i<Wymiar; i++)
  	 {
		if(v1[i]!=v2[i]) return 0;
  	 }
  	return 1;
}

/*!
 * \brief Przeciazenie operatora mnozenia dla dwoch wektorow. Funkcja zwraca wartosc iloczynu skalarnego.
 * \param v1 wektor bedacy pierwszym czynnikiem mnozenia
 * \param v2 wektor bedacy drugim czynnikiem mnozenia
 */

template <unsigned int Wymiar>
double operator * (Wektor<Wymiar> v1, Wektor<Wymiar> v2)
{
	double v3=0;
	for (unsigned int i=0; i<Wymiar; i++)
	 {
		v3=v3+(v1[i]*v2[i]);
	 }
	return v3;
}


/*!
 * \brief Przeciazenie operatora wczytania. Funkcja zwraca strumien, do ktorego wczytywalismy wspolrzedne wektora.
 * \param Strm strumien, do ktorego wczytujemy wspolrzedne wektora.
 * \param Wek wektor, do ktorego przypisujemy wczytane wspolrzedne.
 */

template <unsigned int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
  for (unsigned int i=0; i<Wymiar; i++) Strm>>Wek[i];
  return Strm;
}

/*!
 * \brief Przeciazenie operatora wypisania. Funkcja zwraca strumien, za pomoca ktorego wypisujemy wspolrzedne wektora.
 * \param Strm strumien, za pomoca ktorego wypisujemy wspolrzedne wektora.
 * \param Wek wektor, ktorego wspolrzedne chcemy wypisac
 */

template <unsigned int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
  for (unsigned int i=0; i<Wymiar; i++) 
  {
	  
	 if (i==(Wymiar-1)) Strm<<Wek[i];
  	 else Strm<<Wek[i]<<" ";
  }
  return Strm;  
}

typedef Wektor<3> Wektor3D;

#endif
