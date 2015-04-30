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
 * Creates a ordered list with the circuit that the bus is supposed to travel;
 *
 */
list<Rua*> streetPath(list<pathList> organizedPOIs, list<POI*> orderedPOIs);


/*
 * Receives a list of pointers to Rua and places them in a graph with the same order
 *
 */
Graph<Rua*> graphicalPath(list<Rua*> streetPath);

#endif /* PATH_H_ */
