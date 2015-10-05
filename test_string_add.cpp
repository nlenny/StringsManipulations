#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
   
  {

    String test;
    String test2;
    String test3;

    test3 = test + test2;

    assert(test3 == "");

  }

  {

    String test[3];

    test[0] = "Ngwa";
    
    test[1] = " is Leonard";
    
    test[2] = test[0] + test[1];
    
    assert(test[0] == "Ngwa");
    
    assert(test[1] == " is Leonard");
    
    assert(test[2] == "Ngwa is Leonard");
    
    assert(test[2].length() == 15);
  }
  std::cout <<"Done testing string_add.cpp"<<std::endl;


  return 0;
}
