/*
 * Pneus.cpp
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#include "Pneus.h"

namespace std {

Pneus::Pneus() {
	// TODO Auto-generated constructor stub

}

Pneus::~Pneus() {
	// TODO Auto-generated destructor stub
}
Pneus::Pneus(int i,int km,int ei,int idVeic,double v){
	id=i;
	quilometragem = km;
	eixo=ei;
	idVeiculo=idVeic;
	valor=v;
}

int Pneus::getId(){
	return id;
}
void Pneus::setId(int i){
	id=i;
}

int Pneus::getQuilometragem(){
	return quilometragem;
}
void Pneus::setQuilometragem(int km){
	quilometragem=km;
}
int Pneus::getEixo(){
	return eixo;
}
void Pneus::setEixo(int e){
	eixo=e;
}

int Pneus::getIdVeiculo(){
	return idVeiculo;
}

void Pneus::setIdVeiculo(int idV){
	idVeiculo=idV;
}

double Pneus::getValor(){
	return valor;
}

void Pneus::setValor(double v){
	valor=v;
}

int Pneus::getVidaUtil(){
	return vidaUtil;
}
void Pneus::setVidaUtil(int vi){
	vidaUtil=vi;
}

Veiculo Pneus::getVeiculo(){
	return veiculo;
}
void Pneus::setVeiculo(Veiculo veic){
	veiculo=veic;
}


} /* namespace std */
