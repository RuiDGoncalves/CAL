#pragma once

#ifndef RUA_H_
#define RUA_H_

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

class PoI{
	string nome;
	Rua *rua;
public:
	PoI();
	PoI(string nome, Rua* rua);
	string getNome() const;
	void setNome(string nome);
	Rua* getRua();
	void setRua(Rua* rua);
};

#endif
