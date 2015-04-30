/*
 * Path.cpp
 *
 *  Created on: 25/04/2015
 *      Author: duarte
 */

#include "Path.h"



list<pathList> organizePOI(Graph<Rua*> graph, list<POI*> POIs){
	list<pathList> organizedPOIs;

	list<POI*>::iterator it = POIs.begin();
	for(; it != POIs.end(); it++){
		POI* p = *it;
		graph.dijkstraShortestPath(p->getStreet());

		pathList plist;
		plist.poi = p;
		list<POI*>::iterator it2 = POIs.begin();
		for(; it2 != POIs.end(); it2++){
			if(*it == *it2)
				continue;
			POI* dest = *it2;
			Path path;
			path.origin = p;
			path.dest = dest;
			Vertex<Rua*> * v = graph.getVertex(dest->getStreet());
			path.dist = v->getDist();
			path.streets.push_front(v->getInfo());
			do{
				v = v->path;
				if(v == NULL)
					break;
				path.streets.push_front(v->getInfo());
			}while(v->getDist() != 0);
			plist.paths.push_front(path);
		}
		organizedPOIs.push_back(plist);
	}
	return organizedPOIs;
}



Graph<POI*> pathListToGraph(list<pathList> organizedPOIs){
	Graph<POI*> graph;
	list<pathList>::iterator it = organizedPOIs.begin();
	POI* poi = it->poi;
	graph.addVertex(poi);

	//ADD VERTEX AND EDGES FROM FIRST VERTEX TO THE OTHER VERTEX'S
	for(list<Path>::iterator path = it->paths.begin(); path != it->paths.end(); path++){
		POI* dest = path->dest;
		if (dest == poi)
			continue;
		graph.addVertex(dest);
		graph.addEdge(poi, dest, path->dist);
	}

	it++;	//Increment pointer

	//ADD EDGES FOR ALL THE OTHER VERTEXES
	for(; it != organizedPOIs.end(); it++){
		POI* poi = it->poi;

		if(graph.getVertex(poi) == NULL)
			graph.addVertex(poi);

		for(list<Path>::iterator path = it->paths.begin(); path != it->paths.end(); path++){
				POI* dest = path->dest;
				if (dest == poi)
					continue;
				graph.addEdge(poi, dest, path->dist);
		}
	}

	return graph;
}


Graph<Rua*> graphicalPath(list<pathList> organizedPOIs, list<POI*> orderedPOIs){
	list<Rua*> orderedCircuit;

	list<POI*>::iterator it = orderedPOIs.begin();


	POI* origin;
	POI* dest = *it;
	orderedCircuit.push_back(dest->getStreet());

	it++;
	for(; it != orderedPOIs.end(); it++){
		origin = dest;
		dest = *it;
		list<pathList>::iterator orgListIt = organizedPOIs.begin();

		for(; orgListIt != organizedPOIs.end(); orgListIt++){
			if(orgListIt->poi == origin){
				list<Path>::iterator pathListIt = orgListIt->paths.begin();
				for(; pathListIt != orgListIt->paths.end(); pathListIt++){
					if(pathListIt->dest != dest)
						continue;
					list<Rua*> path = pathListIt->streets;
					path.pop_front();
					orderedCircuit.insert(orderedCircuit.end(), path.begin(), path.end());
				}
				break;
			}
		}
	}

	Graph<Rua*>retGraph;
	list<Rua*>::iterator circuitIt = orderedCircuit.begin();
	Rua* previousStreet;
	Rua* currentStreet = *circuitIt;
	retGraph.addVertex(currentStreet);
	circuitIt++;
	for(; circuitIt != orderedCircuit.end(); circuitIt++){
		previousStreet = currentStreet;
		currentStreet = *circuitIt;
//		cout << "Previous street: " << previousStreet->getNome() << endl;
//		cout << "Current Street: " << currentStreet->getNome() << endl << endl;
		retGraph.addVertex(currentStreet);
		retGraph.addEdge(previousStreet, currentStreet, ((double) previousStreet->getComprimento() + currentStreet->getComprimento())/2 );
	}

	return retGraph;
}
