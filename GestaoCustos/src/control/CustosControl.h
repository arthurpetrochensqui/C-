/*
 * CustosControl.h
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_CUSTOSCONTROL_H_
#define SRC_CONTROL_CUSTOSCONTROL_H_

#include "../model/CustosFixos.h"
#include "../service/Arquivo.h"
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <list>
#include <string>
namespace std {

class CustosControl {

public:
	CustosControl();
	virtual ~CustosControl();
	//bool listarCustos(string);
	void outputLine2(int, string);
	void outputLine(ostream&, CustosFixos &);

	//Metodo Cadastrar Custo
	string  cadastrarCusto();
	string  atualizarCusto();
	string  deletarCusto();
	string listarRegistro();

	//Metodo verifica se o arquivo existe deverá estar no construtor
	//não existir criar o arquivo com a estrutura vazia
	void criarArquivoInicial();

	//define o fstream para os metodos
	fstream retornafStream();




	//this methods add


	//Retorno codigo
	int getCodigo(const char * const);



private:
	//fstream file;
	//list<CustosFixos>listCustosFixo;
};

} /* namespace std */

#endif /* SRC_CONTROL_CUSTOSCONTROL_H_ */
