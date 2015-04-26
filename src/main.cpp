#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Rua.h"
#include "POI.h"
#include "Path.h"
using namespace std;





int main() {
	Graph<Rua*> graph;
	list<Rua*> streets;
	list<POI*> POIs;

	loadStreets(graph, streets);
	/*//TESTE LOADSTREETS
	list<Rua*>::iterator it = streets.begin();
	for(; it != streets.end(); it++){
		cout << "Nome: " << (*it)->getNome() << endl;
		cout << "Comprimento: " << (*it)->getComprimento() << endl;
		cout << "Latitude: " << (*it)->getCoords().latitude << endl;
		cout << "Longitude: " << (*it)->getCoords().longitude << endl;
		for(int i = 0; i < (*it)->connections.size(); i++)
			cout << "Rua adj: " << (*it)->connections[i] << endl;
		cout << endl;
	}*/

	loadPOIs(POIs, streets);
	/*//TESTE LOADPOIS
	list<POI*>::iterator it2 = POIs.begin();
	for(; it2 != POIs.end(); it2++){
		cout << "Nome POI: " << (*it2)->getName() << endl;
		cout << (*it2)->getStreet()->getNome() << endl;
		cout << endl;
	}*/

	cout << POIs.size() << endl;
	list<pathList> organizedPOIs = organizePOI(graph, POIs);


	list<pathList>::iterator it = organizedPOIs.begin();
	for(; it != organizedPOIs.end(); it++){
		cout << "POI: " << it->poi->getName() << endl << endl;

		list<Path>::iterator it2 = it->paths.begin();
		for(; it2 != it->paths.end(); it2++){
			cout << "Destino: " << it2->dest->getName() << endl;
			cout << "Distancia: " << it2->dist << endl;
			list<Rua*>::iterator street = it2->streets.begin();
			for(; street != it2->streets.end(); street++)
				cout << (*street)->getNome() << endl;
			cout << endl;
		}
		cout << endl;
	}

	cout << "123\n";
	return 0;
}
