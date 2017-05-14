/*
== * TipoContaControl.h
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_TIPOCONTACONTROL_H_
#define SRC_CONTROL_TIPOCONTACONTROL_H_
#include "../service/Arquivo.h"
#include "../model/TipoConta.h"
#include "../model/CustosFixos.h"
#include <iostream>
#include <fstream>

namespace std {

class TipoContaControl {
public:

	TipoContaControl();

	bool salvarTipoConta();

	bool alterarTipoConta();

	bool removerTipoConta();


	bool verificaArquivoExiste();

	int getCodigo(const char * const);

	bool listarRegistro();

	void outputLine(ostream&,TipoConta &);

	CustosFixos retornaCustosFixos(int);

	virtual ~TipoContaControl();


private:

	//TipoConta tp;

};

} /* namespace std */

#endif /* SRC_CONTROL_TIPOCONTACONTROL_H_ */
