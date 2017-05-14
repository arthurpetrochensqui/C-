/*
 * Motorista.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_MOTORISTA_H_
#define SRC_MODEL_MOTORISTA_H_

#include <iostream>
#include <string>

namespace std {

class Motorista {
public:
	Motorista();
	Motorista(int,string,double);
	virtual ~Motorista();

	int getId();
	void setId(int);

	string getNome();
	void setNome(string);

	double getSalario();
	void setSalario(double);

private:
	int id;
	char  nome[30];
	double salario;
};

} /* namespace std */

#endif /* SRC_MODEL_MOTORISTA_H_ */
