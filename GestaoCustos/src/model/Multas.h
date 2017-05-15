/*
 * Multas.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_MULTAS_H_
#define SRC_MODEL_MULTAS_H_

#include "CustosVariaveis.h"

namespace std {

class Multas {
public:
	Multas();
	Multas(int, long,long,double,int);

	int getCodigo();
	void setCodigo(int);

	long getData();
	void setData(long);

	long getVencimento();
	void setVencimento(long);

	double getValor();
	void setValor(double);

	CustosVariaveis getCustosVariaveis();
	void setCustosVariaveis(CustosVariaveis cv);

	int getIdCentroCusto();
	void setIdCentroCusto(int);

	virtual ~Multas();
private:
	int codigo;
	long data;
	long vencimento;
	double valor;
	CustosVariaveis cv;
	int idCentroCusto;
};

} /* namespace std */

#endif /* SRC_MODEL_MULTAS_H_ */
