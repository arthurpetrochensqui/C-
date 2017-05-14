/*
 * MenuVeiculo.cpp
 *
 *  Created on: 3 de mai de 2017
 *      Author: arthur
 */

#include "MenuVeiculo.h"
#include <iostream>
namespace std {

enum CHOICES {
	LISTAR = 1, CADASTRAR, ATUALIZAR, EXCLUIR, SAIR
};

MenuVeiculo::MenuVeiculo() {
	// TODO Auto-generated constructor stub
	//listarMenu();
}

MenuVeiculo::~MenuVeiculo() {
	// TODO Auto-generated destructor stub
}

void MenuVeiculo::listarMenu() {
	//This Method  must list option that user go realize in the classe:
	cout << "MenuVeiculo: Selecione um opção:" << endl;

	VeiculoControl vc;

	int choice;

	//while (choice != 5) {
	do {

		cout << "\n1 - listar veiculo\n" << "2 - Cadastrar Veiculo\n"
				<< "3 - Pesquisar Veiculo\n" << "4 - Excluir Veiculo\n"
				<< "5 - Sair\n" << endl;

		cin >> choice;
		switch (choice) {
		case LISTAR:
			vc.listarVeiculo();
			break;
		case CADASTRAR:
			vc.inserirVeiculo();
			break;
		case ATUALIZAR:
			vc.alterarVeiculo();
			break;
		case EXCLUIR:
			vc.removerVeiculo();
			break;
		case SAIR:
			cout << "Sair\n";
			break;
		}
	} while (choice < 5);

	//}
}
} /* namespace std */
