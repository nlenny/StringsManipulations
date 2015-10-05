#include "string.hpp"


//Default ctor 

String::String() 
{
    cap = DEFAULT_STRING_CAPACITY;
    ptr = new char[cap];
    ptr[0] = 0;
}



String::String(int y)
{
    cap = y;
    ptr = new char[cap];
    ptr[0] = 0;
    
}



//========================================================================================

//string constructor for single character
//Ensures character becomes a string

String::String(const char ch)
{
  cap = DEFAULT_STRING_CAPACITY;
  ptr = new char[cap];
  ptr[0] = ch;
  ptr[1] = 0;

}

//=======================================================================================

// String constructor for single character
//Ensures the string is s and null terminating

String::String(const char ch[])
{
  cap = DEFAULT_STRING_CAPACITY;
  ptr = new char[cap];
  int i = 0;
 
 while (ch[i]!= 0)
    {	    
      ptr[i] = ch[i];
      ++i;
    }
  ptr[i] = 0;
}


//========================================================================================

//Allows the user to resize the capacity year, and pass in variables.

String::String(const int x, const char ch[])
{
  cap = x;
  ptr = new char[cap];
  
  int i = 0;
  while (ch[i] != 0)
    {
        if (i == cap -1) break;
      ptr[i] = ch[i];
      ++i;
    }
  ptr[i] = 0;
}

//=====================================================================================

// Destructor to free memory

String::~String()
{

  delete [] ptr;

}

//======================================================================================

// Copy Constructor

String::String(const String& rhs)
{
  cap = rhs.cap;
  ptr = new char [cap];

  int i = 0;
  while(rhs.ptr[i] != '\0')
    {
      ptr[i] = rhs.ptr[i];
      ++i;
    }

  ptr[i] = '\0';

}

//=============================================================================

//========================================================================================

//Compares 2 strings 

bool String::operator == (const String& rhs) const
{

    int i = 0;
    
    while (ptr[i] != 0) 
      {
        if (ptr[i] != rhs.ptr[i]) return false;
        ++i;
      }

    if (rhs.ptr[i] != 0) return false;
    
    return true;
}

//========================================================================================

// compares two string to determine if one is less than the other

bool String::operator < (const String& rhs) const
{
  int i =0;

  //Will find the shortest string or the first non-equal character

  while((ptr[i] != 0)&& (rhs.ptr[i] != 0)&&(ptr[i] == rhs.ptr[i])) ++i;
 
      if((ptr[i] == 0)&&(rhs.ptr[i] == 0)) return false;

          if(ptr[i] == 0) return true; // "aa" < "aaX"
  
	      if(ptr[i] < rhs.ptr[i]) return true; // "aaa" < "aabx"

	      return false;

} 
 
//========================================================================================

// Adds 2 string together
// Requires length + rhs.length() < capacity
//Ensures: Return value == "abc" if "a" + "bc"

String String::operator+ (const String& rhs) const
{
  String result(ptr);
  int offset = result.length();
  int i = 0;
  
  while (rhs.ptr[i] != 0)
    {
      if (i + offset == result.capacity()- 1) break;
      result[i + offset] = rhs.ptr[i];
      ++i;
    }
  result[i + offset] = 0;

  return result;

}

//========================================================================================

// Read-in a string 

std::istream& operator >> (std::istream& in, String& rhs)

{
  char temp;

  while (in)
    {
      in.get(temp);
      if (!in.eof())
	{
	  rhs = rhs + temp;
	}
    }

  return in;
}

//======================================================================================

// Read-out or outputs a string

std::ostream& operator << (std::ostream& out, const String& str)

{
    out << str.ptr;

  return out;

}

//========================================================================================

// Returns the character from an index in demand

char String::operator [] (int i) const

{
 
  assert(i >= 0);

  assert(i <= length());

  return ptr[i];

}

//========================================================================================

// Returns the character from a specified index

char& String::operator [] (int i)

{

  assert(i >= 0);                                  

  assert(i <= length());                                                           

  return ptr[i]; 

}

//=======================================================================================

// Finds the first occrance of a character in a string

int String::findchar (const char find)const

{
 
  for (int i = 0; i < length(); ++i)
    {
      if (ptr[i] == find)
	{
	  return i;
	}
    
    }

      return -1;

}

  //=====================================================================================

// Determines the number of times a string occurs in another string.

int String::findstr(const String& rhs) const

