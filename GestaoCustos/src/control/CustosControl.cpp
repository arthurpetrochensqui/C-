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
	//Verificar se o arquivo existe caso  contrario criar o arquivo
	cout << "Construtor" << endl;
	criarArquivoInicial();

}
//Metodo que verifica no construtor se o arquivo existe
CustosControl::~CustosControl() {

}

void CustosControl::criarArquivoInicial() {

	//verifica se o arquivo existe
	Arquivo arq;
	if (arq.arquivoExist("centroCusto.dat") == false) {

		//Arquivo não existe cria um novo
		ofstream fout("centroCusto.dat", ios::out | ios::binary);

		//tenta abrir o arquivo
		if (!fout) {
			cerr << "Nao foi possivel abrir o arquivo" << endl;
			exit(1);
		}

		//Classe vazia
		CustosFixos cf(0, "", 0);

		for (int i = 0; i < 10; ++i) {
			cout << "Criando estrutura construtor" << endl;
			fout.write(reinterpret_cast<const char *>(&cf),
					sizeof(CustosFixos));
		}

	}
}

string CustosControl::listarRegistro() {

	/**************************************/

	/*Implementado de forma sequencial

	 cout << "ListarCustos do Arquivo\n" << endl;
	 bool retorno = true;

	 CustosFixos cf;
	 ifstream ifs("centroCusto.txt",ios::in);

	 if(ifs.good())
	 {
	 while(!ifs.eof()){
	 ifs>>cf;

	 cout<<"CF001"<<"|"<<cf.getCodigo()<<"|"<<cf.getNome()<<endl;

	 }
	 ifs.close();
	 }

	 return retorno;
	 */

	/*

	 //Reading from a Random-Access File Sequentially
	 ifstream isf("centroCusto.txt", ios::in);

	 //exit program if ifstream cannot open file
	 if (!isf) {
	 cerr << "Arquivo não pode ser aberto" << endl;
	 exit(1);
	 }

	 cout << left << setw(10) << "Codigo" << setw(50) << "Nome" << endl;

	 CustosFixos cf;

	 //read first record from file
	 isf.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));

	 //read all records from file
	 while (isf && !isf.eof()) {

	 //display record
	 if (cf.getCodigo() != 0)
	 outputLine(cout, cf);
	 //cout<<cf;

	 //read next from file
	 isf.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));
	 }
	 */

	/*
	 * Arthur
	 * 09/05/2017 implementação acesso aleatorio
	 */
	ofstream outPrint("print.txt", ios::out);

	fstream readFrom("centroCusto.dat", ios::in | ios::out | ios::binary);

	if (!readFrom) {
		cerr << "Arquivo não pode ser aberto";
		exit(1);
	}
	//return ifs;

	//fstream readFrom=retornafStream();

	//sair se ofstream não poder ser criado
	if (!outPrint) {
		cerr << "Arquivo não pode ser criado" << endl;
		exit(1);
	}

	outPrint << left << setw(10) << "Codigo" << setw(20) << "Nome" << setw(10)
			<< "Código Contábil" << endl;

	//configura posição arquivo apontar para o inicio do readFromFile
	readFrom.seekg(0);

	//leia o primeiro registro do readFromFile
	CustosFixos cf;
	readFrom.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));

	//copia todos os registros do arquivo para dentro arquivo texto
	while (readFrom && !readFrom.eof()) {

		//cout << "." << endl;
		//escreva simples registro para o text file
		if (cf.getCodigo() != 0)
			outputLine(outPrint, cf);

		//leia o proximo registro do arquivo
		readFrom.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));
	}

	return "";

}

void CustosControl::outputLine2(int codigo, const string nome) {
	cout << left << setw(10) << codigo << setw(50) << nome << endl;
}

void CustosControl::outputLine(ostream &output, CustosFixos &record) {
	cout << left << setw(10) << record.getCodigo() << setw(50)
			<< record.getNome() << record.getCodigoContabil() << endl;
}

