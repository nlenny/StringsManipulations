#include "string.hpp"
#include <cassert>
#include <iostream>


int main()
{
  {
    String p = "42";

    int x = p.to_i();

    assert(p == "42");
    assert(x == 42);
}
  std::cout << "Done testing to_i" << std::endl;

  return 0;
}
