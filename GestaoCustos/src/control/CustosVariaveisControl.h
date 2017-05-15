/*
 * CustosVariaveisControl.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_CUSTOSVARIAVEISCONTROL_H_
#define SRC_CONTROL_CUSTOSVARIAVEISCONTROL_H_
#include <iostream>
#include <fstream>

#include "../model/CustosVariaveis.h"
#include "../service/Arquivo.h"

namespace std {

class CustosVariaveisControl {
public:
	CustosVariaveisControl();
	virtual ~CustosVariaveisControl();

	bool inserirCustosVariaveis();
	bool alterarCustosVariaveis();
	bool removerCustosVariaveis();
	bool listarCustosVariaveis();
	bool verificarArquivo();


	void outputLine(ostream&,CustosVariaveis&);
	void output();

	int getCodigo(const char *);



};

} /* namespace std */

#endif /* SRC_CONTROL_CUSTOSVARIAVEISCONTROL_H_ */
