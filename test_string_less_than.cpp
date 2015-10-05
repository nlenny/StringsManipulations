#include "string.hpp"
#include <cassert>
#include <iostream>


int main()
{
  {
    String str1, str2;
    assert(str1 <= str2);
  }

  {
    String str1 = "b", str2 = "m";
    assert(str1 < str2);
    assert(str1 <= str2);
  }

  {
    String str1 = "bm", str2 = "mm";
    assert(str1 < str2);
    assert(str1 <= str2);
  }

  {
    String str1 = "bm", str2 = "m";
    assert(str1 < str2);
    assert(str1 <= str2);
  }

  std::cout <<"Done testing string less than operator" << std::endl;

  return 0;
}
