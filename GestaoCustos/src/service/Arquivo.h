/*
 * Arquivo.h
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_SERVICE_ARQUIVO_H_
#define SRC_SERVICE_ARQUIVO_H_

#include "sys/stat.h"
#include "string"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <fstream>


namespace std {

class Arquivo {
public:
	Arquivo();
	virtual ~Arquivo();
	bool arquivoExist(const string& );

};

} /* namespace std */

#endif /* SRC_SERVICE_ARQUIVO_H_ */
