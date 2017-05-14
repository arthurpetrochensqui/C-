/*
 * ManutencaoVeiculo.h
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_MANUTENCAOVEICULO_H_
#define SRC_MODEL_MANUTENCAOVEICULO_H_
#include "Veiculo.h"

namespace std {

class ManutencaoVeiculo {
public:
	ManutencaoVeiculo();
	ManutencaoVeiculo(int,long,double,int);
	ManutencaoVeiculo(Veiculo);

	virtual ~ManutencaoVeiculo();

	int getCodigo();
	void setCodigo(int);

	Veiculo getVeiculo();
	void setVeiculo(Veiculo);

	long getData();
	void setData(long);

	double getValor();
	void setValor(double);

	int getIdVeiculo();
	void setIdVeiculo(int);


private:
	int codigo;
	long data;
	int idVeiculo;
	double valor;
	Veiculo veiculo;

};

} /* namespace std */

#endif /* SRC_MODEL_MANUTENCAOVEICULO_H_ */
