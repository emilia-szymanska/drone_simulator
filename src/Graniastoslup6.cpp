#include "Graniastoslup6.hh"

/*
 * \brief Metoda przesuwa srodek graniastoslupa o zadany wektor
 * \param wektor wektor, o jaki chcemy przesunac bryle
 */

void Graniastoslup6::przesunowektor(Wektor3D wektor)
{
	sr=sr+wektor;
	return;	
}

/*
 * \brief Metoda przemnaza macierz zwiazana z obrotem o dany kat przez srodek graniastoslupa, do kata z klasy prostokata dodawana jest wartosc kata, o jaki jest obracana figura
 * \param kat wartosc kata, o jaki chcemy obrocic bryle
 * \param znak wskazuje os, wokol ktorej ma byc wykonany obrot
 */

void Graniastoslup6::obrocokat(double kat, char znak, Wektor3D srodek_obrotu)
{
	Macierz3x3 Macierz =  Macierz3x3(kat, znak);
	sr=sr-srodek_obrotu;
	sr=Macierz*sr;	
	sr=sr+srodek_obrotu;
	mobrotu=Macierz*mobrotu;
	return;
}

/*
 *\brief Metoda obraca graniastoslup o dana macierz obrotu
 *\param macierzdopowtorki macierz, o jaka chcemy obrocic bryle
 */

Wektor3D Graniastoslup6::zwroc_srodek () const
{
	return sr;
}

void Graniastoslup6::obrocomacierz(Macierz3x3 macierzdopowtorki)
{
	mobrotu=macierzdopowtorki*mobrotu;
	return;
}


/*
 * \brief Metoda sluzaca do pobierania wartosci wektorow bedacych reprezentacja wierzcholkow graniastoslupa. Sa one obliczane na podstawie srodka figury, dlugosci promienia opisanego na podstawie oraz kata z klasy figury. Wektory sa przekazywane przez funkcje push_back, dzieki czemu moga one byc nastepnie wykorzystane przez gnuplota do rysowania figury.
 */

std::vector<Wektor3D> Graniastoslup6::pobierzpunkty() const
{
	std::vector<Wektor3D> wektorro;
	Wektor3D W1, W2, W3, W4, W5, W6, W7, W8, W9, W10, W11, W12;

	W1[0]=0;
	W1[1]=R;
	W1[2]=-h;
	W1 = Macierz3x3(0 ,'z') * W1;
	W1=mobrotu*W1;
	W1=sr+W1;

	W2[0]=0;
	W2[1]=R;
	W2[2]=-h;
	W2 = Macierz3x3(60 ,'z') * W2;
	W2=mobrotu*W2;
	W2=sr+W2;
	
	W3[0]=0;
	W3[1]=R;
	W3[2]=-h;
	W3 = Macierz3x3(120 ,'z') * W3;
	W3=mobrotu*W3;
	W3=sr+W3;

	W4[0]=0;
	W4[1]=R;
	W4[2]=-h;
	W4=Macierz3x3(180, 'z') * W4;
	W4=mobrotu*W4;
	W4=sr+W4;

	W5[0]=0;
	W5[1]=R;
	W5[2]=-h;
	W5=Macierz3x3(240, 'z') * W5;
	W5=mobrotu*W5;
	W5=sr+W5;

	W6[0]=0;
	W6[1]=R;
	W6[2]=-h;
	W6 = Macierz3x3(300, 'z') * W6;
	W6=mobrotu*W6;
	W6=sr+W6;

	W7[0]=0;
	W7[1]=R;
	W7[2]=h;
	W7=Macierz3x3(0, 'z') * W7;
	W7=mobrotu*W7;
	W7=sr+W7;

	W8[0]=0;
	W8[1]=R;
	W8[2]=h;
	W8=Macierz3x3(60, 'z') * W8;
	W8=mobrotu*W8;
	W8=sr+W8;
	
	W9[0]=0;
	W9[1]=R;
	W9[2]=h;
	W9=Macierz3x3(120, 'z') * W9;
	W9=mobrotu*W9;
	W9=sr+W9;
	
	W10[0]=0;
	W10[1]=R;
	W10[2]=h;
	W10=Macierz3x3(180, 'z') * W10;
	W10=mobrotu*W10;
	W10=sr+W10;
	
	W11[0]=0;
	W11[1]=R;
	W11[2]=h;
	W11=Macierz3x3(240, 'z') * W11;
	W11=mobrotu*W11;
	W11=sr+W11;
	
	W12[0]=0;
	W12[1]=R;
	W12[2]=h;
	W12=Macierz3x3(300, 'z') * W12;
	W12=mobrotu*W12;
	W12=sr+W12;
	

	wektorro.push_back(W1);
	wektorro.push_back(W2);
	wektorro.push_back(W3);
	wektorro.push_back(W4);
	wektorro.push_back(W5);
	wektorro.push_back(W6);
	wektorro.push_back(W7);
	wektorro.push_back(W8);
	wektorro.push_back(W9);
	wektorro.push_back(W10);
	wektorro.push_back(W11);
	wektorro.push_back(W12);
	
	return wektorro;
}
 
/*
 *\brief Metoda dziedziczona rysujaca graniastoslup szeciokatny na zielono
 *\param api wskaznik na przestrzen, w ktorej rysujemy bryle
 */

int Graniastoslup6::rysuj(API3D *api /*, double grubosc_linii, APIrys::Kolor kolor*/)
{		
	std::vector<Wektor3D> wektorix=this->pobierzpunkty();
  	int id_figury;
  	id_figury=api->rysuj_graniastoslup6(wektorix, /*grubosc_linii,*/ APIrys::zielony, false);
  	return id_figury;
}


void Graniastoslup6::zmien_wymiary (double skalar)
{
	R=R*skalar;
	h=h*skalar;
	return;
}

double Graniastoslup6::zwroc_wysokosc () const
{
	return h;
}

double Graniastoslup6::zwroc_promien () const
{
	return R;
}

void Graniastoslup6::zmien_srodek (Wektor3D wektor)
{
	sr=wektor;
	return;
}
