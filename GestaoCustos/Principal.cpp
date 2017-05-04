/*
 * Principal.cpp
 *
 *  Created on: 3 de mai de 2017
 *      Author: arthur
 */
#include <iostream>
#include "src/view/MenuVeiculo.h"
using namespace std;

//Get option from user
int optionChoice(); //prototype



int main(){

	MenuVeiculo veiculo;
	cout<<"Menu Principal -Escolha Uma Opção"<<endl;
	//store user choice
	int choice;

	//enable user to specify action
	while((choice=optionChoice())!=-1){
		switch(choice){
				case 1:
					cout<<"Escolheu Veiculo";
					veiculo.listarMenu();


					break;
				case 2:
					cout<<"Escolheu outra opcao";
				}
	}
}

//Implements Menu Option Information About GestaoCustos
int optionChoice(){
	cout<<"1 - Veiculo\n";
	cout<<"2 - Custos\n";

	int opcao;
	cin>>opcao;

	return opcao;
	//cout<<opcao<<cin;
}




