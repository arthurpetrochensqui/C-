/*
 * TipoContaControl.cpp
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 *
 * Esta classe e responsável por gerenciar informacoes referente
 * ao TipoConta
 * O construtor deverá chamar o metodo para verificar se o arquivo
 * existe, se não ele deve criar
 */

#include "TipoContaControl.h"

namespace std {

TipoContaControl::TipoContaControl() {
	verificaArquivoExiste();
}

TipoContaControl::~TipoContaControl() {
	// TODO Auto-generated destructor stub
}

//This method check if file exists, case is not exist than create
bool TipoContaControl::verificaArquivoExiste() {

	//This variavel will filled the information of return
	bool retorno = true;

	//The Construct will execute this method

	//Here I will go create a object of type Arquivo
	Arquivo arq;

	//Then I pass the name of file for to see it exist
	if (arq.arquivoExist("tipoConta.dat") == false) {

		//the file not exists
		ofstream fout("tipoConta.dat", ios::out | ios::binary);

		//tenta abrir o arquivo
		if (!fout) {
			cerr << "Nao foi possivel abrir o arquivo" << endl;
			retorno = false;
			exit(1);
		}

		CustosFixos cf(0, "", 0);
		TipoConta tc(0, "", 0.0, "", cf.getCodigo());

		for (int i = 0; i < 10; ++i) {
			cout << "Criando estrutura construtor :" << i << endl;
			fout.write(reinterpret_cast<const char *>(&tc), sizeof(TipoConta));
			//.write(reinterpret_cast<const char*>(&cf),
			//		sizeof(CustosFixos));
		}

	}
	return retorno;
}

bool TipoContaControl::salvarTipoConta() {

	//the value of the return
	bool inseriu = true;
	try {

		//Then I open the file
		fstream ifs("tipoConta.dat", ios::in | ios::out | ios::binary);

		if (!ifs) {
			//There is a error of the open the file
			cerr << "Erro ao abrir tipoConta" << endl;
			exit(1);
		}

		//Return the next codigo of file
		int codigo = getCodigo("Insira o codigo da Conta: ");

		//Move the pointer for position
		ifs.seekg((codigo - 1) * sizeof(TipoConta));

		TipoConta tc;

		//Read the file position
		ifs.read(reinterpret_cast<char *>(&tc), sizeof(TipoConta));

		cout << "Verificando codigo tipoconta:" << tc.getCodigo() << endl;

		//Verified the value of tc.getCodigo();
		if (tc.getCodigo() == 0) {
			//This is new Record
			string contaContabil;
			double valor;
			string data;

			//Define the type of custos Fixos
			CustosFixos cf(1, "Fixos", 1000);

			cout << "Insira o codigo Contabil da conta:\n? ";
			cin >> setw(30) >> contaContabil;

			cout << "Insira o valor da conta: ";
			cin >> valor;

			cout << "Insira a data da conta :";
			cin >> data;

			tc.setCodigo(codigo);
			tc.setContaContabil(contaContabil);
			tc.setValor(valor);
			tc.setCustosFixos(cf.getCodigo());

			//Move the pointer for position register
			ifs.seekp((codigo - 1) * sizeof(TipoConta));

			//Save the register in the file
			ifs.write(reinterpret_cast<const char *>(&tc), sizeof(TipoConta));

		} else {
			cerr << "Codigo #" << codigo << " Já cadastrado " << endl;
			inseriu = false;
		}

	} catch (exception &) {
		inseriu = false;
		cout << "\nErro ao inserir tipoConta no arquivo" << endl;

		throw;
	}
	return inseriu;
}

//Here I list all register in the file and return true
//if there is register
bool TipoContaControl::listarRegistro() {
	bool hasRegister = false;

	//I will go put the register in of the print
	//then I need verified if the file exists
	ofstream outPrint("print.txt", ios::out);

	//verified the file
	if (!outPrint) {
		cerr << "Arquivo não pode ser criado" << endl;
		exit(1);
	}

	//Here I read file in format binary
	fstream readFile("tipoConta.dat", ios::in | ios::out | ios::binary);

	//then I verified if I can open the file
	if (!readFile) {
		cerr << "Arquivo não pode ser aberto" << endl;
		exit(1);
	}

	//Here I save the head of file that I will print
	outPrint << left << setw(3) << "Codigo" << setw(10) << "Conta Contabil"
			<< setw(10) << "valor" << setw(10) << "data" << setw(10)
			<< "Centro Custo" << endl;

	TipoConta tc;
	readFile.read(reinterpret_cast<char *>(&tc), sizeof(TipoConta));

	//copy all register of it file for in it file Print
	while (readFile && !readFile.eof()) {

		if (tc.getCodigo() != 0) {
			outputLine(outPrint, tc);
			hasRegister = true;
		}
		//read the next register
		readFile.read(reinterpret_cast<char *>(&tc), sizeof(TipoConta));
	}
	return hasRegister;
}

//Alterar Tipo Conta
bool TipoContaControl::alterarTipoConta() {

	bool atualizou = false;

	fstream update("tipoConta.dat", ios::in | ios::out | ios::binary);

	if (!update) {
		cerr << "Arquivo TipoConta dat não pode ser aberto";
		exit(1);

	}

	//obtain o codigo do registro para atualizar
	int codigo = getCodigo("Enter o codigo do TipoConta para Atualizar");

	//mode o ponteiro para a posicao do arquivo
	update.seekg((codigo - 1) * sizeof(TipoConta));

	//Leia o primeiro registro do arquivo
	TipoConta tc;

	update.read(reinterpret_cast<char *>(&tc), sizeof(TipoConta));

	//atualiza o registro
	if (tc.getCodigo() != 0) {
		outputLine(cout, tc);

		cout << "\nInsira o codigo contabil da conta: " << tc.getContaContabil()
				<< "\n";
		cout << "?:";
		string contaContabil;
		cin >> contaContabil;

		cout << "\nInsira o valor da conta:\n";
		cout << "?:";
		double valorConta;
		cin >> valorConta;

		cout << "\nInsira o mês de referência:\n";
		cout << "?:";
		string data;
		cin >> data;

		tc.setContaContabil(contaContabil);
		tc.setValor(valorConta);
		tc.setData(data);

		outputLine(cout, tc);

		//move o ponteiro para a posicao correta no arquivo
		update.seekp((codigo - 1) * sizeof(TipoConta));

		//escreva o novo valor para a posicao do registro
		update.write(reinterpret_cast<const char *>(&tc), sizeof(TipoConta));

		atualizou = true;
	}
	return atualizou;
}
//return codigo of register
int TipoContaControl::getCodigo(const char * const prompt) {
	int codigo;

	do {
		cout << prompt << ": ";
		cin >> codigo;
	} while (codigo < 1 || codigo > 100);

	return codigo;
}

//this methdo print information of register
void TipoContaControl::outputLine(ostream &output, TipoConta &tc) {

	cout << left << setw(3) << tc.getCodigo() << setw(10)
			<< tc.getContaContabil() << setw(10) << tc.getValor() << setw(10)
			<< tc.getData() << setw(10)
			<< retornaCustosFixos(tc.getCustosFixos()).getNome() << endl;
}

//Retorna o objeto CustosFixos
CustosFixos TipoContaControl::retornaCustosFixos(int i) {
	CustosFixos cf(1, "Custos Fixos", 1000);
	return cf;

}

bool TipoContaControl::removerTipoConta() {

	bool removeu = false;

	fstream remover("tipoConta.dat", ios::in | ios::out | ios::binary);

	if (!remover) {
		cerr << "Arquivo não pode ser aberto";
		exit(1);
	}

	//obtain o numero do registro para deletar
	int codigo = getCodigo("Insira o codigo do TiConta para ser Removida");

	//move o ponteiro para a primeira posicao
	remover.seekg((codigo - 1) * sizeof(TipoConta));

	//Leia o Arquivo
	TipoConta tc;

	remover.read(reinterpret_cast<char *>(&tc), sizeof(TipoConta));

	if (tc.getCodigo() != 0) {

		TipoConta contaVazia;

		//move o ponteiro para a posicao do arquivo a ser removido
		remover.seekp((codigo - 1) * sizeof(TipoConta));

		//substitui o registro selecionado pelo vazio
		remover.write(reinterpret_cast<const char*>(&contaVazia),
				sizeof(TipoConta));

		cout << " Tipo Conta #" << codigo << "removida.\n";

		removeu = true;
	} else {
		cerr << "Tipo Conta #" << codigo << "Não Pode ser Removida";
	}

	return removeu;
}

}
/* namespace std */
