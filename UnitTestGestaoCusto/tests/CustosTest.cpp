/*
 * This class must realize test
 */
#include "gtest/gtest.h"

#include "model/Custos.h"
using namespace std;

namespace{
class CustosTest : public ::testing::Test{

protected:
	Custos custos;
};

//Here the first test
TEST_F(CustosTest,custoTest){

	//Here we can test constructor
	//The first fail
	//Create
	ASSERT_TRUE(false);

};
}
