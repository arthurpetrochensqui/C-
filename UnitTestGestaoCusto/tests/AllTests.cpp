/*
 * AllTests.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: arthur
 */
#include "gtest/gtest.h"

#include "VeiculoTest.cpp"

int main(int argc,char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

