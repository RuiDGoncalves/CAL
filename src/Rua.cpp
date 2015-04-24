#include "Rua.h"

Rua::Rua(string nome, int comp, Coords coords, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	this->coords = coords;
}

Rua::Rua(string nome, int comp, float lat, float lon, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	Coords newCoords;
	newCoords.latitude = lat;
	newCoords.longitude = lon;
	this->coords = newCoords;
}

string Rua::getNome() const{
	return nome;
}

int Rua::getComprimento(){
	return comprimento;
}

void Rua::setNome(string n){
	this->nome = n;
}

void Rua::setComprimento(int comp){
	this->comprimento = comp;
}

bool Rua::operator==(const Rua& r1){
    if(r1.getNome() == nome)
    	return true;
    else return false;
 }


Coords Rua::getCoords(){
	return coords;
}
void Rua::setCoords(Coords coords){
	this->coords = coords;
}
