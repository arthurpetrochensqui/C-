/*
 * Combustivel.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "Combustivel.h"

namespace std {

Combustivel::Combustivel() {
	// TODO Auto-generated constructor stub

}

Combustivel::Combustivel(int id,long dt,int qtd,double val,int ccv){
	codigo=id;
	data=dt;
	quantidade=qtd;
	valor =val;
	centroCusto=ccv;
}

Combustivel::~Combustivel() {
	// TODO Auto-generated destructor stub
}

int Combustivel::getCodigo(){
	return codigo;
}
void Combustivel::setCodigo(int id){
	codigo=id;
}
long Combustivel::getData(){
	return data;
}
void Combustivel::setData(long dt){
	data=dt;
}
int Combustivel::getQuantidade(){
	return quantidade;
}
void Combustivel::setQuantidade(int qtd){
	quantidade=qtd;
}
double Combustivel::getValor(){
	return valor;
}
void Combustivel::setValor(double val){
	valor=val;
}
CustosVariaveis Combustivel::getCustosVariaveis(){
	cv;
}
void Combustivel::setCustosVariaveis(CustosVariaveis _cv){
	cv=_cv;
}

int Combustivel::getCentroCusto(){
	return centroCusto;
}
void Combustivel::setCentroCusto(int cc){
	centroCusto=cc;
}

} /* namespace std */