//Create a new Record
string CustosControl::cadastrarCusto() {

	/* Nova Versao do codigo cadastrar custo
	 ofstream out("centroCusto.txt", ios::out | ios::binary | ios::app);

	 if (!out) {
	 cerr << "Arquivo não pode ser aberto" << endl;
	 exit(1);
	 }


	 int codigo = getCodigo("Digite o número da nova conta:");

	 CustosFixos custosFixos;
	 string nome;

	 custosFixos.setCodigo(codigo);
	 cout << "Digite o nome centro custo:\n";
	 cin >> nome;
	 custosFixos.setNome(nome);

	 cout << "Codigo: " << custosFixos.getCodigo() << " | Nome: "
	 << custosFixos.getNome() << endl;
	 out << custosFixos;

	 */

	//obtem o codisgo do registro para criar
	try {
		//fstream inserir = retornafStream();
		fstream inserir("centroCusto.dat", ios::in | ios::out | ios::binary);

		if (!inserir) {
			cerr << "Arquivo não pode ser aberto";
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo ");

		//move o ponteiro para o correto registro no arquivo
		inserir.seekg((codigo - 1) * sizeof(CustosFixos));

		//Leia o registro From arquivo
		CustosFixos cf;
		inserir.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));

		//cria o registro, se o registro não exisitr
		if (cf.getCodigo() == 0) {
			string nome;
			int cc;

			//usuario entra com o nome do registro
			cout << "Insira o nome do registro:\n? ";
			cin >> setw(30) >> nome;

			cout << " Insira o código contabil:\n? ";
			cin >> cc;

			//usa os valore para popular os valores do objeto
			cf.setNome(nome);
			cf.setCodigo(codigo);
			cf.setCodigoContabil(cc);

			//move o ponteiro posição arquivo para o registro correto no arquivo
			inserir.seekp((codigo - 1) * sizeof(CustosFixos));

			//insira o registro no arquivo
			inserir.write(reinterpret_cast<const char *>(&cf),
					sizeof(CustosFixos));
		} else {
			cerr << "Codigo #" << codigo << "Já contém " << endl;
		}
	} catch (exception &) {
		cout << " Exception handled in function throwException"
				<< "\n Function throwException rethrows exception";
		throw; //rethrow exception for further processing
	}
	return "salvou";

}

//atualizar registro
string CustosControl::atualizarCusto() {

	//fstream update = retornafStream();

	fstream update("centroCusto.dat", ios::in | ios::out | ios::binary);

	if (!update) {
		cerr << "Arquivo não pode ser aberto";
		exit(1);
	}

	//obtain o codigo do registro para atualizar
	int codigo = getCodigo("Enter codigo para atualizar");

	//move o ponteiro para a posicao do arquivo
	update.seekg((codigo - 1) * sizeof(CustosFixos));

	//leia o primeiro registro do arquivo
	CustosFixos cf;
	update.read(reinterpret_cast<char *>(&cf), sizeof(CustosFixos));

	//atualiza o registro
	if (cf.getCodigo() != 0) {
		//exibe o registro
		outputLine(cout, cf);

		//solicita para o usuario
		cout << "\nEnter o novo nome: ";
		string nome; //novo nome
		cin >> nome;

		cout << "\nInseria o codigo contabil";
		int cc;
		cin >> cc;
		//atualiza o registro
		cf.setNome(nome);
		cf.setCodigoContabil(cc);

		outputLine(cout, cf);

		//move o pointeiro para a posicao correta no arquivo
		update.seekp((codigo - 1) * sizeof(CustosFixos));

		//escreva o novo valor sobre o antigo valor no arquivo
		update.write(reinterpret_cast<const char *>(&cf), sizeof(CustosFixos));
	}
	//Exibe error se o registro não existir
	else {
		cerr << "Codigo # " << codigo << " não tem informação." << endl;
	}
	return "atualizou";
}

//remover registro
string CustosControl::deletarCusto() {

	fstream remover("centroCusto.dat", ios::in | ios::out | ios::binary);

	if (!remover) {
		cerr << "Arquivo não pode ser aberto";
		exit(1);
	}

	//obtain o numero do registro para deletar
	int codigo = getCodigo("Enter o codigo para ser removido");

	//move o ponteiro na posicao correta no arquivo
	remover.seekg((codigo - 1) * sizeof(CustosFixos));

	//leia o registro
	CustosFixos cf;
	remover.read((char *) (&cf), sizeof(CustosFixos));

	//remove registro se o registro existir no arquivo
	if (cf.getCodigo() != 0) {
		CustosFixos blankCF; //cria um registro vazio

		//move o ponteiro na posição correta no registro no arquivo
		remover.seekp((codigo - 1) * sizeof(CustosFixos));

		//substitui um registro existente with o registro vazio
		remover.write(reinterpret_cast<const char *>(&blankCF),
				sizeof(CustosFixos));

		cout << "Codigo #" << codigo << "deletado.\n";

	} else
		cerr << "Codigo #" << codigo << "está vazio\n";

	return "removeu";
}
//Return Codigo
int CustosControl::getCodigo(const char * const prompt) {
	int codigo;

	do {
		cout << prompt << ": ";
		cin >> codigo;
	} while (codigo < 1 || codigo > 100);

	return codigo;
}


} /* namespace std */
