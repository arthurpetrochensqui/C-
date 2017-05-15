/*
 * Combustivel.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_COMBUSTIVEL_H_
#define SRC_MODEL_COMBUSTIVEL_H_

#include "CustosVariaveis.h"
namespace std {

class Combustivel {
public:
	Combustivel();
	Combustivel(int,long,int,double,int);
	virtual ~Combustivel();

	int getCodigo();
	void setCodigo(int);

	long getData();
	void setData(long);

	int getQuantidade();
	void setQuantidade(int);

	double getValor();
	void setValor(double);

	int getCentroCusto();
	void setCentroCusto(int);

	CustosVariaveis getCustosVariaveis();
	void setCustosVariaveis(CustosVariaveis);
private:
	int codigo;
	long data;
	double quantidade;
	double valor;
	CustosVariaveis cv;
	int centroCusto;
};

} /* namespace std */

#endif /* SRC_MODEL_COMBUSTIVEL_H_ */
