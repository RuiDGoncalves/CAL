/*
 * POI.h
 *
 *  Created on: 23/04/2015
 *      Author: duarte
 */

#ifndef POI_H_
#define POI_H_

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <cmath>

#include "Rua.h"


class POI{
private:
	string name;
	Rua * street;
public:
	POI(string name, Rua * rua);
	string getName() const;
	void setName(string name);
	Rua * getStreet() const;
	void setStreet(Rua* street);
	bool operator==(const POI &b);
};

void loadPOIs(string filename, list<POI*> &vecPOI, list<Rua*> &ruas);


#endif /* POI_H_ */
