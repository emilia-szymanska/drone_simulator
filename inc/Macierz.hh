#ifndef MACIERZ_HH
#define MACIERZ_HH


#include "Wektor.hh"


const double Pi=3.14;

template <unsigned int Wymiar>
class Macierz 
{
  	Wektor<Wymiar> tab[Wymiar];
  	public:
	Macierz ();
	Macierz (double alfa, char znak);
  	Wektor<Wymiar> & operator [] (unsigned int index);
  	const Wektor<Wymiar> & operator [] (unsigned int index) const;
};



template <unsigned int Wymiar>
Wektor<Wymiar> operator * (Macierz<Wymiar> macierz, Wektor<Wymiar> wektor)
{
	Wektor<Wymiar> wektor2;
	for(unsigned int i=0; i<Wymiar; i++) wektor2[i]=macierz[i]*wektor;
	return wektor2;
}

//Przeciazenie operatora mnozenia dla dwoch macierzy
//Zwracana jest macierz

template <unsigned int Wymiar>
Macierz<Wymiar> operator * (Macierz<Wymiar> macierz1, Macierz<Wymiar> macierz2)
{
	Macierz<Wymiar> macierz3;
	
	macierz3[0][0]=0;
	macierz3[0][1]=0;
	macierz3[0][2]=0;
	macierz3[1][0]=0;	
	macierz3[1][1]=0;
	macierz3[1][2]=0;
	macierz3[2][0]=0;
	macierz3[2][1]=0;
	macierz3[2][2]=0;
	
	for(unsigned int i=0; i<Wymiar; i++)
	{
		for (unsigned int j=0; j<Wymiar; j++)
		{
			for(unsigned int k=0; k<Wymiar; k++)
			{
				macierz3[i][j]+=macierz1[i][k]*macierz2[k][j];
			}
		}
	}
	return macierz3;
}

template <unsigned int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Mac)
{
  for(unsigned int i=0; i<Wymiar; ++i) 
   {
	   Strm<<Mac[i]<<endl;
   }
  return Strm;  
}

template <unsigned int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Macierz<Wymiar> &Mac)
{
  for(int unsigned i=0; i<Wymiar; ++i) Strm>>Mac[i];
  return Strm;  
}

/*
template <unsigned int Wymiar>
void wyswietlmacierz(Macierz<Wymiar> Mac)
{
	for (unsigned int i=0; i<Wymiar; i++)
	{
		wyswietlwektor(Mac[i]);
	}
	return;
}
*/

double torad(double alfa);

typedef Macierz<3> Macierz3x3;

#endif
