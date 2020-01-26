#include "Obiekt_sceny.hh"

//inicjalizacja zmiennej statycznej
int Obiekt_sceny::ile_bylo_obiektow=0;

//inicjalizacja zmiennej statycznej
int Obiekt_sceny::ile_jest_obiektow=0;

void Obiekt_sceny::statystyka_obiektow()
{
	cout<<"Laczna ilosc stworzonych obiektow klasy Obiekt_sceny: "<< ile_bylo_obiektow << endl;
	cout<<"Ilosc istniejacych obiektow klasy Obiekt_sceny:       "<< ile_jest_obiektow << endl;
}

