/*
 * VeiculoTest.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: arthur
 */
#include "gtest/gtest.h"

//#include "gtest/gtest.h";
#include "Veiculo.h"
#include <string>
using namespace std;

namespace {
class VeiculoTest: public ::testing::Test {

protected:
	Veiculo veiculo; //(5,"AB");
	//(5,"AOL5459"); //=new Veiculo(5,"AOL549");

	//bool valor=true;

};
TEST_F(VeiculoTest,Veiculo) {
	//veiculo(5, "AOL5459");
	veiculo.setVeiculoId(5);
	veiculo.setPlaca("AOL5459");
	//ASSERT_TRUE(veiculo.lerVeiculo());
	ASSERT_EQ(veiculo.getVeiculoId(), 5);
	ASSERT_EQ("AOL5459",veiculo.getPlaca());

}

}

