/*
 * CustosControl.h
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_CUSTOSCONTROL_H_
#define SRC_CONTROL_CUSTOSCONTROL_H_

#include "../model/CustosFixos.h"

namespace std {

class CustosControl {
public:
	CustosControl();
	virtual ~CustosControl();
	void listarCustos(string, fstream &);
	void outputLine(int, string);
	void outputLine(ofstream&, CustosFixos &);

};

} /* namespace std */

#endif /* SRC_CONTROL_CUSTOSCONTROL_H_ */
