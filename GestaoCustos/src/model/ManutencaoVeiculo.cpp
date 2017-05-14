/*
 * ManutencaoVeiculo.cpp
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#include "ManutencaoVeiculo.h"

namespace std {

ManutencaoVeiculo::ManutencaoVeiculo() {
	// TODO Auto-generated constructor stub

}

//Construtor sobrecarregado
ManutencaoVeiculo::ManutencaoVeiculo(Veiculo veic){
	veiculo=veic;
}

//Construtor sobrecarregado criar arquivo
ManutencaoVeiculo::ManutencaoVeiculo(int id,long dat,double val,int idVeic){
	codigo=id;
	data=dat;
	valor=val;
	idVeiculo=idVeic;
}

ManutencaoVeiculo::~ManutencaoVeiculo() {
	// TODO Auto-generated destructor stub
}

int ManutencaoVeiculo::getCodigo(){
	return codigo;
}
void ManutencaoVeiculo::setCodigo(int c){
	codigo=c;
}

Veiculo ManutencaoVeiculo::getVeiculo(){
	return veiculo;
}
void ManutencaoVeiculo::setVeiculo(Veiculo veic){
	veiculo=veic;
}

int ManutencaoVeiculo::getIdVeiculo(){
	return idVeiculo;
}

void ManutencaoVeiculo::setIdVeiculo(int idVeic){
	idVeiculo=idVeic;
}

double ManutencaoVeiculo::getValor(){
	return valor;
}
void ManutencaoVeiculo::setValor(double val){
	valor = val;
}

void ManutencaoVeiculo::setData(long dt){
	data=dt;
}

long ManutencaoVeiculo::getData(){
	return data;
}
} /* namespace std */
