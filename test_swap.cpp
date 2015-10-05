#include "string.hpp"
#include <cassert>

int main()
{
  {
    String test1 = "It's a miracle";
    String test2 = "He's alive!";
    
    test1.swap(test2);
    
    assert(test1 == "He's alive!");
    assert(test2 == "It's a miracle");
  }
  std::cout <<"Done testing swap" <<std::endl;
  
  return 0;
}
