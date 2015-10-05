// Testing the default constructor

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){

  {

    //Test declaration
    String test;

    //Running the tests

    assert(test == "");

    assert(test.length() == 0);
      
    assert(test.capacity() == DEFAULT_STRING_CAPACITY);
      
      String  str;
      std::cout << "|a| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity() << std::endl;
      
      // VERIFY
      assert(str == "");
      assert(str.length() == 0);
      assert(str.capacity() == DEFAULT_STRING_CAPACITY);
      
  }

// Will output the following message if test is successful.

	std::cout <<"Done testing the default string constructor!" << std::endl;

	return 0;
}



