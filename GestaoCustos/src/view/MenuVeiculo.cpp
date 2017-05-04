/*
 * MenuVeiculo.cpp
 *
 *  Created on: 3 de mai de 2017
 *      Author: arthur
 */

#include "MenuVeiculo.h"
#include <iostream>
namespace std {

enum CHOICES {LISTAR=1,CADASTRAR,ATUALIZAR,EXCLUIR,SAIR};


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

	int choice;

	cout << "1 listar veiculo\n" << "2 - Cadastrar Veiculo\n"
			<< "3 - Pesquisar Veiculo\n" << "4 - Excluir Veiculo\n"
			<< "5 - Sair\n" << endl;
	cin>>choice;
	//while (choice != 5) {
		switch (choice) {
		case 1:
			cout << "Cadastrar Veiculo\n";
			break;
		case 5:
			cout << "Exit";
			break;
		}
	//}
}
} /* namespace std */
