#include <iostream>
#include <fstream>
#include <ctime>


#include "graphviewer.h"
#include "Graph.h"
#include "Rua.h"
#include "POI.h"
#include "Path.h"
using namespace std;

float convert_coordinates_y(float coordinate)
{
	float y_limit = 41.140;
	cout << "Returning y " << (y_limit - coordinate) * 100000 << endl;
	return 600 - (coordinate - y_limit) * 100000;
}

float convert_coordinates_x(float coordinate)
{
	float x_limit = -8.61124;
	cout << "Returning x " << (x_limit - coordinate) * 100000 << endl;
	return 600 - (x_limit - coordinate) * 100000;
}

void view_Graph(Graph<Rua*> graph) {
	unsigned idE = 0;
	unsigned idV = 0;
	float window_size = 3000;
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");



	//add vertexes
	vector<Vertex<Rua*> *> vertexes = graph.getVertexSet();

	for (unsigned int i = 0; i < vertexes.size(); i++){
		gv->addNode(i, convert_coordinates_x(vertexes[i]->getInfo()->getCoords().longitude), convert_coordinates_y(vertexes[i]->getInfo()->getCoords().latitude));
		gv->setVertexLabel(i,vertexes[i]->getInfo()->getNome());
	}

	gv->rearrange();

	//add edges
	vector<Edge<Rua*> > edges;

	for (unsigned int j = 0; j < vertexes.size(); j++) {
		edges = vertexes[j]->getAdj();
		for (unsigned int k = 0; k < edges.size(); k++) {
			gv->addEdge(idE++, vertexes[j]->getInfo()->getId(), edges[k].getDest()->getInfo()->getId(), EdgeType::DIRECTED);
		}
	}
	gv->rearrange();

}

bool paint_edge(list<pathList> organised_POIs, Rua* rua){
	list<pathList>::iterator prim_it =organised_POIs.begin();
	list<Path>::iterator it;
	list<Rua *>::iterator iterB;
	list<Rua *>::iterator iterE;
	list<Rua *>::iterator check;

	for(prim_it; prim_it != organised_POIs.end();prim_it++){
		it = prim_it->paths.begin();
		for(it; it!= prim_it->paths.end(); it++){
			iterB = it->streets.begin();
			iterE = it->streets.end();
			for(;iterB!=iterE;iterB++)
				check = find(iterB,iterE, rua);
			if(check!=iterE)
				return true;
		}
	}
	return false;
}

void view_circuit(Graph<Rua*> graph, list<pathList> organizedPOIs)
{
	unsigned idE = 0;
	unsigned idV = 0;
	float window_size = 3000;

	vector<string> POIs_name;
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");



	//add vertexes
	vector<Vertex<Rua*> *> vertexes = graph.getVertexSet();

	for (unsigned int i = 0; i < vertexes.size(); i++){
		gv->addNode(i, convert_coordinates_x(vertexes[i]->getInfo()->getCoords().longitude), convert_coordinates_y(vertexes[i]->getInfo()->getCoords().latitude));
		gv->setVertexLabel(i,vertexes[i]->getInfo()->getNome());
	}

	for (unsigned int i = 0; i < vertexes.size(); i++){
		for(list<pathList>::iterator it = organizedPOIs.begin(); it!= organizedPOIs.end();it++){
			if(it->poi->getStreet()->getNome() == vertexes[i]->getInfo()->getNome()){
				gv->setVertexColor(vertexes[i]->getInfo()->getId(), "green");
			}
		}
	}
	gv->rearrange();
	//add edges
	vector<Edge<Rua*> > edges;
	vector<Rua *> temp;

	for (unsigned int j = 0; j < vertexes.size(); j++) {
		edges = vertexes[j]->getAdj();
		for (unsigned int k = 0; k < edges.size(); k++) {

				if(paint_edge(organizedPOIs, edges[k].getDest()->getInfo())){
					gv->addEdge(idE, vertexes[j]->getInfo()->getId(), edges[k].getDest()->getInfo()->getId(), EdgeType::DIRECTED);
					gv->setEdgeColor(idE++,"green");
					temp.push_back(edges[k].getDest()->getInfo());
					//idE++;
				}

			else
				gv->addEdge(idE++, vertexes[j]->getInfo()->getId(), edges[k].getDest()->getInfo()->getId(), EdgeType::DIRECTED);
		}
	}

	gv->rearrange();



}

void savePath(string filename, list<Rua*> streetPath){
	ofstream file;
	file.open(filename.c_str());

	list<Rua*>::iterator it = streetPath.begin();

	file << (*it)->getNome();
	it++;

	for(; it != streetPath.end(); it++)
		file << endl << (*it)->getNome();
}

int main() {
	time_t initTime;
	time(&initTime);
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
/*	//TESTE ORGANIZEDPOIS
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
	}*/

	Graph<POI*> poiGraph = pathListToGraph(organizedPOIs);
	list<POI*> orderedPOIs = poiGraph.branchAndBoundSmallestCircuit();
/*	//TESTE BRANCHANDBOUND
	list<POI*>::iterator it = orderedPOIs.begin();
	for(;it != orderedPOIs.end(); it++){
		cout << "POI: " << (*it)->getName() << endl;
	}
	cout << endl;*/

	list<Rua*> path = streetPath(organizedPOIs,orderedPOIs);

	savePath("path.txt",path);

	Graph<Rua*> orderedCircuit = graphicalPath(path);

	time_t endTime;
	time(&endTime);
	double duration = difftime(endTime, initTime);
	cout << duration << endl;
	//view_Graph(graph);

	view_circuit(graph, organizedPOIs);
	while(true){}
	return 0;
}
