#include "menu.hh"

void komunikat_kolizja()
{
	cout<<endl;
	cout<<"Wykryta kolizja!!!"<<endl;
	cout<<"  Lot przerwany"<<endl;
	return;
}

void menu (/*Dron dronik,*/ Scena sceniszcze, API3D * api)
{
	int czykoniec=0;
	while(!czykoniec)
	{
		
		double dlugoscdrogi=0, kat_wznoszenia=0, katobrotu=0, jak_szybko=1, skalar, nr_id=1;
		char opcja;
		cout<<endl;
		Wektor3D::statystyka_wektorow();
		cout<<endl;
		Obiekt_sceny::statystyka_obiektow();
		cout<<endl;
		cout<<"Obecnie wybrany dron: ";
		cout<< sceniszcze.nr_id_obecnego()<<endl;
		cout<<"Wspolrzedne obecnie wybranego drona: "<<(sceniszcze.pobierz_obecnego_drona())->zwroc_srodek()<<endl;;
		cout<<endl;
		cout<<"Twoj wybor? (w - wyswietl menu) > ";
		cin>>opcja;
		switch(opcja)
		{
			case 'j': cout<< "Podaj dlugosc drogi przelotu i kat wznoszenia (+) / opadania (-)."<<endl;
				  cout<<"Dlugosc drogi: ";
				  cin>>dlugoscdrogi;
				  while(cin.fail())
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Dlugosc drogi: ";
					cin>>dlugoscdrogi;
				   }
				  cout<<"Kat wznoszenia (stopnie): ";
				  cin>>kat_wznoszenia;
				  while(cin.fail())
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Kat wznoszenia (stopnie): ";
					cin>>kat_wznoszenia;
				   }
				  if(sceniszcze.animuj_scene(api, kat_wznoszenia, dlugoscdrogi)==1) 
				   {
					komunikat_kolizja();
				  //	sceniszcze.animuj_scene(api, -kat_wznoszenia, dlugoscdrogi/100);
				   }
				  break;

			case 'o': cout<<"Podaj wartosc kata, o jaki ma sie obrocic dron"<<endl;
				  cout<<"Kat obrotu (stopnie): ";
				  cin>>katobrotu;
				  while(cin.fail())
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Kat obrotu (stopnie): ";
					cin>>katobrotu;
				   }
				  if(sceniszcze.animuj_scene(api, katobrotu, 0)==1) 
				   {
					komunikat_kolizja();
				//	sceniszcze.animuj_scene(api, (-katobrotu/100), 0);
				   }
				//(sceniszcze.pobierz_obecnego_drona())->animuj_obrot(api, katobrotu);
				  break;

			case 'v': cout<<"Podaj liczbe, ktora bedzie oznaczala wielokrotnosc zwiekszenia predkosci drona: ";
				  cin>>jak_szybko;
				  while(cin.fail())
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Wielokrotnosc zmiany predkosci drona: ";
					cin>>jak_szybko;
				   }
				  (sceniszcze.pobierz_obecnego_drona())->przypisz_predkosc(jak_szybko);
				  break;

			case 'r': cout<<"Wpisz skale zmiany rozmiaru drona: ";
				  cin>>skalar;
				  while(cin.fail())
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Skala zmiany rozmiaru drona: ";
					cin>>skalar;
				   }
				  (sceniszcze.pobierz_obecnego_drona())->zmien_rozmiar(skalar, api);
				  break;

			case 'z': sceniszcze.wspolrzedne_dronow(); 
				  cout<<"Podaj nr id drona, ktorym chcesz sterowac: ";
				  cin>>nr_id;
				  while(cin.fail() || nr_id>3)
				   {
					cout<<"Nieprawidlowa wartosc. Wpisz ponownie"<<endl;
					cin.clear();
					cin.ignore(1000000, '\n');
				  	cout<<"Nr id: ";
					cin>>nr_id;
				   }
				  sceniszcze.zmien_drona(nr_id);
				  break;

			case 'w': cout<<" o - obrot drona"<<endl;
				  cout<<" j - lot na wprost"<<endl;
				  cout<<" w - wyswietl ponownie menu"<<endl;
				  cout<<" k - koniec dzialania programu"<<endl;
				  cout<<" v - zmiana predkosci "<< endl;
				  cout<<" r - zmiana rozmiaru drona" <<endl;
				  cout<<" z - zmiana drona"<<endl;
				  break;

			case 'k': cout<<"Koniec dzialania programu"<<endl;
				  czykoniec=1;
				  system("rm ./figury/*.dat");
				  return;

			default: cout<<"Bledne polecenie. Wpisz ponownie"<<endl;
				 cin.clear();
				 cin.ignore(1000000, '\n');
				 break;
		}

	}
}
