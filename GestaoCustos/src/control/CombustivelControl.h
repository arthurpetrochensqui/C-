/*
 * CombustivelControl.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_COMBUSTIVELCONTROL_H_
#define SRC_CONTROL_COMBUSTIVELCONTROL_H_
#include "../model/Combustivel.h"
#include "../model/CustosVariaveis.h"
#include "../service/Arquivo.h"

#include <iostream>
#include <fstream>

namespace std {

class CombustivelControl {
public:
	CombustivelControl();
	virtual ~CombustivelControl();

	bool inserirCombustivel();
	bool alterarCombustivel();
	bool removerCombustivel();
	bool listarCombustivel();
	bool verificarArquivo();

	void outputLine();
	void outputLine(ostream&,Combustivel&);

	int getCodigo(const char *);

};

} /* namespace std */

#endif /* SRC_CONTROL_COMBUSTIVELCONTROL_H_ */
