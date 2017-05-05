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
	Custos(int, string);

	//Encapsulamento codigo
	void setCodigo(int);
	int getCodigo();

	//Encapsulamento nome
	void setNome(string);
	string getNome();

	//Implement method returnTotalAccount
	virtual double returnTotal() const=0;

	template<typename T> void listarCustos(const list<T>&listRef);

	virtual ~Custos();

protected:
	int codigo;
	string nome;
};

} /* namespace std */

#endif /* SRC_MODEL_CUSTOS_H_ */
