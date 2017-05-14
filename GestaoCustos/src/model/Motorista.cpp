/*
 * Motorista.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "Motorista.h"

namespace std {

Motorista::Motorista() {
	// TODO Auto-generated constructor stub

}
Motorista::Motorista(int i,string n,double s){
	setId(i);
	setNome(n);
	setSalario(s);
}
Motorista::~Motorista() {
	// TODO Auto-generated destructor stub
}

int Motorista::getId(){
	return id;
}
void Motorista::setId(int i){
	id=i;
}

string Motorista::getNome(){
	return nome;
}
void Motorista::setNome(string n){
	int length = n.length();
	n.copy(nome,length);
	nome[length]='\0';

}

double Motorista::getSalario(){
	return salario;
}
void Motorista::setSalario(double sal){
	salario=sal;
}
} /* namespace std */
