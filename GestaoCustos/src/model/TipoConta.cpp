/*
 * TipoConta.cpp
 *
 *  Created on: 9 de mai de 2017
 *      Author: arthur
 */

#include "TipoConta.h"
#include "time.h"

namespace std {

TipoConta::TipoConta() {
	// TODO Auto-generated constructor stub

}

TipoConta::TipoConta(int c, string cc, double valor, string data,int cf) {
	setCodigo(c);
	setContaContabil(cc);
	setValor(valor);
	setData(data);
	setCustosFixos(cf);
}

TipoConta::~TipoConta() {
	// TODO Auto-generated destructor stub
}

const string TipoConta::getData() const {

	return data;
}

void TipoConta::setData(string dt) {
	//this->data = data;
	int length = dt.size();
		length =(length < 10 ? length:8);
		dt.copy(data,length);

		data[length] ='\0';
}

int TipoConta::getCodigo() const {
	return codigo;
}

void TipoConta::setCodigo(int codigo) {
	this->codigo = codigo;
}

string TipoConta::getContaContabil() const {
	return contaContabil;
}

void TipoConta::setContaContabil(string cc) {
	//this->contaContabil = contaContabil;
	int length = cc.size();
		length =(length < 10 ? length:9);
		cc.copy(contaContabil,length);

		contaContabil[length] ='\0';


}

int TipoConta::getCustosFixos() const {
	return custosFixos;
}

void TipoConta::setCustosFixos(int cf) {
	custosFixos = cf;
}

double TipoConta::getValor() const {
	return valor;
}

void TipoConta::setValor(double v) {
	valor = v;
}

} /* namespace std */
