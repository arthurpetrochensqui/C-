/*
 * CustosVariaveisControl.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "CustosVariaveisControl.h"

namespace std {

CustosVariaveisControl::CustosVariaveisControl() {
	// TODO Auto-generated constructor stub

}

CustosVariaveisControl::~CustosVariaveisControl() {
	// TODO Auto-generated destructor stub
}

//bool verifica arquivo
bool CustosVariaveisControl::verificarArquivo(){
	bool achou=true;
	Arquivo arq;
	if(arq.arquivoExist("custosVariaveis.dat")==false){
		ofstream out("custosVariaveis.dat",ios::out|ios::binary);
		if(!out){
			cerr<<"Nao foi possivel abrir o arquivo custosvariaveis";
			exit(1);
		}

		CustosVariaveis cv(0,"",0);
		for(int i=0; i<5; ++i){
			out.write(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

		}
		achou=true;
	}
	return achou;
}

//Listar Custos Variaveis
bool CustosVariaveisControl::listarCustosVariaveis(){
	bool hasRecord=false;
	try{
		fstream fs("custosVariaveis.dat",ios::in|ios::out|ios::binary);

		if(!fs){
			cerr<<"Erro ao abrir arquivo custosVariaveis.dat";
			exit(1);
		}

		ofstream print("printer.txt",ios::out);
		if(!print){
			cerr<<"Erro ao abrir arquivo temporario print"<<endl;
			exit(1);
		}
		cout<<left<<setw(10)<<"Codigo"<<setw(10)<<"Nome"<<setw(10)<<"Codigo Contabil"<<endl;

		print<<left<<setw(10)<<"Codigo"<<setw(10)<<"Nome"<<setw(10)<<"Codigo Contabil"<<endl;

		fs.seekg(0);

		CustosVariaveis cv;
		fs.read(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

		while(fs && !fs.eof()){
			if(cv.getCodigo()!=0){
				hasRecord=true;
				outputLine(print,cv);
			}
			fs.read(reinterpret_cast<char * >(&cv),sizeof(CustosVariaveis));
		}
	}catch(exception &){
		throw;
	}
	return hasRecord;
}

//Insert Register
bool CustosVariaveisControl::inserirCustosVariaveis(){
	bool inseriu=false;
	try{
		fstream fs("custosVariaveis.dat",ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Nao foi possivel abrir o arquivo custosVariaveis";
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo");
		fs.seekg((codigo-1)*sizeof(CustosVariaveis));

		CustosVariaveis cv;
		fs.read(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

		if(0 != cv.getCodigo()){
			string nome;
			int codigoContabil;

			cout<<"\nInsira o nome: ";
			cin>>nome;

			cout<<"\nInsira o centro custo";
			cin>>codigoContabil;

			cv.setCodigo(codigo);
			cv.setNome(nome);
			cv.setCodigoContabil(codigoContabil);

			fs.seekp((codigo-1)*sizeof(CustosVariaveis));
			fs.write(reinterpret_cast<const char *>(&cv),sizeof(CustosVariaveis));

			inseriu=true;
		}else{
			cerr<<"Registro já inserido: "<<codigo<<endl;
		}

	}catch(exception &){
		throw;
	}

	return inseriu;
}

bool CustosVariaveisControl::alterarCustosVariaveis(){
	bool alterou=true;
	try{
		fstream fs("custosVariaveis.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir custosvariaveis.dat";
			exit(1);
		}

		int codigo = getCodigo("Insira o codigo para alterar: ");

		CustosVariaveis cv;
		fs.read(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

		if(0 != cv.getCodigo()){
			output();
			outputLine(cout,cv);

			string nome;
			int codigoContabil;

			cout<<"\Insira o nome";
			cin>>nome;

			cout<<"\Insira o codigo contabil";
			cin>>codigoContabil;

			cv.setNome(nome);
			cv.setCodigoContabil(codigoContabil);

			output();
			outputLine(cout,cv);

			fs.seekp((codigo-1)*sizeof(CustosVariaveis));
			fs.write(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

			alterou=true;
		}else{
			cerr<<"Custos Variaveis #"<<codigo<<" não pode ser alterado";
		}
	}catch(exception &){

		throw;
	}

	return alterou;
}

bool CustosVariaveisControl::removerCustosVariaveis(){
	bool removeu=false;

	try{
		fstream fs("custosVariaveis", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir custosVariaveis.dat";
			exit(1);
		}

		int codigo =getCodigo("insira o codigo a ser removido");

		fs.seekg((codigo-1)*sizeof(CustosVariaveis));
		CustosVariaveis cv;
		fs.read(reinterpret_cast<char *>(&cv),sizeof(CustosVariaveis));

		if(0!=cv.getCodigo()){
			CustosVariaveis cvBlank;

			fs.seekp((codigo-1)*sizeof(CustosVariaveis));

			fs.write(reinterpret_cast<char *>(&cvBlank),sizeof(CustosVariaveis));
			removeu=true;
		}else{
			cout<<"Custos Variaveis #"<<codigo<<" não foi possivel remover"<<endl;
		}


	}catch(exception &){
		throw;
	}
	return removeu;
}

void CustosVariaveisControl::outputLine(ostream &output,CustosVariaveis &cv){
	cout<<left<<setw(10)<<cv.getCodigo()<<setw(10)<<cv.getNome()<<setw(10)<<cv.getCodigoContabil()<<endl;

}

void CustosVariaveisControl::output(){
	cout<<left<<setw(10)<<"Codigo"<<setw(10)<<"Nome"<<setw(10)<<"Codigo Contabil"<<endl;
}
int CustosVariaveisControl::getCodigo(const char * const prompt){
	int codigo;

	do{
		cout<<prompt<<": ";
		cin>>codigo;
	}while(codigo>1 ||codigo<5);
	return codigo;
}
} /* namespace std */
