/*
 * Path.h
 *
 *  Created on: 25/04/2015
 *      Author: duarte
 */

#ifndef PATH_H_
#define PATH_H_

#include <list>
#include <string>
#include "POI.h"
#include "Rua.h"
#include "Graph.h"

struct Path{
	POI * origin;
	POI * dest;
	int dist;
	list<Rua*> streets;
};

struct pathList{
	POI * poi;
	list<Path> paths;
};


/*
 * Creates the path between all of the given POIs
 *
 */
list<pathList> organizePOI(Graph<Rua*> graph, list<POI*> POIs);



/*
 * Creates a graph with the POI's, where all the POIs are connected to eachother and the weight
 * of the edges is the real distance between one POI to the other
 *
 *
 */
Graph<POI*> pathListToGraph(list<pathList> organizedPOIs);


/*
 * Creates a graph with the circuit that the bus is supposed to travel;
 *
 */
Graph<Rua*> graphicalPath(list<pathList> organizedPOIs, list<POI*> orderedPOIs);

#endif /* PATH_H_ */
