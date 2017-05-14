/*
 * Arquivo.cpp
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 */

#include "Arquivo.h"

namespace std {

Arquivo::Arquivo() {
	// TODO Auto-generated constructor stub

}

Arquivo::~Arquivo() {
	// TODO Auto-generated destructor stub
}

//this method verified if the file exists
bool Arquivo::arquivoExist(const string& nomeArquivo){
		struct stat buf;

		if (stat(nomeArquivo.c_str(), &buf) != -1) {
			return true;
		}

		return false;
}



} /* namespace std */
