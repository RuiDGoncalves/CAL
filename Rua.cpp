#include "Rua.h"


Rua::Rua(string n, int comp){
	this->nome = n;
	this->comprimento = comp;
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
bool Rua::operator==(const Rua& r1)
 {
    if(r1.getNome() == nome)
    	return true;
    else return false;
 }
