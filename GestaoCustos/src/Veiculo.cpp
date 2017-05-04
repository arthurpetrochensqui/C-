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
Veiculo::Veiculo(int i, string p){
	id=i;
	placa=p;
}

Veiculo::~Veiculo() {
	// TODO Auto-generated destructor stub
}

int Veiculo::getVeiculoId(){
	return id;
}
void Veiculo::setVeiculoId(int i){
	id =i;
}

//Implements Method Placa
string Veiculo::getPlaca(){
	return placa;
}

void Veiculo::setPlaca(string str){
	placa =str;
}
} /* namespace std */