{
  for (int i = 0; i < length() - rhs.length(); ++i)
    {
      for (int j = 0; j < rhs.length(); ++j)
	{
	  if (ptr[i + j] != rhs[j])
	      break;
	      }
	  return i;
	}

   return -1;

}

  //=====================================================================================

// Returns a selected part of a string

  String String::substr (int left, int right) const

  {

    if((left < 0)||(right < 0)) return String("");

    String result;
    int i;

    for(i = left; i < right; ++i)
     
      result[i-left] = ptr[i];
    
         result[i-left] = 0;
    
    return result;

  }

 
 //=======================================================================

// Will return the length of a string
 
int String::length()const

{
  int result = 0;

  while (ptr[result] != 0)
    ++result;

  return result;

}
 
//========================================================================

//will return true or false if two string are not equal

bool operator!= (const String& lhs, const String& rhs)
{
  return (!(lhs == rhs));
}
//======================================================================

// Will return true if one string is less than or equal to another

bool operator<= (const String& lhs, const String& rhs)
{
  return (lhs < rhs) || (lhs == rhs);
}

//======================================================================

//Compares and returns true if one string is greater or equal to the other

bool operator>= (const String& lhs, const String& rhs)
{
  return (lhs > rhs) || (lhs == rhs);
}

//====================================================================

// Compares and returns true if one string is strictly greater than the other

bool operator> (const String& lhs, const String& rhs)
{
  return (lhs > rhs);
}

//====================================================================

// Compares two strings for equaity

bool operator== (const char lhs[], const String& rhs)
{
  return String(lhs) == rhs;
}

//===============================================================

// Return true if a character is less than a string

bool operator< (const char lhs[], const String& rhs)
{
  return String(lhs) < rhs;
}

//======================================================================

// Checks if a character and a string are equal

bool operator== (const char lhs, const String& rhs)
{
  return String(lhs) == rhs;
}

//========================================================================

//checks if a character is less than a string

bool operator< (const char lhs, const String& rhs)
{
  return String(lhs) < rhs;
}

//=========================================================================

int String::capacity()const
{
  return cap;
}

//=========================================================================

// Part 2

void String::swap(String& str)
{
  char *temp = ptr;

  ptr = str.ptr;

  str.ptr = temp;

  int tmp = cap;

  cap=str.cap;

  str.cap=tmp;
}


 //======================================================================

 //Increases the capacity of a string and copies it.eg str.reallocate(50)
 
void String::reallocate(const int size)

{
    String newstring(size, ptr);
    swap(newstring); 
}

    
//==================================================================================
String& String::operator= (String rhs)

{
  swap(rhs);
  return *this;
} 

//=================================================================================

std::vector<String> String::split()const
{
  std::vector<String> result;
  
  for(int i = 0; ptr[i] != '\0'; ++i)
    {
      result.push_back(ptr[i]);
    }
  
  return result;
}

//================================================================================

std::vector<String> String::split(const char str)const
{
  std::vector<String> result;
  String temp;
  
  for(int i = 0; ptr[i] != '\0'; ++i)
    {
      if (ptr[i] != str)
	{
	  temp = temp + ptr[i];
	}
      else
	{
	  result.push_back(temp);
	  temp = ptr[++i];
	}
    }
  
  return (result.push_back(temp), result);
}


//==============================================================================

//Will convert a string to an integer

int String::to_i()
{
  int index_start = length() - 1;
  
  if (ptr[index_start] == '-')
    {
      return 0;
    }
  int val = 0, spot_ten = 1;
  for (int i = index_start; i >= 0; --i)
    {
      val = val + (int(ptr[i] - int('0')) * spot_ten);
      spot_ten = spot_ten * 10;
    }
  return val;
}

//===========================================================================

String String::getline(std::istream& in)
{
  String ln;
  char c = '\0';
  
  for(int i = (in.get(c), 0); (c != '\n')&&(!in.fail());++i, in.get(c))
    {
      if(i == (ln.capacity() - 1))
	{
	  ln.reallocate(ln.capacity() * 2);
	}
      ln = ln + c;
    }
  return ln;
}

//=======================================================

String String::operator - (const int x) const
{
  if (x == 0) {
    return *this;
  }

  String result;

  if (x < length()) {
    for (int i = 0; i < (length() - x); ++i) {
      result += ptr[i];
    }
  }

  return result;
}


//===========================================================

String String::operator - (const char ch) const
{
  if (findchar(ch) == -1) {
    return *this;
  }

  String result;

  for (int index = 0; index < length(); ++index) {
    if (ptr[index] != ch) {
      result += ptr[index];
    }
  }

  return result;
}
