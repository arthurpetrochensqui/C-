/*
 * CustosVariaveis.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "CustosVariaveis.h"

namespace std {

CustosVariaveis::CustosVariaveis() {
	// TODO Auto-generated constructor stub

}

CustosVariaveis::~CustosVariaveis() {
	// TODO Auto-generated destructor stub
}

CustosVariaveis::CustosVariaveis(int c,string nome,int cv)
:Custos(c,nome,cv){

	setCodigo(c);
	setNome(nome);
	setCodigoContabil(cv);
}

double CustosVariaveis::returnTotal()const{
	return 0.0;
}


} /* namespace std */
