#include "string.hpp"
#include <cassert>
#include <iostream>


int main()
{
  {
    string z;
    z.getline(istream& in);
    assert(z == "a");
}

  std::cout << "Done testing getline" << std::endl;

  return 0;
}
