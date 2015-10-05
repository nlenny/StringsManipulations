#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
  
  {
    String test = "God is love";
    {
      String find = "leo";
      assert(test.findstr(find) == 0);
    }
    
        {
      String find = "is";
      assert(test.findstr(find) == 0);
    }
    
    {
      String find = "ove";
      assert(test.findstr(find) == 0);
    }
    {
      String find = "God";
      assert(test.findstr("God") == 0);
    }
  }
   
    std::cout << "Done testing findstring" << std::endl;
    
    return 0;
}

