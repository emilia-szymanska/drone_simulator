#include "Scena.hh"

Scena::Scena()
{
  Wektor3D wek1=Wektor3D();
  Wektor3D wek2=Wektor3D(-20, -20, -20);
  Wektor3D wek3=Wektor3D(20, 20, 20); 
  Wektor3D wek4=Wektor3D(10, 10, 10); 
  Wektor3D wek5=Wektor3D(-10, -10, -10); 
  Wektor3D wek6=Wektor3D(10, -10, 10); 
  
  Macierz3x3 mobrotu=Macierz3x3();
  
  shared_ptr<Przeszkoda> Przeszkoda1 = shared_ptr<Przeszkoda>(new Przeszkoda(wek4, mobrotu, 3, 4, 5, true)); 
  shared_ptr<Przeszkoda> Przeszkoda2 = shared_ptr<Przeszkoda>(new Przeszkoda(wek5, mobrotu, 3, 4, 5, true));
  shared_ptr<Przeszkoda> Przeszkoda3 = shared_ptr<Przeszkoda> (new Przeszkoda(wek6, mobrotu, 3, 4, 5, true));
  
  shared_ptr<Dron> Dron1 = shared_ptr<Dron>(new Dron(wek1, 0.0, 2.0, 2.5, 1.0, 1, 0.5, 1));
  shared_ptr<Dron> Dron2 = shared_ptr<Dron>(new Dron(wek2, 0.0, 3.0, 4.0, 1.0, 2, 0.5, 2));
  shared_ptr<Dron> Dron3 = shared_ptr<Dron>(new Dron(wek3, 0.0, 3.0, 4.0, 1.0, 2, 0.5, 3));
  
  obecnyDron = Dron1;
  
  listaDronow.push_back(obecnyDron);
  listaDronow.push_back(Dron2);
  listaDronow.push_back(Dron3);

  listaObiektow.push_back(obecnyDron);
  listaObiektow.push_back(Dron2);
  listaObiektow.push_back(Dron3);
  listaObiektow.push_back(Przeszkoda1);
  listaObiektow.push_back(Przeszkoda2);
  listaObiektow.push_back(Przeszkoda3);
  
  listaSceny.push_back(obecnyDron);
  listaSceny.push_back(Dron2);
  listaSceny.push_back(Dron3);
  listaSceny.push_back(Przeszkoda1);
  listaSceny.push_back(Przeszkoda2);
  listaSceny.push_back(Przeszkoda3);
  
}

void Scena::wspolrzedne_dronow() const
{
	cout<<"Mozliwe wybory dronow: "<<endl;
	for(shared_ptr<Dron> latacz : listaDronow)
	{
		cout<<"Dron"<<latacz->zwroc_id()<<": "<<latacz->zwroc_srodek()<<endl;
	}
	return;
}


void Scena::zmien_drona(int id)
{

	for(shared_ptr<Dron> latacz : listaDronow)
	{
		if(latacz->zwroc_id() == id)
		{
			obecnyDron = latacz;
		}
	}
}


int Scena::nr_id_obecnego() const
{
	return obecnyDron->zwroc_id();
}

shared_ptr<Dron> Scena::pobierz_obecnego_drona() const
{
	return obecnyDron;
}


void Scena::rysuj(API3D *api) const
{
	for (shared_ptr<Obiekt_graficzny> stojacz : listaObiektow) stojacz->rysuj(api);
	return;
}



int Scena::animuj_scene (API3D *api, double kat, double odleglosc)
{
	Wektor3D srodek_walca;
	std::vector<double> dane2;
	if(odleglosc==0)
	 {
		kat=kat/100.0;
		for(int i=0; i<100; i++)
		 {
			for(shared_ptr<Obiekt_sceny> obiekcik : listaSceny)
			 {
				if (obiekcik==obecnyDron) continue; 
				else 
				 {
					srodek_walca=obecnyDron->zwroc_srodek_kolizja();
					dane2=obecnyDron->pobierz_dane_kolizja();
					if(obiekcik->sprawdz_czy_kolizja(srodek_walca, dane2)==true) 
					{
						while(obiekcik->sprawdz_czy_kolizja((obecnyDron->zwroc_srodek_kolizja()), (obecnyDron->pobierz_dane_kolizja()))) obecnyDron->animuj_obrot(api, -kat);	
						return 1;
					}
				 }
			 }		
			obecnyDron->animuj_obrot(api, kat);
		 }
	 }
	else
	 {
		odleglosc=odleglosc/100.0;
		for(int i=0; i<100; i++)
		 {
			for(shared_ptr<Obiekt_sceny> obiekcik : listaSceny)
			 {
				if (obiekcik==obecnyDron) continue; 
				else 
				 {
					srodek_walca=obecnyDron->zwroc_srodek_kolizja();
					dane2=obecnyDron->pobierz_dane_kolizja();
					if(obiekcik->sprawdz_czy_kolizja(srodek_walca, dane2)==true)
					{
						while(obiekcik->sprawdz_czy_kolizja((obecnyDron->zwroc_srodek_kolizja()), (obecnyDron->pobierz_dane_kolizja()))) obecnyDron->animuj_ruch_przod(api, -odleglosc, kat);
						return 1;
					}
				 }

			 }		
			obecnyDron->animuj_ruch_przod(api, odleglosc, kat);
		 }
	 }

	return 0;
}


//for (shared_ptr<Dron> latacz : listaDronow) latacz->rysuj(api);

  //listaDronow.push_back(obecnyDron);  
  //listaDronow.push_back(shared_ptr<Dron>(new Dron(wek2, 0.0, 3.0, 4.0, 1.0, 2, 0.5, 2)));
  //listaDronow.push_back(shared_ptr<Dron>(new Dron(wek3, 0.0, 3.0, 4.0, 1.0, 2, 0.5, 3)));
  
//  listaPrzeszkod.push_back(shared_ptr<Przeszkoda>(new Przeszkoda(wek4, mobrotu, 3, 4, 5, true)));
//  listaPrzeszkod.push_back(shared_ptr<Przeszkoda>(new Przeszkoda(wek5, mobrotu, 3, 4, 5, true)));
//  listaPrzeszkod.push_back(shared_ptr<Przeszkoda>(new Przeszkoda(wek6, mobrotu, 3, 4, 5, true)));
