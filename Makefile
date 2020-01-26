#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x


dron: obj obj/main.o obj/Prostopadloscian.o obj/Macierz.o obj/Wektor.o\
           obj/lacze_do_gnuplota.o obj/API3D.o obj/menu.o obj/Graniastoslup6.o\
	   obj/Dron.o obj/Scena.o obj/Obiekt_sceny.o obj/Przeszkoda.o
	g++ -Wall -pedantic -std=c++0x -o dron obj/main.o obj/Wektor.o obj/Macierz.o\
                        obj/Prostopadloscian.o obj/lacze_do_gnuplota.o obj/API3D.o\
                        obj/menu.o obj/Graniastoslup6.o obj/Dron.o obj/Scena.o obj/Obiekt_sceny.o\
			obj/Przeszkoda.o

obj:
	mkdir obj

obj/API3D.o: inc/API3D.hh inc/lacze_do_gnuplota.hh src/API3D.cpp
	g++ -c ${CXXFLAGS} -o obj/API3D.o src/API3D.cpp

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/menu.o: src/menu.cpp inc/menu.hh inc/Scena.hh\
         inc/Wektor.hh inc/Macierz.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/menu.o src/menu.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz.hh\
           inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor.hh inc/Macierz.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh\
         inc/Wektor.hh inc/Macierz.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Obiekt_graficzny.o: src/Obiekt_graficzny.cpp inc/Obiekt_graficzny.hh\
         inc/API3D.hh
	g++ -c ${CXXFLAGS} -o obj/Obiekt_graficzny.o src/Obiekt_graficzny.cpp

obj/Obiekt_sceny.o: src/Obiekt_sceny.cpp inc/Obiekt_sceny.hh inc/Wektor.hh\
	 inc/API3D.hh
	g++ -c ${CXXFLAGS} -o obj/Obiekt_sceny.o src/Obiekt_sceny.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/Obiekt_sceny.hh inc/Obiekt_graficzny.hh\
         inc/Wektor.hh inc/Macierz.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Dron.hh inc/Przeszkoda.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh inc/Obiekt_sceny.hh\
       	  inc/Prostopadloscian.hh inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

clean:
	rm -f obj/*.o dron
