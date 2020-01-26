#include "Przeszkoda.hh"		

//wektor_odleglosci to wektor miedzy srodkiem przeszkody prostopadlosciennej a srodkiem  walca

bool Przeszkoda::sprawdz_czy_kolizja (Wektor3D wektor_srodka_walca, std::vector<double> dane2) const
{
	Wektor3D wektor_odleglosci=((this->zwroc_srodek())-wektor_srodka_walca);
	std::vector<double> dane1=this->zwroc_wymiary();
	dane1[0]=dane1[0]+dane2[1]; //a powiekszamy o R
	dane1[1]=dane1[1]+dane2[1]; //b powiekszamy o R
	dane1[2]=dane1[2]+dane2[0]; //c powiekszamy o h

	if(std::fabs(wektor_odleglosci[0])<=dane1[0] && std::fabs(wektor_odleglosci[1])<=dane1[1] && std::fabs(wektor_odleglosci[2])<=dane1[2]) return true;
	return false;
	
}


/*
Wektor3D Przeszkoda::odleglosc_przeszkoda_dron (Dron dron) const
{
	return dron.zwroc_srodek_kolizja()-this->zwroc_srodek();
}
//	cout<<wektor_odleglosci<<endl;
//	cout<<"Wektor srodka walca: "<<wektor_srodka_walca<<endl;
	cout<<"Poczatkowe dane1:"<<endl;
	cout<<dane1[0]<<endl;
	cout<<dane1[1]<<endl;
	cout<<dane1[2]<<endl;
	cout<<"Koncowe dane1"<<endl;
	cout<<dane1[0]<<endl;
	cout<<dane1[1]<<endl;
	cout<<dane1[2]<<endl;
	
	cout<<endl;
	cout<<dane2[0]<<endl;//h
	cout<<dane2[1]<<endl;//R
	cout<<endl;
	cout<<std::fabs(wektor_odleglosci[0])<<endl;
	cout<<dane1[0]<<endl;
	
	cout<<std::fabs(wektor_odleglosci[1])<<endl;
	cout<<dane1[1]<<endl;
	
	cout<<std::fabs(wektor_odleglosci[2])<<endl;
	cout<<dane1[2]<<endl;
	cout<<endl;
	cout<<"Srodek przeszkody: "<<this->zwroc_srodek()<<endl;
*/
