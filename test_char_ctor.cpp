#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
  {
    String test('z');
    assert(test == "z");
    assert(test.length() == 1);
    assert(test.capacity() == DEFAULT_STRING_CAPACITY);
    assert(test[0] == 'z');
      
  }
  {
    String test("Ngwa");
    assert(test == "Ngwa");
    assert(test.length() == 4);
    assert(test.capacity() == DEFAULT_STRING_CAPACITY);

    assert(test[2] == 'w');
    assert(test[1] != test[2]);
  }
  std::cout <<"Done testing test_char_ctor.cpp" << std::endl;

  return 0;
}
