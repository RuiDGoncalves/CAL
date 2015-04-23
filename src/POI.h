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
#include "Rua.h"
class POI{
private:
	string name;
	Rua * rua;
public:
	POI(string name, Rua * rua);
	string getName() const;
	void setName(string name);
	Rua * getRua() const;
	void setRua(Rua* rua);
	bool operator==(const POI &b);
};



#endif /* POI_H_ */
