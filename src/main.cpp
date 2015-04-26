#include <iostream>
#include <fstream>
#include "graphviewer.h"
#include "Graph.h"
#include "Rua.h"
#include "POI.h"
#include "Path.h"
using namespace std;



void view_Graph(Graph<Rua*> graph) {

	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	//add vertexes
	vector<Vertex<Rua*> *> vertexes = graph.getVertexSet();

	for (unsigned int i = 0; i < vertexes.size(); i++)
		gv->addNode(i);

	gv->rearrange();

	//add edges
	vector<Edge<Rua*> > edges;

	for (unsigned int j = 0; j < vertexes.size(); j++) {
		edges = vertexes[j]->getAdj();
		for (unsigned int k = 0; k < edges.size(); k++) {
			gv->addEdge(edges[k].getWeight(), vertexes[j]->getInfo()->getComprimento(), edges[k].getDest()->getInfo()->getComprimento(), EdgeType::UNDIRECTED);
		}
	}

	gv->rearrange();

}

int main() {
	Graph<Rua*> graph;
	list<Rua*> streets;
	list<POI*> POIs;

	string streetFilename = "ruas.txt";
	loadStreets(streetFilename, graph, streets);
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

	string poiFilename = "pois.txt";
	loadPOIs(poiFilename, POIs, streets);
	/*//TESTE LOADPOIS
	list<POI*>::iterator it2 = POIs.begin();
	for(; it2 != POIs.end(); it2++){
		cout << "Nome POI: " << (*it2)->getName() << endl;
		cout << (*it2)->getStreet()->getNome() << endl;
		cout << endl;
	}*/

	list<pathList> organizedPOIs = organizePOI(graph, POIs);

	//TESTE ORGANIZEDPOIS
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

	Graph<POI*> poiGraph = pathListToGraph(organizedPOIs);

	//view_Graph(graph);
	return 0;
}
