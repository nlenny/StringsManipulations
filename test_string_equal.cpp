#include"string.hpp"
#include<cassert>
#include<iostream>

int main() 
{
  String rhs("abc"),lhs("fff"), ans;
  assert(rhs=="abc");
  assert(lhs=="fff");
  lhs=rhs;
  assert(rhs=="abc");
  assert(lhs=="abc");
  ans=lhs+rhs;
  assert(lhs=="abc");
  assert(rhs=="abc");
  assert(ans=="abcabc");

  std::cout <<"Done testing assigment and add operator" << std::endl;

  return 0;
}
