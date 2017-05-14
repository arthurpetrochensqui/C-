/*
 * MenuCustos.cpp
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#include "MenuCustos.h"

namespace std {

enum CHOICES {
	LISTAR = 1, CADASTRAR, ATUALIZAR, EXCLUIR, SAIR
};

MenuCustos::MenuCustos() {
	// TODO Auto-generated constructor stub

}

MenuCustos::~MenuCustos() {
	// TODO Auto-generated destructor stub
}
void MenuCustos::showMenu() {

	CustosControl cc;



	cout << "Opções Custos: Selecione um opção:\n" << endl;

	int choice;

	//while (choice != 5) {
	do {
		cout << "1 - listar custos\n" << "2 - Cadastrar Custos\n"
				<< "3 - Pesquisar Custos\n" << "4 - Excluir Custos\n"
				<< "5 - Sair\n" << endl;
		cin >> choice;
		switch (choice) {
		case LISTAR:

			cc.listarRegistro();
			//cout << "Listar Veiculos :" << endl;

			break;
		case CADASTRAR:
			cc.cadastrarCusto();
			//cout << "Cadastrar Custo \n" << endl;
			break;
		case ATUALIZAR:
			//cout << "Atualizar Custo" << endl;
			cc.atualizarCusto();
			break;
		case EXCLUIR:
			cc.deletarCusto();
			break;
		case SAIR:
			cout << "Sair";
			break;
		}
	} while (choice < 5);

	//}
}

} /* namespace std */
