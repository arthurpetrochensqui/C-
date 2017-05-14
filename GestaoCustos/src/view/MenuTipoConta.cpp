/*
 * MenuTipoConta.cpp
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 */

#include "MenuTipoConta.h"

namespace std {

MenuTipoConta::MenuTipoConta() {
	// TODO Auto-generated constructor stub

}

MenuTipoConta::~MenuTipoConta() {
	// TODO Auto-generated destructor stub
}
void MenuTipoConta::showMenu() {

	TipoContaControl tc;



	cout << "\nOperacoes Contas Operacionais: Selecione um opção:\n" << endl;

	int choice;

	//while (choice != 5) {
	do {
		cout << "\n1 - listar Tipo Conta\n" << "2 - Cadastrar Tipo Conta\n"
				<< "3 - Alterar Tipo Conta\n" << "4 - Excluir Tipo Conta\n"
				<< "5 - Sair\n" << endl;
		cin >> choice;
		switch (choice) {
		case LISTAR:

			tc.listarRegistro();
			//cout << "Listar Veiculos :" << endl;

			break;
		case CADASTRAR:
			tc.salvarTipoConta();
			//cout << "Cadastrar Custo \n" << endl;
			break;
		case ATUALIZAR:
			//cout << "Atualizar Custo" << endl;
			tc.alterarTipoConta();
			break;
		case EXCLUIR:
			tc.removerTipoConta();
			break;
		case SAIR:
			cout << "Sair";
			break;
		}
	} while (choice < 5);

	//}
}
} /* namespace std */
