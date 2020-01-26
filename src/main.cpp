#include <iostream>
#include <iomanip>
#include <fstream>
#include "menu.hh"
#include "lacze_do_gnuplota.hh"
#include "Scena.hh"

int main()
{
  API3D * api = new APIGnuPlot3D(-30,30,-30,30,-30,30);
  Scena sceniszcze = Scena();
  
  sceniszcze.rysuj(api);

  menu ( sceniszcze, api);
  return 0;
}
