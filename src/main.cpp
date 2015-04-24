#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

void loadStreets(Graph<Rua> &graph){
	vector<Rua*> ruas;
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
		vector<string> ruasAdj;

		while(!streets.eof() || streets.peek() != "\n"){
			string ruaAdj;
			getline(streets,ruaAdj);
			ruasAdj.push_back(ruaAdj);
		}

		Rua * rua = new Rua(nome, comp, coords, ruasAdj);

		while(!streets.eof() && streets.peek() == "\n")
			streets.ignore();
	}

	graph.

}


void loadPOIs(vector<POI*>){

}



int main() {
	Graph<Rua> graph;


	system("PAUSE");
	return 0;
}
