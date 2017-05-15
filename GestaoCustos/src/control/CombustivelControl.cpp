/*
 * CombustivelControl.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "CombustivelControl.h"

namespace std {

CombustivelControl::CombustivelControl() {
	verificarArquivo();
}

CombustivelControl::~CombustivelControl() {
	// TODO Auto-generated destructor stub
}

bool CombustivelControl::verificarArquivo() {
	bool achou = false;
	Arquivo arq;

	if (arq.arquivoExist("combustivel.dat") == false) {
		ofstream out("combustivel.dat", ios::out);

		Combustivel c(0, 0, 0, 0.0, 0);
		for (int i = 0; i < 100; ++i) {
			out.write(reinterpret_cast<char *>(&c), sizeof(Combustivel));
		}
	}
	return achou;
}

//Listar Combustivel
bool CombustivelControl::listarCombustivel() {
	bool hasRegistro = false;
	try {
		fstream fs("combustivel.dat", ios::in | ios::out | ios::binary);
		if (!fs) {
			cerr << "Erro ao abrir combustivel.dat" << endl;
			exit(1);
		}

		ofstream print("print.txt", ios::out);
		if (!print) {
			cerr << "Erro ao abrir arquivo temporario" << endl;
			exit(1);
		}

		cout << left << setw(10) << "ID" << setw(10) << "Data" << setw(10)
				<< "QTD" << setw(10) << "Valor" << setw(10) << "Centro Custo"
				<< endl;

		print << left << setw(10) << "ID" << setw(10) << "Data" << setw(10)
				<< "QTD" << setw(10) << "Valor" << setw(10) << "Centro Custo"
				<< endl;

		//int codigo = getCodigo("Insira o codigo: ");
		Combustivel c;
		fs.read(reinterpret_cast<char *>(&c), sizeof(Combustivel));

		while (fs && !fs.eof()) {
			if (c.getCodigo() != 0) {
				outputLine(print, c);
				hasRegistro = true;

			}
			fs.read(reinterpret_cast<char *>(&c), sizeof(Combustivel));
		}

	} catch (exception &) {
		throw;
	}
	return hasRegistro;
}

//Inseir Combustivel
bool CombustivelControl::inserirCombustivel() {
	bool inseriu = false;
	try {
		fstream fs("combustivel.dat", ios::in | ios::out | ios::binary);
		if (!fs) {
			cerr << "Erro ao abrir arquivo combustivel.dat" << endl;
			exit(1);
		}
		int codigo = getCodigo("Insira um codigo: ");

		fs.seekg((codigo - 1) * sizeof(Combustivel));

		Combustivel c;
		fs.read(reinterpret_cast<char *>(&c), sizeof(Combustivel));

		CustosVariaveis cv(1, "Custos Variaveis", 10002);

		if (c.getCodigo() == 0) {
			long data;
			int quantidade;
			double valor;

			cout << "\nInsira a data: ";
			cin >> data;
			cout << "\nInsira a quantidade:";
			cin >> quantidade;
			cout << "\nInsira o valor:";
			cin >> valor;

			c.setCodigo(codigo);
			c.setData(data);
			c.setQuantidade(quantidade);
			c.setValor(valor);
			c.setCentroCusto(cv.getCodigo());

			fs.seekp((codigo - 1) * sizeof(Combustivel));

			fs.write(reinterpret_cast<char *>(&c), sizeof(Combustivel));

			inseriu = true;
		} else {
			cerr << "Erro ao Inserir combustivel." << endl;
		}

	} catch (exception &) {
		throw;
	}
	return inseriu;
}

//atualizar combustivel

bool CombustivelControl::alterarCombustivel() {
	bool alterou = false;
	try {
		fstream fs("combustivel.dat", ios::in | ios::out | ios::binary);
		if (!fs) {
			cerr << "Erro ao abrir arquivo combustivel" << endl;
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo: ");

		fs.seekg((codigo - 1) * sizeof(Combustivel));

		Combustivel c;
		fs.read(reinterpret_cast<char *>(&c), sizeof(Combustivel));

		CustosVariaveis cv(1, "Custos Variaveis", 10002);

		if (c.getCodigo() != 0) {

			outputLine();
			outputLine(cout, c);

			long data;
			int quantidade;
			double valor;

			cout << "\nInsira a data: ";
			cin >> data;
			cout << "\nInsira a quantidade:";
			cin >> quantidade;
			cout << "\nInsira o valor:";
			cin >> valor;

			//c.setCodigo(codigo);
			c.setData(data);
			c.setQuantidade(quantidade);
			c.setValor(valor);
			//c.setCentroCusto(cv.getCodigo());

			fs.seekp((codigo - 1) * sizeof(Combustivel));

			fs.write(reinterpret_cast<char *>(&c), sizeof(Combustivel));

			alterou = true;
		} else {

		}

	} catch (exception&) {
		throw;
	}

	return alterou;
}

bool CombustivelControl::removerCombustivel(){
	bool removeu;
	try{
		fstream fs("combustivel.dat",ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo combustivel.dat"<<endl;
			exit(1);
		}

		int codigo=getCodigo("\nInsira o codigo combustivel a ser removido");

		fs.seekg((codigo-1)*sizeof(Combustivel));

		Combustivel c;
		fs.read(reinterpret_cast<char *>(&c),sizeof(Combustivel));

		if(0 !=c.getCodigo()){
			Combustivel cBlank;

			fs.seekp((codigo-1)*sizeof(Combustivel));

			fs.write(reinterpret_cast<char *>(&cBlank),sizeof(Combustivel));
			removeu=true;
			cout<<"Combustivel #"<<codigo<<" removido\n";
		}else{
			cout<<"Combustivel #"<<codigo<<" não foi possivel remover"<<endl;
		}

	}catch(exception &){
		throw;
	}
	return removeu;
}

void CombustivelControl::outputLine(){
	cout << left << setw(10) << "ID" << setw(10) << "Data" << setw(10)
					<< "QTD" << setw(10) << "Valor" << setw(10) << "Centro Custo"
					<< endl;
}

void CombustivelControl::outputLine(ostream &output,Combustivel &c){
	CustosVariaveis cv(1, "Custos Variaveis", 10002);

	cout << left << setw(10) << c.getCodigo() << setw(10) << c.getData() << setw(10)
					<< c.getQuantidade() << setw(10) << c.getValor() << setw(10) << cv.getNome()
					<< endl;
}

int CombustivelControl::getCodigo(const char * const prompt){
	int codigo;
	do{
		cout<<prompt<<":";
		cin>>codigo;

	}while(codigo>1 || codigo<100);
	return codigo;
}
} /* namespace std */
