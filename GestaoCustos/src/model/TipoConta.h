/*
 * TipoConta.h
 *
 *  Created on: 9 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_TIPOCONTA_H_
#define SRC_MODEL_TIPOCONTA_H_
#include "CustosFixos.h"
#include <string>

namespace std {

class TipoConta {
public:
	TipoConta();
	//Create a construct overload
	TipoConta(int,string,double,string,int);

	virtual ~TipoConta();

	int getCodigo() const;

	void setCodigo(int);

	string getContaContabil() const;

	void setContaContabil(string);


	int getCustosFixos() const;

	void setCustosFixos(int);

	const string getData() const;

	void setData(string );

	double getValor() const;

	void setValor(double);

	//define get and sets

private:
	int codigo;
	char contaContabil[10];
	double valor;
	char data[10];
	int custosFixos;




};

} /* namespace std */

#endif /* SRC_MODEL_TIPOCONTA_H_ */
