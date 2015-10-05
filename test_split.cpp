#include "string.hpp"
#include <cassert>


int main()
{
  {
    String test = "Keep your head up!";
    std::vector<String> result;

    result = test.split(' ');

    assert(test == "Keep your head up!");
    assert(result[0] == "Keep");
    assert(result[1] == "your");
    assert(result[2] == "head");
    assert(result[3] == "up!");

}

  {
    String t = "Ngwa";
    std::vector<String> result;

    result = t.split();

    assert(t == "Ngwa");
   
    assert(result[0] == "N");
    assert(result[1] == "g");
    assert(result[2] == "w");
    assert(result[3] == "a");

}

  std::cout <<"Done testing string split" << std::endl;


  return 0;
}
