#include "string.hpp"
#include <cassert>

int main()
{
  {
    String x   = 'z';

    x.reallocate(20);
    assert(x == "z");
    assert(x.length() == 1);
    assert(x.capacity() == 20);
}
  
  std::cout <<"Done testing reallocate" << std::endl;
  
  return 0;
}
