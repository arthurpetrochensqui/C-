/*
 * MenuTipoConta.h
 *
 *  Created on: 11 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_VIEW_MENUTIPOCONTA_H_
#define SRC_VIEW_MENUTIPOCONTA_H_
#include "../control/TipoContaControl.h"
namespace std {

class MenuTipoConta {
	enum CHOICES {
		LISTAR = 1, CADASTRAR, ATUALIZAR, EXCLUIR, SAIR
	};
public:
	MenuTipoConta();
	void showMenu();
	virtual ~MenuTipoConta();
};

} /* namespace std */

#endif /* SRC_VIEW_MENUTIPOCONTA_H_ */
