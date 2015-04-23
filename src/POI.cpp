/*
 * POI.cpp
 *
 *  Created on: 23/04/2015
 *      Author: duarte
 */

#include <string>
#include <vector>

#include "POI.h"




POI::POI(string name, Rua* rua){
	this->name = name;
	this->rua = rua;
}


string POI::getName() const{
	return this->name;
}

void POI::setName(string name){
	this->name = name;
}

Rua * POI::getRua() const{
	return this->rua;
}

void POI::setRua(Rua * rua){
	this->rua = rua;
}

bool POI::operator==(const POI &b){
	if(b.getName() == name)
		return true;
	return false;
}



