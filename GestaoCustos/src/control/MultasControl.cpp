/*
 * MultasControl.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "MultasControl.h"

namespace std {

MultasControl::MultasControl() {
	// TODO Auto-generated constructor stub

}


MultasControl::~MultasControl() {
	// TODO Auto-generated destructor stub
}

bool MultasControl::verificaArquivo(){
	bool achou=false;
	Arquivo arq;

	if(arq.arquivoExist("multas.dat")==false){
		ofstream out("multas.dat",ios::out|ios::binary);
		if(!out){
			cerr<<"Erro ao criar arquivo multas"<<endl;
			exit(1);
		}

		Multas m(0,0,0,0.0,0);

		for(int i=0;i<50; ++i){
			out.write(reinterpret_cast<char *>(&m),sizeof(Multas));
		}
		achou=true;
	}

	return achou;
}

bool MultasControl::listarMulta(){
	bool hasRegister=false;
	try{
		fstream fs("multas.dat",ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivos multa"<<endl;
			exit(1);
		}

		ofstream print("printer.txt", ios::out);
		if(!print){
			cerr<<"Erro ao criar arquivo temporario print"<<endl;
			exit(1);
		}

		cout<<left<<setw(10)<<"ID"<<setw(10)<<"Vencimento"<<setw(10)
				<<"Valor"<<setw(10)<<"Centro Custos"<<endl;

		print<<left<<setw(10)<<"ID"<<setw(10)<<"Vencimento"<<setw(10)
						<<"Valor"<<setw(10)<<"Centro Custos"<<endl;

		fs.seekg(0);

		Multas m;
		fs.read(reinterpret_cast<char *>(&m),sizeof(Multas));

		while(fs && !fs.eof()){
			if(m.getCodigo()!=0){
				hasRegister=true;
				outputLine(print,m);
			}
			fs.read(reinterpret_cast<char *>(&m),sizeof(Multas));
		}


	}catch(exception &){
		throw;
	}
	return hasRegister;
}

//Adicionar multa
bool MultasControl::adicionarMulta(){
	bool inseriu=false;
	try{
		fstream fs("multas.dat",ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo multas.dat"<<endl;
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo: ");

		fs.seekg((codigo-1)*sizeof(Multas));

		Multas m;

		CustosVariaveis cv(1,"Custos Variaveis ",1000);

		fs.read(reinterpret_cast<char *>(&m),sizeof(Multas));

		if(0==m.getCodigo()){
			long data;
			long vencimento;
			double valor;

			cout<<"\nInsira a data: ";
			cin>>data;

			cout<<"\nInsira o vencimento:";
			cin>>vencimento;

			cout<<"\Insira o valor:";
			cin>>valor;

			m.setCodigo(codigo);
			m.setData(data);
			m.setVencimento(vencimento);
			m.setValor(valor);
			m.setIdCentroCusto(cv.getCodigo());

			fs.seekp((codigo-1)*sizeof(Multas));
			fs.write(reinterpret_cast<char *>(&m),sizeof(Multas));

			inseriu=true;

		}else{
		cerr<<"Registro já inserido :"<<codigo<<endl;
		}

	}catch(exception &){
		throw;
	}
	return inseriu;
}

bool MultasControl::alterarMulta(){
	bool alterou=false;
	try{
		fstream fs("multas.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo multas.dat"<<endl;
			exit(1);
		}

		int codigo = getCodigo("Insira o registro a atualizar:");
		fs.seekg((codigo-1)*sizeof(Multas));

		Multas m;

		fs.read(reinterpret_cast<char *>(&m),sizeof(Multas));

		if(0!=m.getCodigo()){
			outputLine();
			outputLine(cout,m);

			long data;
			long vencimento;
			double valor;

			cout<<"\Insira a data :";
			cin>>data;

			cout<<"Insira o vencimento :";
			cin>>vencimento;

			cout<<"\nInsira o valor :";
			cin>>valor;

			m.setData(data);
			m.setVencimento(vencimento);
			m.setValor(valor);

			fs.seekp((codigo-1)*sizeof(Multas));
			fs.write(reinterpret_cast<char *>(&m),sizeof(Multas));
			alterou=true;
		}else{
			cerr<<"Multas #"<<codigo<<" não pode ser alterada"<<endl;
		}
	}catch(exception &){
		throw;
	}
	return alterou;
}

bool MultasControl::removerMulta(){
	bool removeu=false;
	try{
		fstream fs("multas.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo multas.dat"<<endl;
			exit(1);
		}

		int codigo = getCodigo("\nInsira o codigo multa a ser removido");

		fs.seekg((codigo-1)*sizeof(Multas));

		Multas m;
		fs.read(reinterpret_cast<char *>(&m),sizeof(Multas));

		if(0!=m.getCodigo()){
			Multas mBlank;

			fs.seekp((codigo-1)*sizeof(Multas));
			fs.write(reinterpret_cast<char *>(&mBlank),sizeof(Multas));
			cout<<"Multa "<<codigo<<" removida com sucesso"<<endl;
			removeu=true;

		}else {
			cout<<"Multa #"<<codigo<<" não foi possivel remover"<<endl;
		}
	}catch(exception &){
		throw;
	}
	return removeu;
}

void MultasControl::outputLine(){

	cout<<left<<setw(10)<<"ID"<<setw(10)<<"Vencimento"<<setw(10)
					<<"Valor"<<setw(10)<<"Centro Custos"<<endl;

}

void MultasControl::outputLine(ostream &output,Multas &m){

	CustosVariaveis cv(1,"Custos variaveis ",1002);
	cout<<left<<setw(10)<<m.getCodigo()<<setw(10)<<m.getVencimento()<<setw(10)
					<<m.getValor()<<setw(10)<<cv.getNome()<<endl;
}

int MultasControl::getCodigo(const char * const prompt){
	int codigo;
	do{
		cout<<prompt<<": ";
		cin>>codigo;

	}while(codigo>1 || codigo< 100);
	return codigo;
}
} /* namespace std */
