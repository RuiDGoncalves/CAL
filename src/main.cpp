#include <iostream>
#include <fstream>
#include "AuxiliarFunctions.h"
#include "Graph.h"
#include "Rua.h"
#include "POI.h"
using namespace std;





int main() {
	Graph<Rua> graph;
	list<Rua*> streets;
	list<POI*> POIs;


	loadStreets(graph, streets);
	//TESTE LOADSTREETS
	list<Rua*>::iterator it = streets.begin();
	for(; it != streets.end(); it++){
		cout << "Nome: " << (*it)->getNome() << endl;
		cout << "Comprimento: " << (*it)->getComprimento() << endl;
		cout << "Latitude: " << (*it)->getCoords().latitude << endl;
		cout << "Longitude: " << (*it)->getCoords().longitude << endl;
		for(int i = 0; i < (*it)->connections.size(); i++)
			cout << "Rua adj: " << (*it)->connections[i] << endl;
		cout << endl;
	}

	loadPOIs(POIs, streets);
	//TESTE LOADPOIS
	list<POI*>::iterator it2 = POIs.begin();
	for(; it2 != POIs.end(); it++){
		cout << "Nome POI: " << (*it2)->getName() << endl;
		cout << (*it2)->getStreet()->getNome() << endl;
		cout << endl;
	}

	view_Graph(graph);

	return 0;
}
