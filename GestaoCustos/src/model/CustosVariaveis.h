/*
 * CustosVariaveis.h
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_CUSTOSVARIAVEIS_H_
#define SRC_MODEL_CUSTOSVARIAVEIS_H_

#include "Custos.h"
namespace std {

class CustosVariaveis :public Custos {
public:
	CustosVariaveis();
	CustosVariaveis(int, string, int);

	double returnTotal() const;

	virtual ~CustosVariaveis();

};

} /* namespace std */

#endif /* SRC_MODEL_CUSTOSVARIAVEIS_H_ */
