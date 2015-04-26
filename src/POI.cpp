/*
 * POI.cpp
 *
 *  Created on: 23/04/2015
 *      Author: duarte
 */



#include "POI.h"




POI::POI(string name, Rua* street){
	this->name = name;
	this->street = street;
}


string POI::getName() const{
	return this->name;
}

void POI::setName(string name){
	this->name = name;
}

Rua * POI::getStreet() const{
	return this->street;
}

void POI::setStreet(Rua * rua){
	this->street = rua;
}

bool POI::operator==(const POI &b){
	if(b.getName() == name)
		return true;
	return false;
}

void loadPOIs(string filename,list<POI*> &vecPOI, list<Rua*> &ruas){
	ifstream file;
	file.open(filename.c_str());
	string nome,nomeRua;
	while(!file.eof()){
		getline(file, nome);
		getline(file, nomeRua);
		file.ignore();
		list<Rua*>::iterator it = ruas.begin();
		Rua* rua;
		for(;it != ruas.end(); it++)
			if((*it)->getNome() == nomeRua)
				rua = *it;
		if(rua == NULL)
			throw ExceptionStreetNotFound();

		POI * poi = new POI(nome, rua);
		vecPOI.push_back(poi);
	}

	file.close();

}




