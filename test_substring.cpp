#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
  {
    String test[8];
 
   test[0] = "0123456789";
  
    test[3] = test[0].substr(0, 6);
    test[4] = test[0].substr(3, 9);
    test[5] = test[0].substr(4, 7);
    test[6] = test[0].substr(0, 0);
    test[7] = test[0].substr(7, 9);
 
    assert(test[0] == "0123456789");
    assert(test[0].length() == 10);

    assert(test[3] == "012345");
    assert(test[3].length() == 6);

    assert(test[4] == "345678");
    assert(test[4].length() == 6);

    assert(test[5] == "456");
    assert(test[5].length() == 3);

    assert(test[6] == "");
    assert(test[6].length() == 0);

    assert(test[7] == "78");
    assert(test[7].length() == 2);
  }

  std::cout <<"Done testing substring" << std::endl;


  return 0;
}
