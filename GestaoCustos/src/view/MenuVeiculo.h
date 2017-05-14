/*
 * MenuVeiculo.h
 *
 *  Created on: 3 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_VIEW_MENUVEICULO_H_
#define SRC_VIEW_MENUVEICULO_H_

#include "../control/VeiculoControl.h"

namespace std {

class MenuVeiculo {
public:
	MenuVeiculo();
	void listarMenu();
	virtual ~MenuVeiculo();
};

} /* namespace std */

#endif /* SRC_VIEW_MENUVEICULO_H_ */
