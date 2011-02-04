#include <iostream>
/******************************************************************************/
#include "Decimal"
/******************************************************************************/
#define TEST_TRUE(a)\
if(!(a))\
{\
  std::cout<<"FAIL IN LINE "<<__LINE__<<": "<<#a<<" IS FALSE!\n";\
  return 1;\
}
#define TEST_FALSE(a)\
if(a)\
{\
  std::cout<<"FAIL IN LINE "<<__LINE__<<": "<<#a<<" IS TRUE!\n";\
  return 1;\
}
/******************************************************************************/
int main(void){
  Decimal myXX("12.0001");
  Decimal myXY("12.0001");
  Decimal myYX("14.234");
  Decimal myYY("14.234");
  Decimal myZ;
/*******************************/
  TEST_TRUE(myZ.is_zero());
  TEST_FALSE(myXY.is_zero());
  TEST_FALSE(Decimal("0.000000000001").is_zero());
/*******************************/
  TEST_TRUE(Decimal("1223423423423423423423")==Decimal("1223423423423423423423"));
  TEST_FALSE(Decimal("12")==Decimal("13"));
  TEST_FALSE(Decimal("120000000000000")==Decimal("-23433"));
/*******************************/
  TEST_FALSE(Decimal("12")!=Decimal("12"));
  TEST_FALSE(Decimal("12.0005")!=Decimal("12.0005"));
  TEST_TRUE(Decimal("12.000001")!=Decimal("12"));
  TEST_FALSE(Decimal("12")!=Decimal("12.00000000000"));
/*******************************/
  TEST_FALSE(Decimal("14")<Decimal("13"));
  TEST_TRUE(Decimal("13")<Decimal("15"));
  TEST_FALSE(Decimal("14")<Decimal("14"));
/*******************************/
  TEST_FALSE(Decimal("12")>Decimal("14"));
  TEST_TRUE(Decimal("15")>Decimal("14"));
  TEST_FALSE(Decimal("12")>Decimal("12"));
/*******************************/
  TEST_FALSE(Decimal("12")>=Decimal("14"));
  TEST_TRUE(Decimal("15")>=Decimal("14"));
  TEST_TRUE(Decimal("12")>=Decimal("12"));
/*******************************/
  TEST_FALSE(Decimal("15")<=Decimal("14"));
  TEST_TRUE(Decimal("15")<=Decimal("16"));
  TEST_TRUE(Decimal("15")<=Decimal("15"));
/*******************************/
  std::cout<<"PASS!\n";
  return 0;
}
/******************************************************************************/
