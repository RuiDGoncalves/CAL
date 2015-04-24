#pragma once

#ifndef RUA_H_
#define RUA_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unistd.h>
#include <cmath>

#include "Graph.h"
#include "AuxiliarFunctions.h"
using namespace std;




class Rua{
	string nome;
	int comprimento;
	Coord coords;
public:
	vector<string> connections;

	Rua(string nome, int comp, Coord coords,vector<string> connections);
	Rua(string nome, int comp,float lat,float lon,vector<string> connections);
	string getNome() const;
	void setNome(string n);
	int getComprimento();
	void setComprimento(int comp);
	bool operator==(const Rua& r1);
	Coord getCoords();
	void setCoords(Coord coords);
};

void loadStreets(Graph<Rua> &graph, list<Rua*> &ruas);


#endif
