#pragma once

#include <string>
#include <vector>

using namespace std;

class Rua{
	string nome;
	int comprimento;
public:
	Rua();
	Rua(string n, int com);
	string getNome() const;
	void setNome(string n);
	int getComprimento();
	void setComprimento(int comp);
	bool operator==(const Rua& r1);

};
