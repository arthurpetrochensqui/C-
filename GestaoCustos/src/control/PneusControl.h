/*
 * PneusControl.h
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_PNEUSCONTROL_H_
#define SRC_CONTROL_PNEUSCONTROL_H_

#include "../model/Pneus.h"
#include "../service/Arquivo.h"

#include <fstream>
#include <iostream>

namespace std {

class PneusControl {
public:
	PneusControl();
	PneusControl(Veiculo);

	bool listarPneus();
	bool inserirPneu();
	bool alterarPneu();
	bool removerPneu();


	bool verificaArquivo();

	void outputLine(ostream&,Pneus&);
	void outputHead();

	int getCodigo(const char *);




	virtual ~PneusControl();

private:
	Veiculo veiculo;
};

} /* namespace std */

#endif /* SRC_CONTROL_PNEUSCONTROL_H_ */
