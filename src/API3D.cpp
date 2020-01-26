#include "API3D.hh"

/********************************************************
 * code given at programming course led by 
 * Ph.D. Bogdan Kreczmer and MSc Arkadiusz Mielczarek
 * at Wroclaw University of Science and Technology
 * MIT Licence
 ********************************************************/

APIGnuPlot3D::APIGnuPlot3D(double minX, double maxX, double minY, double maxY, double minZ, double maxZ) : l_stworzone_ob(0) {
  Inicjalizuj();
  ZmienTrybRys(PzG::TR_3D);
  UstawZakresY(minY,maxY);
  UstawZakresX(minX,maxX);
  UstawZakresZ(minZ,maxZ);
  PrzeslijDoGNUPlota("set view equal xyz\n");
  PrzeslijDoGNUPlota("set xyplane relative 0\n");
}

int APIGnuPlot3D::rysuj_linie(const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor, bool rysuj_od_razu) {
  l_stworzone_ob++;//nowe id
  if (kolor == APIrys::domyslny)
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,l_stworzone_ob));
  else
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,kolor));
  stringstream str;
  str << "figury/dane" << l_stworzone_ob << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,3,istniejace_obiekty[l_stworzone_ob]);
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pt1 << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pt2 << endl;//wypisanie danych do pliku
  if(rysuj_od_razu)
    Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  return l_stworzone_ob;
}

int APIGnuPlot3D::rysuj_prostopadloscian(const vector<Wektor3D> & pts, APIrys::Kolor kolor, bool rysuj_od_razu) {
  l_stworzone_ob++;//nowe id
  if (kolor == APIrys::domyslny)
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,l_stworzone_ob));
  else
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,kolor));
  stringstream str;
  str << "figury/dane" << l_stworzone_ob << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,3,istniejace_obiekty[l_stworzone_ob]);
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  if (pts.size() < 8) {
    cerr << endl
         << "Blad: Za mało punktów by określić prostopadłościan"
         << endl;
  }
  //wypisanie danych do pliku
  for(uint i=0;i<pts.size();++i) {
    strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
    if(i%2)
      strm << endl;
  }
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[0] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[1] << endl;

  if(rysuj_od_razu)
    Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  return l_stworzone_ob;
}


int APIGnuPlot3D::rysuj_graniastoslup6(const vector<Wektor3D> & pts, APIrys::Kolor kolor, bool rysuj_od_razu) {
  l_stworzone_ob++;//nowe id
  if (kolor == APIrys::domyslny)
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,l_stworzone_ob));
  else
    istniejace_obiekty.insert(make_pair(l_stworzone_ob,kolor));
  stringstream str;
  str << "figury/dane" << l_stworzone_ob << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,3,istniejace_obiekty[l_stworzone_ob]);
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  if (pts.size() < 12) {
    cerr << endl
         << "Blad: Za mało punktów by określić prostopadłościan"
         << endl;
  }
  //wypisanie danych do pliku
  for (int i=6; i<12; i++) strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[6] << endl;
  
  strm << endl;

  for (int i=0; i<6; i++) strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[0] << endl;
  
  strm << endl;

  for (int i=0; i<6; i++)
  {
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i+6] << endl;
  strm << endl;
  }

  for (int i=6; i<9; i++)
  {
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i+3] << endl;
  strm << endl;
  }

  if(rysuj_od_razu)
    Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  return l_stworzone_ob;
}
//
//
//

void APIGnuPlot3D::wymaz_ksztalt(int indeks, bool rysuj_od_razu) {
  istniejace_obiekty.erase(indeks);
  UsunWszystkieNazwyPlikow();
  stringstream str;
  for (auto ind : istniejace_obiekty) {
    str.str("");
    str << "figury/dane" << ind.first << ".dat";
    DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,3);
  }
  if (istniejace_obiekty.size() > 0)
    if(rysuj_od_razu)
      Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  //usuwanie wyszstkich plikow z pamieci lacza a potem dodawanie tych co mialy tam
  //pozostac jest nieoptymalne, jednak klasa dra Kreczmara udostepnia tylko takie metody
}

void APIGnuPlot3D::aktualizuj_linie(int indeks, const Wektor3D & pt1, const Wektor3D & pt2, APIrys::Kolor kolor, bool rysuj_od_razu) {
  if (istniejace_obiekty.count(indeks) == 0)
    std::cerr << "brak ksztaltu!";
  if (kolor != APIrys::domyslny) {
    istniejace_obiekty[indeks] = kolor;
  }
  stringstream str;
  str << "figury/dane" << indeks << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pt1 << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pt2 << endl;//wypisanie danych do pliku
  if(rysuj_od_razu)
    Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
}

void APIGnuPlot3D::aktualizuj_prostopadloscian(int indeks, const vector<Wektor3D> & pts, APIrys::Kolor kolor, bool rysuj_od_razu) {
  if (istniejace_obiekty.count(indeks) == 0)
    std::cerr << "brak ksztaltu!";
  if (kolor != APIrys::domyslny) {
    istniejace_obiekty[indeks] = kolor;
  }
  stringstream str;
  str << "figury/dane" << indeks << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  if (pts.size() < 8) {
    cerr << endl
         << "Blad: Za mało punktów by określić prostopadłościan"
         << endl;
  }
  //wypisanie danych do pliku
  for(uint i=0;i<pts.size();++i) {
    strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[i] << endl;
    if(i%2)
      strm << endl;
  }
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[0] << endl;
  strm << std::setw(16) << std::fixed << std::setprecision(10) << pts[1] << endl;

  if(rysuj_od_razu)
    Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
}

void APIGnuPlot3D::rysuj() {
  Rysuj();
}
