/*
 * Custos.cpp
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#include "Custos.h"

namespace std {

Custos::Custos() {

}

//construct overload
Custos::Custos(int id, string n) {
	codigo = id;
	nome = n;
}

//Method encapsulate get and set id
void Custos::setCodigo(int id) {
	codigo = id;
}

int Custos::getCodigo() {
	return codigo;
}

//Method encapsulate get and set Name
void Custos::setNome(string n) {
	nome = n;
}

string Custos::getNome() {
	return nome;
}
Custos::~Custos() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
