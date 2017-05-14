/*
 * VeiculoControl.h
 *
 *  Created on: 12 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_VEICULOCONTROL_H_
#define SRC_CONTROL_VEICULOCONTROL_H_

#include "../service/Arquivo.h"
#include "../model/Veiculo.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace std {

class VeiculoControl {
public:
	VeiculoControl();
	virtual ~VeiculoControl();

	bool inserirVeiculo();
	bool listarVeiculo();
	bool removerVeiculo();
	bool alterarVeiculo();

	void outputLine(ostream&,Veiculo&);
    void outputHead();

	int getCodigo(const char  *);

	void verificaArquivo();


};

} /* namespace std */

#endif /* SRC_CONTROL_VEICULOCONTROL_H_ */
