#include "Prostopadloscian.hh"
#include "API3D.hh"

double ABS(double x)
{
	if(x<0) return -x;
	return x;
}


/*
 * \brief Metoda przesuwa srodek prostopadloscianu o zadany wektor
 * \param wektor wektor, o jaki chcemy przesunac bryle
 */

void Prostopadloscian::przesunowektor(Wektor3D wektor)
{
	sr=sr+wektor;
	return;	
}

/*
 * \brief Metoda przemnaza macierz zwiazana z obrotem o dany kat przez srodek prostopadloscianu, do kata z klasy prostokata dodawana jest wartosc kata, o jaki jest obracana figura
 * \param kat wartosc kata, o jaki chcemy obrocic bryle
 * \param znak wskazuje os, wokol ktorej ma byc wykonany obrot
 */

void Prostopadloscian::obrocokat(double kat, char znak)
{
	Macierz3x3 Macierz(kat, znak);
	mobrotu=Macierz*mobrotu;
	return;
}



/*
 *\brief Metoda obraca prostopadloscian o dana macierz obrotu
 *\param macierzdopowtorki macierz, o jaka chcemy obrocic bryle
 */

void Prostopadloscian::obrocomacierz(Macierz3x3 macierzdopowtorki)
{
	//sr=macierzdopowtorki*sr;
	mobrotu=macierzdopowtorki*mobrotu;
	return;
}
 
/*
 * \brief Metoda wyswietlajaca macierz obrotu bryly
 */
   

Macierz3x3 Prostopadloscian::zwroc_mobrotu() const
{
	return mobrotu;
}

Wektor3D Prostopadloscian::zwroc_srodek() const
{
	return sr;
}


/*
 * \brief Metoda sluzaca do pobierania wartosci 4 wektorow bedacych reprezentacja wierzcholkow prostopadloscianu. Sa one obliczane na podstawie srodka figury, dlugosci promienia opisanego na podstawie oraz kata z klasy figury. Wektory sa przekazywane przez funkcje push_back, dzieki czemu moga one byc nastepnie wykorzystane do ustawienia srodkow wirnikow.
 * \param h polowa dlugosci wysokosci wirnikow
 */


std::vector<Wektor3D> Prostopadloscian::zwroc4srodki(double h) const
{
	std::vector<Wektor3D> srodki;
	Wektor3D S1, S2, S3, S4;
	
	S1[0]=-abc[0];
	S1[1]=-abc[1];
	S1[2]=abc[2]+h;
	S1=mobrotu*S1;
	S1=sr+S1;

	S2[0]=-abc[0]; 
	S2[1]=abc[1];
	S2[2]=abc[2]+h;
	S2=mobrotu*S2;
	S2=sr+S2;
	
	S3[0]=abc[0];
	S3[1]=abc[1];
	S3[2]=abc[2]+h;
	S3=mobrotu*S3;
	S3=sr+S3;

	S4[0]=abc[0];
	S4[1]=-abc[1];
	S4[2]=abc[2]+h;
	S4=mobrotu*S4;
	S4=sr+S4;
	
	srodki.push_back(S1);
	srodki.push_back(S2);
	srodki.push_back(S3);
	srodki.push_back(S4);
	
	return srodki;
}

/*
 * \brief Metoda sluzaca do pobierania wartosci wektorow bedacych reprezentacja wierzcholkow prostopadloscianu. Sa one obliczane na podstawie srodka figury, dlugosci promienia opisanego na podstawie oraz kata z klasy figury. Wektory sa przekazywane przez funkcje push_back, dzieki czemu moga one byc nastepnie wykorzystane przez gnuplota do rysowania figury.
 */

std::vector<Wektor3D> Prostopadloscian::pobierzpunkty() const
{
	std::vector<Wektor3D> wektorro;
	Wektor3D W1, W2, W3, W4, W5, W6, W7, W8;

	W1[0]=-abc[0];
	W1[1]=-abc[1];
	W1[2]=abc[2];
	W1=mobrotu*W1;
	W1=sr+W1;

	W2[0]=-abc[0]; 
	W2[1]=abc[1];
	W2[2]=abc[2];
	W2=mobrotu*W2;
	W2=sr+W2;
	
	W3[0]=abc[0];
	W3[1]=abc[1];
	W3[2]=abc[2];
	W3=mobrotu*W3;
	W3=sr+W3;

	W4[0]=abc[0];
	W4[1]=-abc[1];
	W4[2]=abc[2];
	W4=mobrotu*W4;
	W4=sr+W4;

	W5[0]=-abc[0];
	W5[1]=-abc[1];
	W5[2]=-abc[2];
	W5=mobrotu*W5;
	W5=sr+W5;

	W6[0]=-abc[0];
	W6[1]=abc[1];
	W6[2]=-abc[2];
	W6=mobrotu*W6;
	W6=sr+W6;

	W7[0]=abc[0];
	W7[1]=abc[1];
	W7[2]=-abc[2];
	W7=mobrotu*W7;
	W7=sr+W7;

	W8[0]=abc[0];
	W8[1]=-abc[1];
	W8[2]=-abc[2];
	W8=mobrotu*W8;
	W8=sr+W8;
	
	
	wektorro.push_back(W5);
	wektorro.push_back(W6);
	wektorro.push_back(W8);
	wektorro.push_back(W7);
	wektorro.push_back(W4);
	wektorro.push_back(W3);
	wektorro.push_back(W1);
	wektorro.push_back(W2);
	
	return wektorro;
}

