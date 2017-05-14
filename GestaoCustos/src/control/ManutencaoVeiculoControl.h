/*
 * ManutencaoVeiculoControl.h
 *
 *  Created on: 13 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_CONTROL_MANUTENCAOVEICULOCONTROL_H_
#define SRC_CONTROL_MANUTENCAOVEICULOCONTROL_H_

#include "../model/ManutencaoVeiculo.h"
#include "../model/Veiculo.h"
#include "../service/Arquivo.h"

namespace std {

class ManutencaoVeiculoControl {
public:
	ManutencaoVeiculoControl();

	ManutencaoVeiculoControl(Veiculo);

	bool verificaArquivoExiste();

	void listarManutencao();
	void inserirManutencao();
	void alterarManutencao();
	void removerManutencao();

	void outputHead();
	void outputLine(ostream&,ManutencaoVeiculo&);

	Veiculo getVeiculo();
	void setVeiculo(Veiculo);

	int getCodigo(const char * );


	virtual ~ManutencaoVeiculoControl();

private:
	Veiculo veiculo;

};

} /* namespace std */

#endif /* SRC_CONTROL_MANUTENCAOVEICULOCONTROL_H_ */
