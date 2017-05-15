/*
 * MotoristaControl.cpp
 *
 *  Created on: 14 de mai de 2017
 *      Author: arthur
 */

#include "MotoristaControl.h"

namespace std {

MotoristaControl::MotoristaControl() {
	// TODO Auto-generated constructor stub

}


MotoristaControl::~MotoristaControl() {
	// TODO Auto-generated destructor stub
}

//Verifica se arquivo .dat existe
bool MotoristaControl::verificarArquivo(){
	bool encontrou=false;
	Arquivo arq;
	if(arq.arquivoExist("motorista.dat")==false){
		ofstream out("motorista.dat", ios::out|ios::binary);

		if(!out){
			cerr<<"Erro ao criar o arquivo";
			exit(1);
		}

		Motorista m(0,"",0.0);

		for(int i=0;i<30;++i){
			out.write(reinterpret_cast<const char *>(&m),sizeof(Motorista));
		}


	}
	return encontrou;
}

//Listar all motorista
bool MotoristaControl::listarMotorista(){
	bool hasRecord=false;

	fstream fs("motorista.dat", ios::in|ios::out|ios::binary);
	if(!fs){
		cerr<<"Arquivo veiculo não pode ser aberto";
		exit(1);
	}

	//criar o arquivo Print para armazenar os arquivos temporarios
	ofstream print("print.txt", ios::out);
	if(!print){
		cerr<<"Arquivo Temporario Print não foi possivel abrir:";
		exit(1);
	}

	cout<<left<<setw(10)<<"Codigo"<<setw(30)<<"Nome"<<setw(20)<<"Salario"<<endl;

	print<<left<<setw(10)<<"Codigo"<<setw(30)<<"Nome"<<setw(20)<<"Salario"<<endl;

	fs.seekg(0);

	//Read the first record
	Motorista m;
	fs.read(reinterpret_cast<char *>(&m),sizeof(Motorista));

	while(fs && !fs.eof()){
		if(0 != m.getId()){
			hasRecord=true;
			lineOutPut(print,m);
		}
		fs.read(reinterpret_cast<char *>(&m),sizeof(Motorista));
	}

}

//Inseir motorista
bool MotoristaControl::inserirMotorista(){
	bool inseriu=false;
	try{
		fstream fs("motorista.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo motorista.dat";
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo: ");

		fs.seekg((codigo-1)*sizeof(Motorista));

		Motorista m;
		fs.read(reinterpret_cast<char *>(&m),sizeof(Motorista));

		if(m.getId()==0){
			string nome;
			double salario;

			cout<<"Insira o nome do motorista:";
			cin>>nome;

			cout<<"Insira o salario :";
			cin>>salario;

			m.setId(codigo);
			m.setNome(nome);
			m.setSalario(salario);

			fs.seekp((codigo-1)*sizeof(Motorista));

			fs.write(reinterpret_cast<const char *>(&m),sizeof(Motorista));

			inseriu=true;
		}else{
		cerr<<"Motorista já cadastrado: "<<codigo<<endl;
		}
	}catch(exception &){
		throw;
	}
	return inseriu;
}

//Alterar motorista
bool MotoristaControl::alterarMotorista(){
	bool alterou=false;
	try{
		fstream fs ("motorista.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo motorista";
			exit(1);
		}

		int codigo = getCodigo("Insira o codigo motorista para atualizar: ");

		fs.seekg((codigo-1)*sizeof(Motorista));

		Motorista m;
		fs.read(reinterpret_cast<char *>(&m),sizeof(Motorista));

		if(m.getId() != 0){
			lineOutHead();
			lineOutPut(cout,m);

			string nome;
			double salario;

			cout<<"\Insira o nome do motorista : "<<endl;
			cin>>nome;

			cout<<"\Insira o salario: "<<endl;
			cin>>salario;

			m.setNome(nome);
			m.setSalario(salario);

			lineOutHead();
			lineOutPut(cout,m);

			fs.seekp((codigo-1)*sizeof(Motorista));
			fs.write(reinterpret_cast<char *>(&m),sizeof(Motorista));

			alterou=true;

		}else{
			cerr<<"Motorista #"<<codigo<<"não pode ser alterado"<<endl;
		}
	}catch(exception &){
		throw;
	}
	return alterou;
}

//remover
bool MotoristaControl::removerMotorista(){
	bool removeu=false;
	try{
		fstream fs("motorista.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo motorista";
			exit(1);
		}

		int codigo=getCodigo("Insira o codigo do motorista a ser removido");

		fs.seekg((codigo-1)*sizeof(Motorista));

		Motorista m;
		fs.read(reinterpret_cast<char *>(&m),sizeof(Motorista));

		if(0 != m.getId()){
			Motorista motoristaVazio;

			fs.seekp((codigo-1)*sizeof(Motorista));

			fs.write(reinterpret_cast<char *>(&motoristaVazio),sizeof(Motorista));

			removeu=true;

			cout<<"Motorista # "<<codigo<<" removido\n";
		}else{
			cout<<"Motorista # "<<codigo<<" não foi possivel remover";
		}
	}catch(exception &){
		throw;
	}
	return removeu;
}

void MotoristaControl::lineOutPut(ostream &output, Motorista &mot){

	cout<<left<<setw(10)<<mot.getId()<<setw(30)<<mot.getNome()<<setw(20)<<mot.getSalario()<<endl;

}

void MotoristaControl::lineOutHead(){
	cout<<left<<setw(10)<<"Codigo"<<setw(30)<<"Nome"<<setw(20)<<"Salario"<<endl;

}

int MotoristaControl::getCodigo(const char * const prompt){
	int codigo;
	do{
		cout<<prompt<<":";
		cin>>codigo;
	}while(codigo>1 || codigo<30);
	return codigo;
}
} /* namespace std */
