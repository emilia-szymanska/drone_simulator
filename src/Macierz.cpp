#include "Macierz.hh"


/*
 * \brief Bezparametryczny konstruktor macierzy jednostkowej
 */

template <unsigned int Wymiar> 
Macierz<Wymiar>::Macierz ()
{
	tab[0][0]=1;
	tab[0][1]=0;
	tab[0][2]=0;
	tab[1][0]=0;
	tab[1][1]=1;
	tab[1][2]=0;
	tab[2][0]=0;
	tab[2][1]=0;
	tab[2][2]=1;
}

/*!
 * \brief Konstruktor macierzy przypisujacy jej wartosc odpowiednich wartosci zaleznych od podanego kata (niezbedne do wyliczenia obrotu)
 * \param alfa kat obrotu macierzy
 * \param znak opisuje, wzgledem jakiej osi chcemy miec obrot
 */

template <unsigned int Wymiar> 
Macierz<Wymiar>::Macierz (double alfa, char znak)
{
	alfa=torad(alfa);
	switch(znak)
	{
		case 'x':
			tab[0][0]=1;
			tab[0][1]=0;
			tab[0][2]=0;
			tab[1][0]=0;
			tab[1][1]=cos(alfa);
			tab[1][2]=-sin(alfa);
			tab[2][0]=0;
			tab[2][1]=sin(alfa);
			tab[2][2]=cos(alfa);
			break;
		case 'y':
			tab[0][0]=cos(alfa);
			tab[0][1]=0;
			tab[0][2]=sin(alfa);
			tab[1][0]=0;
			tab[1][1]=1;
			tab[1][2]=0;
			tab[2][0]=-sin(alfa);
			tab[2][1]=0;
			tab[2][2]=cos(alfa);
			break;
		case 'z':
			tab[0][0]=cos(alfa);
			tab[0][1]=-sin(alfa);
			tab[0][2]=0;
			tab[1][0]=sin(alfa);
			tab[1][1]=cos(alfa);
			tab[1][2]=0;
			tab[2][0]=0;
			tab[2][1]=0;
			tab[2][2]=1;
			break;
		default: cerr<<"Bledna os"<<endl;
	}
}	


/*
 * \brief Przeciazenie operatora nawiasow kwadratowych dla macierzy
 * \param index indeks opisujacy, do ktorego wektora chcemy sie dostac
 */

template <unsigned int Wymiar> 
Wektor<Wymiar> & Macierz<Wymiar>::operator [] (unsigned int index)
{
	if(index>=Wymiar || index<0)
	{
		cerr<<"Bledna wartosc indeksu"<<endl;
		exit(1);
	}
	return tab[index];
}

/*
 * \brief Przeciazenie operatora nawiasow kwadratowych dla macierzy przy wartosciach typu const
 * \param index indeks opisujacy wektor, do ktorego chcemy sie dostac
 */

template <unsigned int Wymiar> 
const Wektor<Wymiar> & Macierz<Wymiar>::operator [] (unsigned int index) const
{
	if(index>=Wymiar || index<0)
	{
		cerr<<"Bledna wartosc indeksu"<<endl;
		exit(1);
	}
	return tab[index];
}
/*
 * \brief Funkcja zwracajaca wartosc kata w radianach
 * \param alfa kat, ktory chcemy zamienic ze stopni na radiany
 */

double torad(double alfa)
{
	return alfa * Pi/180.0;
}

template class Macierz<3>;
