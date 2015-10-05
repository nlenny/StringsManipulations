//File:        string-interface.h   
//       
//Version:     1.0
//Date:        Fall 2013
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for use with test oracle.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// You will either have use this interface or call your methods through this interface.
// For Part I you do not need to have the methods with the Part 2 lable.
// The I/O operators can be friend functions.

const int DEFAULT_STRING_CAPACITY = 256; //Or what ever number is specified by the assignment.

class String {
public: 
            String        ();               
            String        (const char);                       
            String        (const char[]);           
            String        (const int, const char[]);        //Part 2 
            String        (int);                            //Part 2
            String        (const String&);                  //Part 2 
            ~String       ();                               //Part 2 
    String& operator=     (String);                         //Part 2 

    char&   operator[]    (int);                            
    char    operator[]    (int)                     const;  
    int     capacity      ()                        const;
    int     length        ()                        const; 
    bool    operator==    (const String&)           const; 
    bool    operator<     (const String&)           const;
    String  operator+     (const String&)           const; 
};

std::istream& operator>>(std::istream&, String&);
std::ostream& operator<<(std::ostream&, const String&);

String  operator+       (const char[], const String&);
String  operator+       (const char, const String&);
bool    operator==      (const char[], const String&);
bool    operator<       (const char[], const String&);
bool    operator==      (const char, const String&);
bool    operator<       (const char, const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);



