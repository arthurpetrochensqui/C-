/*
 * MotoristaControl.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_MOTORISTACONTROL_H_
#define SRC_CONTROL_MOTORISTACONTROL_H_
#include <string>
#include "../model/Motorista.h"
#include "../service/Arquivo.h"
#include <iostream>
#include <fstream>

namespace std {

class MotoristaControl {
public:
	MotoristaControl();

    bool listarMotorista();
    bool inserirMotorista();
    bool alterarMotorista();
    bool removerMotorista();
    bool verificarArquivo();

    void lineOutPut(ostream&,Motorista&);
    void lineOutHead();

    int getCodigo(const char *);


	virtual ~MotoristaControl();
private:

};

} /* namespace std */

#endif /* SRC_CONTROL_MOTORISTACONTROL_H_ */
