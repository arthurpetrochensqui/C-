/*
 * Principal.cpp
 *
 *  Created on: 3 de mai de 2017
 *      Author: arthur
 */
#include <iostream>
#include "src/view/MenuVeiculo.h"
#include "src/view/MenuCustos.h"
#include "src/view/MenuTipoConta.h"
using namespace std;

//Get option from user
int optionChoice(); //prototype



int main(){

	MenuVeiculo veiculo;
	MenuCustos menuCusto;
	MenuTipoConta menuTipoConta;
	cout<<"\Menu Principal - Escolha Uma Opção"<<endl;
	//store user choice
	int choice;

	//enable user to specify action
	while((choice=optionChoice())!=-1){
		switch(choice){
				case 1:
					//cout<<"Escolheu Veiculo";
					veiculo.listarMenu();


					break;
				case 2:

					menuCusto.showMenu();
					break;
					//cout<<"Escolheu outra opcao";

				case 3:
					menuTipoConta.showMenu();
					break;
				}

	}
}

//Implements Menu Option Information About GestaoCustos
int optionChoice(){
	cout<<"\n Selecione uma opção \n 1 - Veiculo";
	cout<<"\n 2 - Custos";
	cout<<"\n 3 - Tipo Conta";

	int opcao;
	cout<<"\n ?:";
	cin>>opcao;

	return opcao;
	//cout<<opcao<<cin;
}




