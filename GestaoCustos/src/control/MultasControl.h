/*
 * MultasControl.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_MULTASCONTROL_H_
#define SRC_CONTROL_MULTASCONTROL_H_
#include <iostream>
#include <fstream>

#include "../model/Multas.h"
#include "../service/Arquivo.h"
#include "../model/CustosVariaveis.h"

namespace std {

class MultasControl {
public:
	MultasControl();
	virtual ~MultasControl();

	bool adicionarMulta();
	bool listarMulta();
	bool removerMulta();
	bool alterarMulta();
	bool verificaArquivo();

	void outputLine(ostream&,Multas&);
	void outputLine();

	int getCodigo(const char *);


};

} /* namespace std */

#endif /* SRC_CONTROL_MULTASCONTROL_H_ */
