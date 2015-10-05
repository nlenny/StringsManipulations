#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <vector>
#include <cassert>

const int DEFAULT_STRING_CAPACITY = 256;

class String {
 public:
  String ();
  String (int);
  String (const char);
  String (const char[]);
  String (const int, const  char[]);
  ~String();
  String (const String& rhs);
  String operator* (const int);
  char operator[] (int) const;
  char& operator[] (int);
  bool operator== (const String&) const;
  bool operator< (const String&) const;
  int findchar (const char) const;
  int findstr (const String&) const;
  int capacity() const;
  int length() const;
  int to_i();
  String substr (int, int) const;
  String& operator=(String );  
  String operator+ (const String&) const;
  void swap(String&);
  void reallocate(const int);
  std::vector<String> split()const;
  std::vector<String> split(const char)const;
  friend std::ostream& operator<<(std::ostream&, const String&);
  String getline(std::istream&);

  String& operator += (const String& rhs) { return *this = *this + rhs; };
  String& operator += (const char rhs[]) { return *this = *this + String(rhs); };
  String& operator += (char rhs) { return *this = *this + String(rhs); };

  String operator - (const int) const;
  String& operator -= (const int x) { return *this = *this - x; };

  String operator - (const char) const;
  String& operator -= (const char ch) { return *this = *this - ch; };

  

private:
  char  *ptr;
  int cap;
  
};

std::istream& operator>>(std::istream&, String&);
String operator+ (const char[], const String&);
String operator+ (const char, const String&);
bool operator== (const char[], const String&);
bool operator< (const char[], const String&);
bool operator== (const char, const String&);
bool operator< (const char, const String&);
bool operator<= (const String&, const String&);
bool operator!= (const String&, const String&);
bool operator>= (const String&, const String&);
bool operator> (const String&, const String&);
String getline(std::istream& in);

#endif
