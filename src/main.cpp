#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

bool loadStreets(Graph<Rua*> &graph){

	ifstream streets;
	streets.open("Ruas.txt");
	string nome;
	int comp;
	while(!streets.eof()){
		getline(streets, nome);
		streets >> comp;
		streets.ignore();
		Coords coords;
		streets >> coords.latitude;
		streets >> coords.longitude;

		while(!streets.eof() || streets.peek() == "\n"){
			string ruaAdj;

		}

	}

	return true;
}



int main() {
	Graph<Rua*> graph;


	system("PAUSE");
	return 0;
}
