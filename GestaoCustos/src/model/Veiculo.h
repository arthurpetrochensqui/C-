/*
 * Veiculo.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_VEICULO_H_
#define SRC_MODEL_VEICULO_H_

#include <string>
#include <iostream>

namespace std {

class Veiculo {
public:
	Veiculo();


	//Construct that receive the values of proper
	Veiculo(int, string,string, int);

	virtual ~Veiculo();

	bool lerVeiculo() {
		return true;
	}

	//Define method encapsulation id
	int getVeiculoId();
	void setVeiculoId(int);

	//define method encapsulation placa
	string getPlaca();
	void setPlaca(string);

	string getRenavam();
	void setRenavam(string);

	int getQuilometragem();
	void setQuilmetragem(int);


private:
	int id;
	char placa[20];
	char renavam[20];
	int quilometragem;
};

/* namespace std */
}
#endif /* SRC_MODEL_VEICULO_H_ */
