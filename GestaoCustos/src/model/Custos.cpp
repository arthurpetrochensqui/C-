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
Custos::Custos(int id, string n, int cc) {

	setCodigo(id);
	setNome(n);
	setCodigoContabil(cc);
}

//Method encapsulate get and set id
void Custos::setCodigo(int id) {
	codigo = id;
}

int Custos::getCodigo() const{
	return codigo;
}

//Method encapsulate get and set Name
void Custos::setNome(string n) {
	//Field cannot be greather then 50
	int length = n.size();
	length =(length < 50 ? length:49);
	n.copy(nome,length);
	nome[length] ='\0';
}

string Custos::getNome() const{
	return nome;
}

void Custos::setCodigoContabil(int cc){
	codigoContabil=cc;
}

int Custos::getCodigoContabil()const{
	return codigoContabil;
}
Custos::~Custos() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
