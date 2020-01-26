#include "Dron.hh"

//inicjalizacja zmiennej statycznej
int Dron::ile_bylo_dronow=0;

//inicjalizacja zmiennej statycznej
int Dron::ile_jest_dronow=0;


/*
 * \brief Parametryczny konstruktor drona
 * \param wektorsrodka opisuje srodek drona
 * \param alfa opisuje obrot wokol osi
 * \param a opisuje polowe dlugosci jednego z bokow korpusu
 * \param b opisuje polowe dlugosci jednego z bokow korpusu
 * \param c opisuje polowe dlugosci jednego z bokow korpusu
 * \param R opisuje promien okregu opisanego na podstawie wirnika
 * \param h opisuje polowe wysokosci wirnika
 */

Dron::Dron (Wektor3D wektorsrodka, double alfa, double a, double b, double c, double R, double h, int id /*, APIrys::Kolor kolorek, double grubosc*/ ) :korpus(wektorsrodka, Macierz3x3(alfa, 'z'), a, b, c, false) 
{ 	
	std::vector<Wektor3D> wektor=korpus.zwroc4srodki(h);
	Macierz3x3 mobrotu=Macierz3x3(alfa, 'z');
	wirniki[0]=Graniastoslup6(wektor[0], mobrotu, R, h ); 
	wirniki[1]=Graniastoslup6(wektor[1], mobrotu, R, h ); 
	wirniki[2]=Graniastoslup6(wektor[2], mobrotu, R, h ); 
	wirniki[3]=Graniastoslup6(wektor[3], mobrotu, R, h ); 
	sr=wektorsrodka; 
	kat=0.0;
	for (int i=0; i<5; i++) tab_id[i]=0;
	predkosc=1;
	ID=id;
	ile_jest_dronow++;
	ile_bylo_dronow++;

}

Wektor3D Dron::zwroc_srodek() const
{
	return sr;
}


int Dron::zwroc_id() const
{
	return ID;
}

void Dron::przypisz_predkosc(double jak_szybko)
{
	predkosc=predkosc*jak_szybko;
	return;
}

void Dron::zmien_rozmiar(double skalar, API3D * api)
{
	korpus.zmien_wymiary(skalar);
	for (int i=0; i<4; i++) wirniki[i].zmien_wymiary(skalar);
	double h=wirniki[0].zwroc_wysokosc();
	std::vector<Wektor3D> wektor=korpus.zwroc4srodki(h);
	for (int i=0; i<4; i++) wirniki[i].zmien_srodek(wektor[i]);
	rysuj(api);
	return;
}


void Dron::animuj_ruch_przod(API3D *api, double odleglosc, double alfa)
{
//	odleglosc=odleglosc/100.0;
//	for(int i=0; i<100; i++) 
//	{
		przod(odleglosc, alfa);
		for (int j=0; j<4; j++)	wirniki[j].obrocokat(10, 'z', wirniki[j].zwroc_srodek());
		rysuj(api);
		usleep(10000/predkosc);
//	}
	return;
}

void Dron::animuj_obrot(API3D *api, double alfa)
{
//	alfa=alfa/100.0;
//	for (int i=0; i<100; i++)
//	{
		obrot(alfa);
		for (int j=0; j<4; j++)	wirniki[j].obrocokat(10, 'z', wirniki[j].zwroc_srodek());
		rysuj(api);
		usleep(10000/predkosc);
//	}
	return;
}

/*
 *\brief Metoda przesuwajaca drona wprzod o dana odleglosc pod danym katem do powierzchni 
 *\param odleglosc precyzuje odlegosc, jaka ma pokonac dron (po skosie)
 *\param alfa opisuje kat, jaki ma byc pomiedzy torem ruchu drona a powierzchnia do niego rownolegla
 */

void Dron::przod (double odleglosc, double alfa) 
{
	Macierz3x3 macierzobrotu = korpus.zwroc_mobrotu(); 
	alfa=torad(alfa);
	double y=odleglosc*cos(alfa);
	double z=odleglosc*sin(alfa);
	Wektor3D wektorprzesuniecia = macierzobrotu*Wektor3D(0, y, z);
	korpus.przesunowektor(wektorprzesuniecia);
	sr=korpus.zwroc_srodek();
	for (int i=0; i<4; i++)	wirniki[i].przesunowektor(wektorprzesuniecia);
	return;
} 

/*
 * \brief Metoda obracajaca dronem wokol jego osi
 * \param alfa kat, o jaki chcemy obrocic drona wzgledem jego wlasnej osi
 */

