/*
 * ManutencaoVeiculoControl.cpp
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#include "ManutencaoVeiculoControl.h"

namespace std {

ManutencaoVeiculoControl::ManutencaoVeiculoControl() {
	// TODO Auto-generated constructor stub

}


ManutencaoVeiculoControl::~ManutencaoVeiculoControl() {
	// TODO Auto-generated destructor stub
}

ManutencaoVeiculoControl::ManutencaoVeiculoControl(Veiculo veic){
	veiculo =veic;
}
bool ManutencaoVeiculoControl::verificaArquivoExiste(){
	bool retorno=true;

	Arquivo arq;

	if(arq.arquivoExist("manutencaoVeiculo.dat")==false){

		ofstream fout("manutencaoVeiculo.dat", ios::out|ios::binary);

		if(!fout){
			cerr<<"Não foi possivel abrir o arquivo manutencaoVeiculo"<<endl;
			exit(1);
		}

		ManutencaoVeiculo manVeic(0,0,0.0,0);

		for(int i=0; i<50;++i){

			fout.write(reinterpret_cast<const char *>(&manVeic),sizeof(ManutencaoVeiculo));
		}
	}
	return retorno;
}

void ManutencaoVeiculoControl::listarManutencao(){

	bool hasManutencao=false;

	fstream ifs("manutencaoVeiculo.dat", ios::in | ios::out |ios::binary);
	if(ifs){
		cerr<<"Arquivo manutencao veiculo não pode ser aberto";
		exit(1);
	}

	//criar o arquivo Print  para armazenar os arquivos temporarios
	ofstream print("print.txt", ios::out);
	if(!print){
		cerr<<"Arquivo temporario print não foi possivel abrir";
		exit(1);
	}

	cout<<left<<setw(10)<<"Id"<<setw(10)<<"Data"<<setw(10)
			<<"Valor"<<setw(20)<<"Veiculo"<<endl;

	print<<left<<setw(10)<<"Id"<<setw(10)<<"Data"<<setw(10)
					<<"Valor"<<setw(20)<<"Veiculo"<<endl;

	ifs.seekg(0);//inicia na posicao veiculo
	ManutencaoVeiculo manVeic;
	ifs.read(reinterpret_cast<char *>(&manVeic),sizeof(ManutencaoVeiculo));

	while(ifs && !ifs.eof()){
		if(manVeic.getIdVeiculo()==veiculo.getVeiculoId() && manVeic.getCodigo() !=0){
			hasManutencao=true;
			outputLine(print, manVeic);
		}

		ifs.read(reinterpret_cast<char *>(&manVeic),sizeof(ManutencaoVeiculo));
	}
	//return hasManutencao;
}

void ManutencaoVeiculoControl::inserirManutencao(){
	try{
		fstream fs("manutencaoVeiculo.dat",ios::in |ios::out|ios::binary);
		if(!fs){
			cerr<<"Não foi possivel abrir o arquivo manutencao veículo";
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo: ");

		//Move o ponteiro para o correto registro no arquivo
		fs.seekg((codigo-1)*sizeof(ManutencaoVeiculo));

		ManutencaoVeiculo manVeic;
		fs.read(reinterpret_cast<char *>(&manVeic),sizeof(ManutencaoVeiculo));

		//cria o objeto se ele não existir
		if(manVeic.getCodigo()==0){
			long data;
			double valor;
			cout<<"\Insira a data da manutencao: ";
			cin>>data;

			cout<<"\Insira o valor da manutencao:";
			cin>>valor;

			manVeic.setCodigo(codigo);
			manVeic.setData(data);
			manVeic.setValor(valor);
			manVeic.setIdVeiculo(veiculo.getVeiculoId());

			fs.seekp((codigo-1)*sizeof(ManutencaoVeiculo));

			fs.write(reinterpret_cast<const char *>(&manVeic),sizeof(ManutencaoVeiculo));

		}else{
			cerr<<"Registro já inserido :"<<codigo<<endl;
		}

	}catch(exception &){
		throw;
	}
}

void ManutencaoVeiculoControl::alterarManutencao(){
	try{
		fstream fs("manutencaoVeiculo.dat", ios::in |ios::out |ios::binary);
		if(!fs){
			cerr<<"Erro ao abrir manutencao veiculo.dat";
			exit(1);
		}

		//obtem o codigo manutencao veiculo a atualizar
		int codigo = getCodigo("Insira o codigo manutencao que você deseja alterar\n");
		//move o ponteiro para a posicao do arquivo
		fs.seekg((codigo-1)*sizeof(ManutencaoVeiculo));

		ManutencaoVeiculo manVeic;
		fs.read(reinterpret_cast<char *>(&manVeic),sizeof(ManutencaoVeiculo));

		if(manVeic.getCodigo() != 0){
			outputHead();
			outputLine(cout,manVeic);

			double valor;
			long data;

			cout<<"\nInsira a data";
			cin >>data;

			cout<<"\nInsira o valor";
			cin>>valor;

			manVeic.setData(data);
			manVeic.setValor(valor);

			fs.seekp((codigo-1)*sizeof(ManutencaoVeiculo));

			fs.write(reinterpret_cast<const char *>(&manVeic),sizeof(ManutencaoVeiculo));

		}else{
			cerr<<" Veiculo #"<<codigo<<"Não pode ser alterado"<<endl;
		}
	}catch(exception &){
		cout<<"Manipulador de exceção capturou uma exceção ao alterar veiculo";
		throw;
	}
}
void ManutencaoVeiculoControl::removerManutencao(){
	fstream fs("manutencaoVeiculo.dat", ios::in|ios::out|ios::binary);
	try{
		if(!fs){
			cerr<<"Erro ao abri arquivo manutencaoVeiculo";
			exit(1);
		}

		int codigo = getCodigo("Insira o codigo veiculo para ser removido");

		//posiciona o ponteiro na posicao correta
		fs.seekg((codigo-1)*sizeof(ManutencaoVeiculo));

		ManutencaoVeiculo manVeic;
		fs.read(reinterpret_cast<char *>(&manVeic),sizeof(ManutencaoVeiculo));

		if(0 != manVeic.getCodigo()){

			ManutencaoVeiculo manVeicVazio;

			//move o ponteiro para posicao correta
			fs.seekp((codigo-1)*sizeof(ManutencaoVeiculo));

			//substitui o registro
			fs.write(reinterpret_cast<char *>(&manVeicVazio),sizeof(ManutencaoVeiculo));

		}else{
			cerr<<"Manutencao Veiculo $"<<codigo<<"removida\n";
		}
	}catch(exception &){
		cout<<"O gerenciado de exceção capturou uma exceção ao remover manutenção veiculo";
		throw;
	}
}

void ManutencaoVeiculoControl::outputLine(ostream &output,ManutencaoVeiculo &manVeic){

	cout<<left<<setw(10)<<manVeic.getCodigo()<<setw(10)<<manVeic.getData()<<setw(10)
				<<manVeic.getValor()<<setw(20)<<veiculo.getPlaca()<<endl;

}

void ManutencaoVeiculoControl::outputHead(){
	cout<<left<<setw(10)<<"Codigo"<<setw(10)<<"Data"<<setw(10)
					<<"Valor"<<setw(20)<<"Placa"<<endl;
}
int ManutencaoVeiculoControl::getCodigo(const char * const prompt){

	int codigo;
	do{
		cout<<prompt<<"";
		cin>>codigo;
	}while(codigo < 1 || codigo>50);

	return codigo;
}

//Get Set
Veiculo ManutencaoVeiculoControl::getVeiculo(){
	return veiculo;
}

void ManutencaoVeiculoControl::setVeiculo(Veiculo v){
	veiculo=v;
}
} /* namespace std */
