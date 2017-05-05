/*
 * CustosFixos.cpp
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#include "CustosFixos.h"

namespace std {

CustosFixos::CustosFixos() {

}

CustosFixos::CustosFixos(int id, string n) :
		Custos(id, n) {
	nome = n;

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
