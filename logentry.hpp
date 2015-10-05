 #ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 

  //  friend std::ostream& operator<< (std::ostream& out, const Date&);

public:
  // Date(){};
   Date(): day(), month(), year(0) {};
  // Date(const String& dates);

  void setday(String linestring){day = linestring;};
  void setmonth(String linestring){month = linestring;};
  void setyear(int linevalue){year = linevalue;};
  String getday()const{return day;};
  String getmonth()const{return month;};
  int getyear()const{return year;};
  
private:
  String  day, month;
  int     year;
};

////////////////////////////////////////////////////////////
class Time {
  // friend std::ostream& operator<< (std::ostream& out, const Time&);
public:
  Time(): hour(0), minute(0), second(0){};
  // Time(const String& times);

  void sethour(int linevalue){hour = linevalue;};
  void setminute(int linevalue){minute = linevalue;};
  void setsecond(int linevalue){second = linevalue;};
  int gethour()const{return hour;};
  int getminute()const{return minute;};
  int getsecond()const{return second;};

private:
  int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
  friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
public:
  LogEntry() {};
  LogEntry(String);
  String gethost()const {return host;};
  int getbyte()const  {return number_of_bytes;};
  
private:
  String  host;
  Date    date;
  Time    time;
  String  request;
  String  status;
  int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream& in);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

