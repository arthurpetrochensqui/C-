/*
 * Veiculo.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: arthur
 */

#include "Veiculo.h"

namespace std {

Veiculo::Veiculo() {
	// TODO Auto-generated constructor stub

}

//Implement Construct that receive the value
Veiculo::Veiculo(int i, string p, string r, int km) {

	setVeiculoId(i);
	setPlaca(p);
	setRenavam(r);
	setQuilmetragem(km);

}

Veiculo::~Veiculo() {
	// TODO Auto-generated destructor stub
}

int Veiculo::getVeiculoId() {
	return id;
}
void Veiculo::setVeiculoId(int i) {
	id = i;
}

//Implements Method Placa
string Veiculo::getPlaca() {
	return placa;
}

void Veiculo::setPlaca(string str) {

	int length = str.length();
	//cout<<"tamanho placa veiculo:" <<length<<endl;
	//length = (length < 10 ? length : 4);
	str.copy(placa, length);

	placa[length] = '\0';
	//cout<<"Placa"<<placa<<endl;
}

int Veiculo::getQuilometragem() {
	return quilometragem;
}

void Veiculo::setQuilmetragem(int km) {
	quilometragem = km;
}

string Veiculo::getRenavam() {
	return renavam;
}

void Veiculo::setRenavam(string ren) {
	int length = ren.length();

	//cout<<"tamano quilometragem"<<length;
	//length = (length < 10 ? length : 4);
	ren.copy(renavam, length);

	renavam[length] = '\0';
	//cout<<"renavam"<<renavam;

}

} /* namespace std */
