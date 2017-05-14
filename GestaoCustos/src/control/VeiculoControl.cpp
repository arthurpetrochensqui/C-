/*
 * VeiculoControl.cpp
 *
 *  Created on: 12 de mai de 2017
 *      Author: arthur
 */

#include "VeiculoControl.h"

namespace std {

VeiculoControl::VeiculoControl() {
	// TODO Auto-generated constructor stub
	verificaArquivo();
}

VeiculoControl::~VeiculoControl() {
	// TODO Auto-generated destructor stub
}

void VeiculoControl::verificaArquivo() {
	Arquivo arq;

	if (arq.arquivoExist("veiculo.dat") == false) {

		ofstream out("veiculo.dat", ios::out | ios::binary);

		if (!out) {
			cerr << "Erro ao  criar o arquivo";
			exit(1);
		}

		Veiculo v(0,"","",0);

		//Podemos ter até 5 veiculos
		for (int i = 0; i < 10; ++i) {

			out.write(reinterpret_cast<const char *>(&v), sizeof(Veiculo));
		}
	}

}

//Listar veiculo
bool VeiculoControl::listarVeiculo() {
	bool temVeiculo = false;

	fstream ifs("veiculo.dat", ios::in | ios::out | ios::binary);

	if (!ifs) {
		cerr << "Arquivo veiculo não pode ser aberto";
		exit(1);
	}

	//Criar o arquivo Print para armazenar os arquivos temporarios
	ofstream print("print.txt", ios::out);

	if (!print) {
		cerr << "Arquivo Temporario Print não foi possivel abrir";
		exit(1);
	}

	cout << left << setw(10) << "ID" << setw(10) << "Placa" << setw(20)
						<< "Renavam" << setw(20) << "Quilometragem Atual" << endl;

	print << left << setw(10) << "ID" << setw(10) << "Placa" << setw(20)
					<< "Renavam" << setw(20) << "Quilometragem Atual" << endl;

	ifs.seekg(0); //inicia na posicao zero

	//leia o primeiro registro do veiculo
	Veiculo veic;
	ifs.read(reinterpret_cast<char *>(&veic), sizeof(Veiculo));

	//copia todos os registros do arquivo original para dentro do arquivo print
	while (ifs && !ifs.eof()) {
		if (veic.getVeiculoId() != 0) {
			temVeiculo = true;
			outputLine(print, veic);
		}

		//Leia o proximo registro do arquivo
		ifs.read(reinterpret_cast<char *>(&veic), sizeof(Veiculo));
	}

	return temVeiculo;
}

//Method Inseir Veiculo
bool VeiculoControl::inserirVeiculo() {
	bool inseriu = false;
	try {
		fstream ifs("veiculo.dat", ios::in | ios::out | ios::binary);
		if (!ifs) {
			cerr << "Não foi possivel abrir o arquivo veiculo";
			exit(1);
		}

		int codigo = getCodigo("Insira um codigo: ");

		//move o ponteiro para o correto registro no arquivo
		ifs.seekg((codigo - 1) * sizeof(Veiculo));

		//Leia o registro
		Veiculo veic;
		ifs.read(reinterpret_cast<char *>(&veic), sizeof(Veiculo));

		//cria o objeto se ele não existir
		if (veic.getVeiculoId() == 0) {

			string placa;
			string renavam;
			int km;

			cout << "\nInsira a placa do veiculo: ";
			cin >> placa;
			cout << "\nInsira o renavam do veiculo:";
			cin >> renavam;
			cout << "\nInsira a KM atual do veiculo:";
			cin >> km;

			veic.setVeiculoId(codigo);
			veic.setPlaca(placa);
			veic.setRenavam(renavam);
			veic.setQuilmetragem(km);

			//move o ponteiro na posicao do arquivo
			ifs.seekp((codigo - 1) * sizeof(Veiculo));

			//escreve o registro no arquivo
			ifs.write(reinterpret_cast<const char *>(&veic), sizeof(Veiculo));

			cout<<"Finalizando inserir";

			inseriu = true;
		} else {
			cerr << "Registro já inserido :" << codigo << endl;
		}

	} catch (exception &) {
		cout << "Manipulador de exceção na função capturou uma exceção"
				<< "\n Inserir Veiculo ";
		throw;
	}
	listarVeiculo();

	return inseriu;
}

//alterar veiculo
bool VeiculoControl::alterarVeiculo() {

	bool alterou = false;
	try {
		fstream ifs("veiculo.dat", ios::in | ios::out | ios::binary);

		if (!ifs) {
			cerr << "Erro ao abrir arquivo veiculo.dat";
			exit(1);
		}

		//obtem o codigo do veiculo para atualizar
		int codigo = getCodigo("Insira o codigo veiculo para atualizar: ");

		//move o ponteiro para a posicao do arquivo
		ifs.seekg((codigo - 1) * sizeof(Veiculo));

		//Leia o veiculo
		Veiculo veic;
		ifs.read(reinterpret_cast<char *>(&veic), sizeof(Veiculo));

		if (veic.getVeiculoId() != 0) {

			//exibe o veiculo
			outputHead();
			outputLine(cout, veic);

			string placa;
			string renavam;
			int km;

			cout << "\nInsira a placa :";
			cout << veic.getPlaca();
			cin >> placa;

			cout << "\nInsira o numero do Renavam:";
			cout << veic.getRenavam();
			cin >> renavam;

			cout << "\nInsira a KM atual do Veiculo:";
			cin >> km;

			veic.setPlaca(placa);
			veic.setRenavam(renavam);
			veic.setQuilmetragem(km);

			outputHead();
			outputLine(cout, veic);

			//move o ponteiro para a posicao correta no arquivo
			ifs.seekp((codigo - 1) * sizeof(Veiculo));

			//Atualiza os valores no registro
			ifs.write(reinterpret_cast<const char *>(&veic), sizeof(Veiculo));

			alterou = true;
		} else {
			cerr << " Veiculo #" << codigo << " não pode ser alterado" << endl;
		}

	} catch (exception &) {
		cout
				<< "Manipulador de exceção capturou uma exceção ao alterar veiculo";
		throw;
	}
	return alterou;
}

//remove veiculo
bool VeiculoControl::removerVeiculo() {
	bool removeu = false;

	fstream fs("veiculo.dat", ios::in | ios::out | ios::binary);

	try {
		if (!fs) {
			cerr << "Erro ao abrir arquivo veiculo.dat";
			exit(1);
		}

		//obtaim o codigo do veiculo a ser removido
		int codigo = getCodigo("Insira o codigo veiculo para ser removido");

		//posiciona o ponteiro na posicao correta
		fs.seekg((codigo - 1) * sizeof(Veiculo));

		//Leia veiculo
		Veiculo veic;
		fs.read(reinterpret_cast<char *>(&veic), sizeof(Veiculo));

		//sobreescreve o registro se ele existir
		if (0 != veic.getVeiculoId()) {

			//Cria veiculo vazio
			Veiculo veicVazio;

			//move o ponteiro na posicao correta no registro no arquivo
			fs.seekp((codigo - 1) * sizeof(Veiculo));

			//substitui o registro
			fs.write(reinterpret_cast<char *>(&veicVazio), sizeof(Veiculo));
			removeu=true;

			cout << "Veiculo #" << codigo << "removido\n";
		} else {
			cerr << "Veiculo #" << codigo << " não foi possivel remover"
					<< endl;
		}
	} catch (exception &) {
		cout << "O gerenciado de exceção captura um exceção ao remover veiculo"
				<< endl;
		throw;
	}
	return removeu;
}

//Method outputLine exibe na tela as informações do objeto
void VeiculoControl::outputLine(ostream &output, Veiculo &veic) {

	cout << left << setw(10) << veic.getVeiculoId() << setw(10)
			<< veic.getPlaca() << setw(20) << veic.getRenavam() << setw(20)
			<< veic.getQuilometragem() << endl;

}

//Print cabecalho do registro
void VeiculoControl::outputHead() {
	cout << left << setw(10) << "ID" << setw(10) << "Placa" << setw(20)
			<< "Renavam" << setw(20) << "Quilometragem Atual" << endl;

}

int VeiculoControl::getCodigo(const char * const prompt){

	int codigo;
	do{
		cout<<prompt<<": ";
		cin>>codigo;
	}while(codigo > 1 || codigo <50);
}
} /* namespace std */
