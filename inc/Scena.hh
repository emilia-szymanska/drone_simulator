#ifndef SCENA_HH
#define SCENA_HH

#include <list>
#include <memory>
#include "Dron.hh"
#include "Przeszkoda.hh"
#include "Obiekt_graficzny.hh"
#include "lacze_do_gnuplota.hh"
#include <cstddef>

using std::list;
using std::shared_ptr;

class Scena 
{
	list <shared_ptr<Obiekt_sceny>> listaSceny;
	list <shared_ptr<Obiekt_graficzny>> listaObiektow;
	list <shared_ptr<Dron>> listaDronow;
	shared_ptr<Dron> obecnyDron;
	
	public:
		Scena();
		void zmien_drona(int id);
		void wspolrzedne_dronow() const;
		shared_ptr<Dron> pobierz_obecnego_drona() const;
		void rysuj(API3D *api) const;
		int nr_id_obecnego() const;
		int animuj_scene (API3D *api, double kat, double odleglosc);
};

#endif
