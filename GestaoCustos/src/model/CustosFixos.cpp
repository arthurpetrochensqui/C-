/*
 * CustosFixos.cpp
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#include "CustosFixos.h"

namespace std {

//Sobrecarga operador stream inserção; não pode ser uma função membro
//se nós quiser acessar a operacao como cout<<algumCustoFixo
ostream &operator<<(ostream &output, const CustosFixos &cf){
	output <<cf.codigo <<cf.nome<<"\n";
	return output;
}

//Sobrecarga operador strem extração, não pose ser uma função membro
istream &operator>>(istream &input, CustosFixos &cf){

	input>>cf.codigo>>cf.nome;
	return input;
}


CustosFixos::CustosFixos() {

}

CustosFixos::CustosFixos(int id, string n, int cc) :
		Custos(id, n,cc) {
	setCodigo(id);
	setNome(n);
	setCodigoContabil(cc);

}

CustosFixos::~CustosFixos() {
	// TODO Auto-generated destructor stub
}

double CustosFixos::returnTotal() const {
	//This Method I Need read a list and sum the value of each account registred

	return 0.0;
}

template<typename T> void listarCustos(const list<T>&listRef) {

	list<CustosFixos> list = NULL;
	//list.insert(custosFixos);

}

} /* namespace std */
