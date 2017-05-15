/*
 * Multas.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "Multas.h"

namespace std {

Multas::Multas() {
	// TODO Auto-generated constructor stub

}

Multas::Multas(int id,long dt, long ven,double val,int cv){
	codigo=id;
	data=dt;
	vencimento=ven;
	valor=val;
	idCentroCusto=cv;
}

int Multas::getCodigo(){
	return codigo;
}
void Multas::setCodigo(int cod){
	codigo = cod;
}

long Multas::getData(){
	return data;
}
void Multas::setData(long dt){
	data=dt;
}
long Multas::getVencimento(){
	return vencimento;
}
void Multas::setVencimento(long ven){
	vencimento=ven;
}
double Multas::getValor(){
	return valor;
}
void Multas::setValor(double val){
	valor =val;
}

int Multas::getIdCentroCusto(){
	return idCentroCusto;

}
void Multas::setIdCentroCusto(int icv){
	idCentroCusto=icv;
}

CustosVariaveis Multas::getCustosVariaveis(){
	return cv;
}
void Multas::setCustosVariaveis(CustosVariaveis ccv){
	cv=ccv;
}

Multas::~Multas() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
