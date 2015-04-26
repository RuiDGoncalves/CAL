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
		cout << "it: " << p->getName() << endl;
		list<POI*>::iterator it2 = POIs.begin();
		for(; it2 != POIs.end(); it2++){
			if(it == it2)
				continue;
			cout << "it2: " << (*it2)->getName() << endl;
			POI* dest = *it2;
			Path path;
			path.origin = p;
			path.dest = dest;
			Vertex<Rua*> * v = graph.getVertex(dest->getStreet());

			path.dist = v->getDist();
			path.streets.push_front(v->getInfo());

			while(v->getDist() != 0){
				v = v->path;
				path.streets.push_front(v->getInfo());
			}
			plist.paths.push_front(path);
		}
		cout << "it: " << (*it)->getName() << endl;
		organizedPOIs.push_back(plist);
	}
	return organizedPOIs;
}
