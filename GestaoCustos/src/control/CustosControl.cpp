/*
 * CustosControl.cpp
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#include "CustosControl.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
//#include "../model/CustosFixos.h"

namespace std {

CustosControl::CustosControl() {
	// TODO Auto-generated constructor stub
	fstream inOutCustos("custos.txt", ios::in | ios::out | ios::binary);

}

CustosControl::~CustosControl() {
	// TODO Auto-generated destructor stub
}

void CustosControl::listarCustos(string name, fstream &readFromFile) {

	ofstream inOutCusto("custos.txt", ios::in | ios::out | ios::binary);
	if (!inOutCusto) {
		cerr << "Arquivo não pode ser aberto ." << endl;
		exit(1);
	}

	//set file-position point to beginning of readFromFile
	inOutCusto << left << setw(10) << "ID" << setw(50) << "Nome" << endl;

	readFromFile.seekg(0);

	//read first record form record file

	CustosFixos custos;

	//readFromFile.read(reinterpret_cast<char *>(&custos), sizeof(CustosFixos));

	while (!readFromFile.eof()) {
		if (custos.getCodigo() != 0)
			outputLine(inOutCusto, custos);

		//read nex record from record file
		readFromFile.read(reinterpret_cast<char *>(&custos),
				sizeof(CustosFixos));

	}

	//CustosFixos custoFixos();
}

void CustosControl::outputLine(int codigo, const string nome) {
	cout << left << setw(10) << codigo << setw(50) << nome << endl;
}

void CustosControl::outputLine(ofstream &output, CustosFixos &record) {
	cout << left << setw(10) << record.getCodigo() << setw(50)
			<< record.getNome() << endl;
}

} /* namespace std */
