/*
 * CustosFixos.h
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_CUSTOSFIXOS_H_
#define SRC_MODEL_CUSTOSFIXOS_H_

#include "Custos.h"
#include <list>
#include <iostream>
#include <iomanip>
#include <string>

namespace std {

class CustosFixos: public Custos {

	friend ostream &operator<<(ostream &, const CustosFixos &);
	friend istream &operator>>(istream &, CustosFixos &);

public:
	CustosFixos();
	CustosFixos(int, string,int);

	//Implement Method that return sum of account
	double returnTotal() const;
	virtual ~CustosFixos();

	template<typename T> void listarCustos(const list<T>&listRef);

private:
	//string nome;

};

} /* namespace std */

#endif /* SRC_MODEL_CUSTOSFIXOS_H_ */
