#include "string.hpp"
#include <cassert>

int main()
{
  {
    String test;
    
    assert(test.length() == 0);
    
  }
  
  {
    String test1('z');
    
    assert(test1.length() == 1);
  }
  
  {
    String test2("z");
    
    assert(test2.length() == 1);
  }
  
  {
    String test3("It's Christmas!");
    
    assert(test3.length() == 15);
  }
  
  std::cout <<"Done testing the string length" << std::endl;
  
  return 0;
}
