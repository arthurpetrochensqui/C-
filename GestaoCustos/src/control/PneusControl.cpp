/*
 * PneusControl.cpp
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#include "PneusControl.h"

namespace std {

PneusControl::PneusControl() {
	// TODO Auto-generated constructor stub

}

PneusControl::PneusControl(Veiculo v){
	verificaArquivo();
}
PneusControl::~PneusControl() {
	// TODO Auto-generated destructor stub
}

//Verificar Arquivo existe
bool PneusControl::verificaArquivo(){
	Arquivo arq;

	bool ret=false;
	if(arq.arquivoExist("pneus.dat")==false){
		ofstream out("pneus.dat",ios::out|ios::binary);

		if(!out){
			cerr<<"Erro ao criar o arquivo pneus";
			exit(1);
		}
		Pneus p(0,0,0,0,0.0);

		for(int i=0; i<100; ++i){
			out.write(reinterpret_cast<const char *>(&p), sizeof(Pneus));
		}
		ret=true;
	}
	return ret;
}


//listar Penus
bool PneusControl::listarPneus(){

	bool hasRegister=false;

	try{
		fstream fs("pneus.dat",ios::in |ios::out | ios::binary);

		if(!fs){
			cerr <<"Arquivo Pneus não pode ser aberto";
			exit(1);
		}

		ofstream print ("print.txt", ios::out);
		if(!print){
			cerr<<"Erro ao criar arquivo temporario pneus";
			exit(1);
		}

		cout<<left<<setw(10)<<"Codigo"<<setw(10)<<"Quilometragem Atual"
				<<setw(10)<<"Eixo" << setw(10)<<"Veiculo"<<setw(10)<<"valor"<<"vida Util"
				<< endl;

		print<<left<<setw(10)<<"Codigo"<<setw(10)<<"Quilometragem Atual"<<setw(10)
						<<"Eixo"<<setw(10)<<"Veiculo"<<setw(10)<<"valor"<<"vida Util"
						<<endl;

		fs.seekg(0);

		Pneus p;
		fs.read(reinterpret_cast<char *>(&p),sizeof(Pneus));

		//copia todos os registro do arquivo original
		while(fs && !fs.eof()){
			if(p.getIdVeiculo()== veiculo.getVeiculoId()&& p.getId()!=0){

				hasRegister=true;
				outputLine(print,p);

			}
			fs.read(reinterpret_cast<char *>(&p),sizeof(Pneus));
		}

	}catch(exception &){
		throw;
	}

	return hasRegister;
}

bool PneusControl::inserirPneu(){
	bool inseriu=false;
	try{
		fstream fs("pneus.dat",ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Não foi possivel abrir o arquivo pneu";
			exit(1);

		}

		int codigo = getCodigo("Insira um codigo");

		//move o ponteiro para a posicao correta
		fs.seekg((codigo-1)*sizeof(Pneus));

		Pneus pneus;
		fs.read(reinterpret_cast<char *>(&pneus),sizeof(Pneus));

		//cria o objeto
		if(pneus.getId()==0){

			int quilometragem;
			int eixo;
			double val;
			int vidaUtil;

			cout<<"\nInsira a quilometragem do Pneu: ";
			cin>>quilometragem;
			cout<<"\nInsira o eixo do veiculo:" ;
			cin>>eixo;
			cout<<"\nInsira a vida util do pneus: ";
			cin>>vidaUtil;
			cout<<"\nInsira o valor do Pneus: ";
			cin>>val;

			pneus.setId(codigo);
			pneus.setEixo(eixo);
			pneus.setQuilometragem(quilometragem);
			pneus.setValor(val);
			pneus.setVidaUtil(vidaUtil);
			pneus.setIdVeiculo(veiculo.getVeiculoId());

			fs.seekp((codigo-1)*sizeof(Pneus));

			fs.write(reinterpret_cast<const char *>(&pneus),sizeof(Pneus));

			inseriu=true;


		}else{
			cerr<<"Registro já inserido :"<<codigo<<endl;
		}

	}catch(exception &){
		throw;
	}
	return inseriu;

}

bool PneusControl::alterarPneu(){
	bool alterou=false;
	try{
		fstream fs("pneus.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir pneus dat";
			exit(1);
		}

		int codigo = getCodigo("Insira o codigo veiculo para atualizar:");

		//move o codigo do veiculo para atualizar
		fs.seekg((codigo-1)*sizeof(Pneus));

		Pneus p;
		fs.read(reinterpret_cast<char *>(&p),sizeof(Pneus));

		if(p.getId()!=0){
			outputHead();
			outputLine(cout,p);

			int quilometragem;
			int eixo;
			double valor;
			int vidaUtil;

			cout<<"\Insira a quilometragem :"<<endl;
			cin>>quilometragem;

			cout<<"\Insira eixo"<<endl;
			cin>>eixo;

			cout<<"\Insira o valor"<<endl;
			cin>>valor;

			cout<<"\nInsira a vida util"<<endl;
			cin>>vidaUtil;

			p.setQuilometragem(quilometragem);
			p.setEixo(eixo);
			p.setValor(valor);
			p.setVidaUtil(vidaUtil);

			outputHead();
			outputLine(cout,p);

			fs.seekp((codigo-1)*sizeof(Pneus));

			fs.write(reinterpret_cast<char *>(&p),sizeof(Pneus));

			alterou=true;
		}else{
			cerr<<"Veiculo #"<< codigo <<" não pode ser alterado"<<endl;
		}

	}catch(exception &){
		throw;
	}
	return alterou;
}


bool PneusControl::removerPneu(){
	bool removeu;
	try{
		fstream  fs("pneus.dat", ios::in|ios::out|ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir arquivo pneus.dat";
			exit(1);
		}

		int codigo = getCodigo("Insira o codigo pneus para ser removido");

		fs.seekg((codigo-1)*sizeof(Pneus));

		Pneus p;
		fs.read(reinterpret_cast<char *>(&p),sizeof(Pneus));

		if(0 != p.getId()){
			Pneus pVazio;

			fs.seekp((codigo -1)* sizeof(Pneus));

			fs.write(reinterpret_cast<char *>(&pVazio),sizeof(Pneus));
			removeu=true;
			cout<<"Pneu #"<<codigo <<" removido\n";
		}else{
			cout<<"Pneu #"<< codigo <<" não foi possivel remover ";
		}
	}catch(exception &){
		throw;
	}
	return removeu;
}

void PneusControl::outputHead(){
	cout<<left<<setw(10)<<"Codigo"<<setw(10)<<"Quilometragem Atual"
					<<setw(10)<<"Eixo" << setw(10)<<"Veiculo"<<setw(10)<<"valor"<<"vida Util"
					<< endl;
}

void PneusControl::outputLine(ostream &output,Pneus &pneus){

	cout<<left<<setw(10)<<pneus.getId()<<setw(10)<<pneus.getQuilometragem()
					<<setw(10)<<pneus.getEixo() << setw(10)<<veiculo.getPlaca()
					<<setw(10)<<pneus.getValor()<<pneus.getVidaUtil()
					<< endl;
}

int PneusControl::getCodigo(const char * const prompt){

	int codigo;
	do{
		cout<<prompt<<":";
		cin>>codigo;
	}while(codigo>1 || codigo<100);
	return codigo;
}
} /* namespace std */