/*
 * \brief Metoda wyswietlajaca wspolrzedne wierzcholkow
 */

void Prostopadloscian::wyswietl_wierzcholki() const
{
	std::vector<Wektor3D> wektorix=this->pobierzpunkty();
	cout<<fixed<<setprecision(10)<<wektorix[0]<<endl<<wektorix[1]<<endl<<wektorix[2]<<endl<<wektorix[3]<<endl<<wektorix[4]<<endl<<wektorix[5]<<endl<<wektorix[6]<<endl<<wektorix[7]<<endl;
}


/*
 *\brief Metoda dziedziczona rysujaca prostopadloscian na zielono
 *\param api wskaznik na przestrzen, w ktorej rysujemy bryle
 */

int Prostopadloscian::rysuj(API3D *api)
{	
	std::vector<Wektor3D> wektorix=this->pobierzpunkty();
  	int id_figury;
  	id_figury=api->rysuj_prostopadloscian(wektorix, APIrys::zielony/* double grubosc_linii*/, czy_rysuj);
	return id_figury;
}

/*
 * \brief Metoda wyswietlajaca komunikat informujacy, czy przeciwlegle boki sa sobie rowne i jakie sa ich wartosci.
 */

void Prostopadloscian::wyswietlczypoprawne() const
{
	std::vector<Wektor3D> wektorix=this->pobierzpunkty();
	
	double a=(wektorix[6]-wektorix[4]).dlugosc();
	double b=(wektorix[6]-wektorix[7]).dlugosc();
	double c=(wektorix[0]-wektorix[6]).dlugosc();
	
	double a2=(wektorix[0]-wektorix[2]).dlugosc();
	double b2=(wektorix[4]-wektorix[5]).dlugosc();
	double c2=(wektorix[2]-wektorix[4]).dlugosc();
	
	double a3=(wektorix[5]-wektorix[7]).dlugosc();
	double b3=(wektorix[3]-wektorix[2]).dlugosc();
	double c3=(wektorix[3]-wektorix[5]).dlugosc();
	
	double a4=(wektorix[1]-wektorix[3]).dlugosc();
	double b4=(wektorix[0]-wektorix[1]).dlugosc();
	double c4=(wektorix[1]-wektorix[7]).dlugosc();
	
	int czya=0;
	int czyb=0;
	int czyc=0;
	if(ABS(a-a2)<0.0000000001 && ABS(a2-a3)<0.0000000001 && ABS(a3-a4)<0.0000000001) czya=1;
	if(ABS(b-b2)<0.0000000001 && ABS(b2-b3)<0.0000000001 && ABS(b3-b4)<0.0000000001) czyb=1;
	if(ABS(c-c2)<0.0000000001 && ABS(c2-c3)<0.0000000001 && ABS(c3-c4)<0.0000000001) czyc=1;
	
	if(czya==1) cout<<"Krotsze przeciwlegle boki sa sobie rowne"<<endl;
	else cout<< "Krotsze przeciwlegle boki nie sa sobie rowne"<<endl;
	cout<<"Dlugosc pierwszego boku: "<<fixed<<setprecision(9)<<a<<endl;
	cout<<"  Dlugosc drugiego boku: "<<a2<<endl;
	cout<<" Dlugosc trzeciego boku: "<<a3<<endl;
	cout<<" Dlugosc czwartego boku: "<<a4<<endl;
	
	if(czyb==1) cout<<"Dluzsze przeciwlegle boki sa sobie rowne"<<endl;
	else cout<< "Dluzsze przeciwlegle boki nie sa sobie rowne"<<endl;
	cout<<"Dlugosc pierwszego boku: "<<fixed<<setprecision(9)<<b<<endl;
	cout<<"  Dlugosc drugiego boku: "<<b2<<endl;
	cout<<" Dlugosc trzeciego boku: "<<b3<<endl;
	cout<<" Dlugosc czwartego boku: "<<b4<<endl;

	if(czyc==1) cout<<"Poprzeczne przeciwlegle boki sa sobie rowne"<<endl;
	else cout<< "Poprzeczne przeciwlegle boki nie sa sobie rowne"<<endl;
	cout<<"Dlugosc pierwszego boku: "<<fixed<<setprecision(9)<<c<<endl;
	cout<<"  Dlugosc drugiego boku: "<<c2<<endl;
	cout<<" Dlugosc trzeciego boku: "<<c3<<endl;
	cout<<" Dlugosc czwartego boku: "<<c4<<endl;
	
	return;
}


void Prostopadloscian::zmien_wymiary (double skalar)
{
	for (int i=0; i<3; i++) abc[i]=abc[i]*skalar;
	return;
}
		
std::vector<double> Prostopadloscian::zwroc_wymiary() const
{
	std::vector<double> wymiary;
	wymiary.push_back(abc[0]);
	wymiary.push_back(abc[1]);
	wymiary.push_back(abc[2]);
	return wymiary;

}

double Prostopadloscian::zwroc_wysokosc() const
{
	return abc[2];
}
