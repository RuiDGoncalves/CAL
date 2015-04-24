#pragma once

#ifndef RUA_H_
#define RUA_H_

#include <string>
#include <vector>
#include "Graph.h"

using namespace std;


struct Coords{
	float longitude;
	float latitude;
};

class Rua{
	string nome;
	int comprimento;
	Coords coords;
public:
	vector<string> connections;

	Rua(string nome, int comp, Coords coords,vector<string> connections);
	Rua(string nome, int comp,float lat,float lon,vector<string> connections);
	string getNome() const;
	void setNome(string n);
	int getComprimento();
	void setComprimento(int comp);
	bool operator==(const Rua& r1);
	Coords getCoords();
	void setCoords(Coords coords);
};

void loadStreets(Graph<Rua> &graph, vector<Rua*> &ruas);


#endif
