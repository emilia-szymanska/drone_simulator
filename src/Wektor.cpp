#include "Wektor.hh"

/*!
 * \brief Konstruktor bezparametryczny wektora, ktory zeruje wszystkie jego wspolrzedne.
 */

template <unsigned int Wymiar>
Wektor<Wymiar>::Wektor()
{
	for(unsigned int i = 0;i<Wymiar;i++) tab[i]=0;
	ile_jest++;
	ile_bylo++;
}

/*!
 * \brief Przeciazenie operatora += dla dwoch wektorow. Metoda zmienia wartosc wektora pierwszego, dodajac do niego wartosc drugiego.
 * \param v2 wektor, o ktorego wartosc chcemy zwiekszyc wektor poczatkowy.
 */

template <unsigned int Wymiar>
Wektor<Wymiar> & Wektor<Wymiar>::operator += (Wektor & v2)
{
  for (unsigned int i=0; i<Wymiar; i++)
  {
	tab[i]+=v2[i];
  }
  return *this;
}

/*!
 * \brief Przeciazenie operatora nawiasow kwadratowych. Metoda zwraca wartosc danej wspolrzednej wektora.
 * \param index indeks wartosci, jaka chcemy uzyskac po zastosowaniu operatora.
 */

template <unsigned int Wymiar>
double & Wektor<Wymiar>::operator [] (unsigned int index)
{
	if(index>=Wymiar || index<0)
	{
	  cerr<<"Bledna wartosc indeksu"<<endl;
	  exit(2);
	}	
	return tab[index];

}

/*!
 * \brief Przeciazenie operatora nawiasow kwadratowych. Metoda zwraca wartosc typu const danej wspolrzednej wektora.
 * \param index indeks wartosci, jaka chcemy uzyskac po zastosowaniu operatora.
 */

template <unsigned int Wymiar>
const double & Wektor<Wymiar>::operator [] (unsigned int index) const
{
	if(index>=Wymiar || index<0)
	{
	  cerr<<"Bledna wartosc indeksu"<<endl;
	  exit(2);
	}	
	return tab[index];
}

/*!
 * \brief Metoda zwraca wartosc dlugosci danego wektora
 */

template <unsigned int Wymiar>
double Wektor<Wymiar>::dlugosc() const
{
	double calosc=0;
	for (unsigned int i=0; i<Wymiar; i++)
	{
		calosc+=tab[i]*tab[i];
	}
	return sqrt(calosc);	
}

/*
 * \brief Metoda wyswietlajaca wartosci zmiennych statycznych zliczajacych tworzone obiekty klasy Wektor
 */

template <unsigned int Wymiar>
void Wektor<Wymiar>::statystyka_wektorow()
{
	cout<<"Laczna ilosc stworzonych obiektow klasy Wektor3D: "<< ile_bylo << endl;
	cout<<"Ilosc istniejacych obiektow klasy Wektor3D:       "<< ile_jest << endl;
}

/*
 * \brief Konstruktor kopiujacy klasy Wektor
 */

template <unsigned int Wymiar>
Wektor<Wymiar>::Wektor(const Wektor<Wymiar> & wektorek)
{
	for(unsigned int i = 0;i<Wymiar;i++) tab[i]=wektorek.tab[i];
	ile_jest++;
	ile_bylo++;
}

template class Wektor<3>;
