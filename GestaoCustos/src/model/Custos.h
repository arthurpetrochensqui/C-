/*
 * Custos.h
 *
 *  Created on: 4 de mai de 2017
 *      Author: arthur
 */

#ifndef SRC_MODEL_CUSTOS_H_
#define SRC_MODEL_CUSTOS_H_
#include <string>
#include <list>

namespace std {

class Custos {
public:
	Custos();
	Custos(int, string,int);

	//Encapsulamento codigo
	void setCodigo(int);
	int getCodigo()const;

	//Encapsulamento nome
	void setNome(string);
	string getNome() const;

	void setCodigoContabil(int);
	int getCodigoContabil() const;

	//Implement method returnTotalAccount
	virtual double returnTotal() const=0;

	template<typename T> void listarCustos(const list<T>&listRef);

	virtual ~Custos();

protected:
	int codigo;
	int codigoContabil;
	char nome[30];
};

} /* namespace std */

#endif /* SRC_MODEL_CUSTOS_H_ */
