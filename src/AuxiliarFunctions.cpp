/*
 * AuxiliarFunctions.cpp
 *
 *  Created on: 24/04/2015
 *      Author: duarte
 */

#include "AuxiliarFunctions.h"


bool sortPOI(Coord c1, Coord c2){
	if(c1.latitude == c2.latitude)
		return c1.longitude < c2.longitude;
	return c1.longitude < c2.longitude;
}

void view_Graph(Graph<Rua> graph) {

	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	//add vertexes
	vector<Vertex<POI*> *> pois = graph.getVertexSet();

	for (int i = 0; i < pois.size(); i++)
		gv->addNode(i);

	gv->rearrange();

}
