#include "string.hpp"
#include <cassert>
#include <iostream>


int main()
{

    String test = "The fantastic four";
    {  
      char find = 'T';
      assert(test.findchar(find) == 0);
    }
    {
      char find = 'a';
      assert(test.findchar(find) == 5); 
    } 
    
    {
      assert(test.findchar('s') == 9);
    }
    
    {
      char find = 'f';
      assert(test.findchar(find) == 4);
    }
    
    {
      char find = 'y';
      assert(test.findchar(find) == -1);
    }  
    
    std::cout <<"Done testing findchar" << std::endl;
    
    return 0;
}
