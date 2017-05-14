/*
 * Pneus.h
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_PNEUS_H_
#define SRC_MODEL_PNEUS_H_

#include "Veiculo.h"

namespace std {

class Pneus {
public:
	Pneus();
	Pneus(int,int,int,int,double);
	virtual ~Pneus();

	int getId();
	void setId(int);

	int getQuilometragem();
	void setQuilometragem(int);

	int getEixo();
	void setEixo(int);

	int getIdVeiculo();
	void setIdVeiculo(int);

	double getValor();
	void setValor(double);

	int getVidaUtil();
	void setVidaUtil(int);

	Veiculo getVeiculo();
	void setVeiculo(Veiculo);

private:
	int id;
	int quilometragem;
	int eixo;
	int idVeiculo;
	double valor;
	int vidaUtil;
	Veiculo veiculo;


};

} /* namespace std */

#endif /* SRC_MODEL_PNEUS_H_ */
