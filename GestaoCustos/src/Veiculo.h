/*
 * Veiculo.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include <iostream>

namespace std {

class Veiculo {
public:
	Veiculo();

	//Construct that receive the values of proper
	Veiculo(int, string);

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

private:
	int id;
	string placa;
};

/* namespace std */
}
#endif /* SRC_VEICULO_H_ */