void Dron::obrot (double alfa)
{
	korpus.obrocokat(alfa, 'z');
	sr=korpus.zwroc_srodek();
	for (int i=0; i<4; ++i) wirniki[i].obrocokat(alfa, 'z', korpus.zwroc_srodek());
	return;	
}

/*
 * \brief Dziedziczona metoda rysujaca drona
 * \param api wskaznik na przestrzen, w ktorej rysujemy drona
 */

int Dron::rysuj(API3D *api) 
{
	for (int i=0; i<5; ++i) api-> wymaz_ksztalt(tab_id[i]);
	tab_id[0]=korpus.rysuj(api);
	for (int i =1; i<5; i++) tab_id[i]=wirniki[i-1].rysuj(api);
	api->rysuj();
	return 0;
}


bool Dron::sprawdz_czy_kolizja (Wektor3D wektor_srodka_walca, std::vector<double> dane2) const
{
	std::vector<double> dane1 = this->pobierz_dane_kolizja();
	Wektor3D wektor_odleglosci = (this->zwroc_srodek_kolizja() - wektor_srodka_walca);
	
	double dlugosc_poziom = Wektor3D(wektor_odleglosci[0], wektor_odleglosci[1], 0).dlugosc();
	double dlugosc_pion =  Wektor3D(0, 0, wektor_odleglosci[2]).dlugosc();

	if(dlugosc_pion<=dane1[0]+dane2[0] && dlugosc_poziom<=dane1[1]+dane2[1]) return true;
	return false;
}
		
Wektor3D Dron::zwroc_srodek_kolizja() const
{
	double z = wirniki[0].zwroc_wysokosc(); //polowa wysokosci wirnika plus polowa wysokosci korpusu
	Wektor3D wektor_przesuniecia = Wektor3D(0, 0, z); //zwiekszenie wysokosci polozenia
	//cout<<"Wektor1: "<<wektor_przesuniecia<<endl;
	//cout<<"Wektor2: "<<sr<<endl;
	//cout<<"Wektor3: "<<korpus.zwroc_srodek()<<endl;
	return sr+wektor_przesuniecia;
}

std::vector<double> Dron::pobierz_dane_kolizja() const
{
	std::vector<double> dane;
	std::vector<double> wymiary = korpus.zwroc_wymiary();
	double wysokosc = wirniki[0].zwroc_wysokosc() + wymiary[2]; //h+c
	double promien = wirniki[0].zwroc_promien() + std::sqrt(wymiary[0] * wymiary[0] +  wymiary[1] * wymiary[1]); //R+ pierw(a^2+b^2) 
	dane.push_back(wysokosc);
	dane.push_back(promien);

	return dane;
}
/*
Wektor3D Dron::odleglosc_miedzy_obiektami (Dron dron) const
{
	Wektor3D wektor_odleglosci = (this->zwroc_srodek_kolizja() - dron.zwroc_srodek_kolizja());
	return wektor_odleglosci;
}
*/
/*
void Dron::animuj(API3D *api, int co_robic, double odleglosc, double alfa)
{
	if(co_robic==1) 
	{
		odleglosc=odleglosc/100.0;
		for(int i=0; i<100; i++) 
		{
		
			przod(odleglosc, alfa);
			for (int j=0; j<4; j++)	wirniki[j].obrocokat(10, 'z', wirniki[j].zwroc_srodek());
			rysuj(api);
			usleep(10000/predkosc);
		}
	}

	if(co_robic==2)
	{
		alfa=alfa/100.0;
		for (int i=0; i<100; i++)
		{
			obrot(alfa);
			for (int j=0; j<4; j++)	wirniki[j].obrocokat(10, 'z', wirniki[j].zwroc_srodek());
			rysuj(api);
			usleep(10000/predkosc);
		}
	}

	return;
}
*/
/*
void Dron::statystyka_dronow()
{
	cout<<"Laczna ilosc stworzonych obiektow klasy Dron: "<< ile_bylo_dronow << endl;
	cout<<"Ilosc istniejacych obiektow klasy Dron:       "<< ile_jest_dronow << endl;
}
*/
/*
 * \brief Konstruktor kopiujacy klasy Wektor
 */
/*
Dron::Dron(const Dron & droniszcze): korpus(Wektor3D(), Macierz3x3(), 2, 2, 2, false) 
{
	korpus=droniszcze.korpus;
	for (int i=0; i<4; i++) wirniki[i]=droniszcze.wirniki[i];
	sr=droniszcze.sr; 
	for (int i=0; i<5; i++) tab_id[i]=droniszcze.tab_id[i];
	predkosc=droniszcze.predkosc;
	ID=droniszcze.ID;
	ile_jest_dronow++;
	ile_bylo_dronow++;
}
*/


