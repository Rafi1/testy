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
#define TEST(a)\
if(!(a))\
{\
  std::cout<<"FAIL IN LINE "<<__LINE__<<": "<<#a<<"\n";\
  return 1;\
}
/******************************************************************************/
int main(void){

  TEST(Decimal("0.01357")==(Decimal("0.00123")+Decimal("0.01234")));

  TEST(Decimal("100")==(Decimal("123")-Decimal("23")));

  TEST(Decimal("28.29")==(Decimal("12.3")*Decimal("2.3")));

  TEST(Decimal("41.33333333333333333333")==(Decimal("124")/Decimal("3")).round(20));

  Decimal cumSum("20");

  for(int i=0; i<1001;i++)
    cumSum+= Decimal("0.001");
  TEST(cumSum==Decimal("21.001"));

  for(int i=0; i<500;i++)
    cumSum-= Decimal("0.001");
  TEST(cumSum==Decimal("20.501"));

  TEST(Decimal(1.0/3.0, 5)==Decimal("0.33333"));

  TEST(I2D(234)==Decimal("234"));

  std::cout<<"PASS!\n";
  return 0;
}
/******************************************************************************/
