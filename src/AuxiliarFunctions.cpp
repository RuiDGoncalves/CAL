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
