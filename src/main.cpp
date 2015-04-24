#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Rua.h"
#include "POI.h"
using namespace std;





int main() {
	Graph<Rua> graph;
	list<Rua*> streets;
	list<POI*> POIs;


	loadStreets(graph, streets);
	/*TESTE LOADSTREETS
	list<Rua*>::iterator it = rua.begin();
	for(; it != rua.end(); it++){
		cout << "Nome: " << (*it)->getNome() << endl;
		cout << "Comprimento: " << (*it)->getComprimento() << endl;
		cout << "Latitude: " << (*it)->getCoords().latitude << endl;
		cout << "Longitude: " << (*it)->getCoords().longitude << endl;
		for(int i = 0; i < (*it)->connections.size(); i++)
			cout << "Rua adj: " << (*it)->connections[i] << endl;
		cout << endl;
	}*/

	loadPOIs(POIs, streets);
	/*TESTE LOADPOIS
	list<POI*>::iterator it = POIs.begin();
	for(; it != POIs.end(); it++){
		cout << "Nome POI: " << (*it)->getName() << endl;
		cout << (*it)->getStreet()->getNome() << endl;
		cout << endl;
	}*/


	return 0;
}
