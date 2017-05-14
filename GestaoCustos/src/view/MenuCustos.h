/*
 * MenuCustos.h
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_VIEW_MENUCUSTOS_H_
#define SRC_VIEW_MENUCUSTOS_H_

#include "../control/CustosControl.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
namespace std {

class MenuCustos {
public:
	MenuCustos();
	void showMenu();
	virtual ~MenuCustos();
};

} /* namespace std */

#endif /* SRC_VIEW_MENUCUSTOS_H_ */
