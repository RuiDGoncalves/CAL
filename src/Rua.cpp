#include "Rua.h"

Rua::Rua(string nome, int comp, Coords coords, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	this->coords = coords;
}

Rua::Rua(string nome, int comp, float lat, float lon, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	Coords newCoords;
	newCoords.latitude = lat;
	newCoords.longitude = lon;
	this->coords = newCoords;
}

string Rua::getNome() const{
	return nome;
}

int Rua::getComprimento(){
	return comprimento;
}

void Rua::setNome(string n){
	this->nome = n;
}

void Rua::setComprimento(int comp){
	this->comprimento = comp;
}

bool Rua::operator==(const Rua& r1){
    if(r1.getNome() == nome)
    	return true;
    else return false;
 }


Coords Rua::getCoords(){
	return coords;
}
void Rua::setCoords(Coords coords){
	this->coords = coords;
}


void loadStreets(Graph<Rua> &graph, vector<Rua*> &ruas){
	ifstream streets;
	streets.open("Ruas.txt");
	string nome;
	int comp;
	while(!streets.eof()){
		getline(streets, nome);
		streets >> comp;
		streets.ignore();
		Coords coords;
		streets >> coords.latitude;
		streets >> coords.longitude;
		vector<string> ruasAdj;

		while(!streets.eof() || streets.peek() != '\n'){
			string ruaAdj;
			getline(streets,ruaAdj);
			ruasAdj.push_back(ruaAdj);
		}

		Rua * rua = new Rua(nome, comp, coords, ruasAdj);
		ruas.push_back(rua);
		graph.addVertex(*rua);

		while(!streets.eof() && streets.peek() == '\n')
			streets.ignore();


	}

	vector<Rua*>::iterator it = ruas.begin();
	for(;it != ruas.end(); it++){
		vector<string> connections = (*it)->connections;
		for(int i = 0; i < connections.size(); i++){
			vector<Rua*>::iterator adj = ruas.begin();
			for(;adj != ruas.end(); adj++)
				if( (*adj)->getNome() == connections[i])
					graph.addEdge(*(*it), *(*adj), ((float)(*it)->getComprimento()+(*adj)->getComprimento())/2 );
		}
	}
}
