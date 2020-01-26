#ifndef OBIEKT_GRAFICZNY_HH
#define OBIEKT_GRAFICZNY_HH

#include "API3D.hh"

/* 
 * \section intro_sec Opis 
 * Kod odwzorowuje pusta klase obiektu graficznego, po ktorym dziedziczy dron
 */

class Obiekt_graficzny
{		
	public:
		virtual int rysuj(API3D *api) = 0;

};

#endif
