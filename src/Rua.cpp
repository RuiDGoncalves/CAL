#include "Rua.h"

Rua::Rua(string nome, int comp, Coord coords, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	this->coords = coords;
	this->connections = connections;
}

Rua::Rua(string nome, int comp, float lat, float lon, vector<string> connections){
	this->nome = nome;
	this->comprimento = comp;
	Coord newCoords;
	newCoords.latitude = lat;
	newCoords.longitude = lon;
	this->coords = newCoords;
	this->connections = connections;
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


Coord Rua::getCoords(){
	return coords;
}
void Rua::setCoords(Coord coords){
	this->coords = coords;
}


void loadStreets(string filename,Graph<Rua*> &graph, list<Rua*> &ruas){
	ifstream file;
	file.open(filename.c_str());
	string nome;
	int comp;
	while(!file.eof()){
		getline(file, nome);
//		cout << "Vai buscar a rua: " << nome << endl;
		file >> comp;
		file.ignore();
		Coord coords;
		file >> coords.latitude;
		file >> coords.longitude;
		file.ignore();
		vector<string> ruasAdj;

		while(!file.eof() && (char) file.peek() != '\n'){
			string adjacentStreet;
			getline(file,adjacentStreet);
			ruasAdj.push_back(adjacentStreet);
		}

		Rua * rua = new Rua(nome, comp, coords, ruasAdj);
		ruas.push_back(rua);
		graph.addVertex(rua);

		while(!file.eof() && file.peek() == '\n')
			file.ignore();


	}

	file.close();

	list<Rua*>::iterator it = ruas.begin();
	for(;it != ruas.end(); it++){
		vector<string> connections = (*it)->connections;
		for(unsigned int i = 0; i < connections.size(); i++){
			list<Rua*>::iterator adj = ruas.begin();
			bool success = false;
			for(;adj != ruas.end(); adj++){
				if( (*adj)->getNome() == connections[i]){
					success = true;
					graph.addEdge(*it, *adj, ((float)(*it)->getComprimento()+(*adj)->getComprimento())/2 );
					break;
				}
			}
			if ( ! success){
				cout << (*it)->getNome() << endl;
				cout << connections[i] << endl;
				//usleep(pow(2,6));
				throw ExceptionStreetNotFound();
			}
		}
	}
}


