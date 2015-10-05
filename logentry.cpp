//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// PRE: string is a line from log file  
// POST: LogEntry object takes values from line of input file
//
LogEntry::LogEntry(String s) 
{
  // ...
  std::vector<String> vec = s.split(' ');
  
  if(vec.size() == 10)
    {
      host=vec[0];
      std::vector<String>date_time=vec[3].split(':');
      std::vector<String>date_string=date_time[0].split('/');
      String stringday=date_string[0].substr(1,date_string[0].length());
      date.setday(stringday);
      String stringmonth=date_string[1];
      date.setmonth(stringmonth);
      int intyear=date_string[2].to_i();
      date.setyear(intyear);
      time.sethour(date_time[1].to_i());
      time.setminute(date_time[2].to_i());
      time.setsecond(date_time[3].to_i());
      request=vec[5]+vec[6]+vec[7];
      status=vec[8];

      if(vec[9]=='-')
	{
	  number_of_bytes=0;
	}
      number_of_bytes=vec[9].to_i();
    }
  else
    {
      host="";
      date.setday("");
      date.setmonth("");
      date.setyear(0);
      time.sethour(0);
      time.setminute(0);
      time.setsecond(0);
      request="";
      status="";
      number_of_bytes=0;
    }
}

////////////////////////////////////////////////////////// 
// PRE: If in is an input stream, then it is connected  
// POST: Will be filled with LegEntry from lines of istream 
//
std::vector<LogEntry> parse(std::istream& in)
{
  std::vector<LogEntry> result;
  LogEntry log;
    char ch[512];
  
 
  while(!in.eof())
    {
      in.getline(ch,512);
      String str(512, ch);
      log = str;
      result.push_back(log);
 
    }
  return result;
}

////////////////////////////////////////////////////////// 
// PRE: If out is open, then it better be connected to the file  
// POST: Outputs LogEntry to specified output stream
//
void output_all(std::ostream& out, const std::vector<LogEntry>& vl)
{
for(unsigned int i = 0; i < vl.size(); ++i)
    {
      out << vl[i];
    }
}


///////////////////////////////////////////////////////////////////////              
// PRE:  out will be connected to a file if it is a stream                 
// POST: Will output host of logEntry to logs vector               
//             
void by_host(std::ostream& out, const std::vector<LogEntry>& vl)
{
  for(unsigned int i = 0;i < vl.size();++i)
    {
      out << vl[i].gethost() <<'\n';
    }
}


//////////////////////////////////////////////////////////////////////                  
// PRE:  logs has to be given values                                              
// POST: will return the number of bytes of each logEntry                         
//                                                                                      
int byte_count(const std::vector<LogEntry>& vl)
{
  int sum=0;
  for(unsigned int i=0;i<vl.size();++i)
    {
      sum=sum+vl[i].getbyte();
    }
  return sum;
}

//===========================================================================

//Will output LogEntry to the screen

  std::ostream& operator<< (std::ostream& out, const LogEntry& s)
{
  out<<"Host: "<<s.host<<'\n';
  out<<"Day: "<<s.date.getday()<<'\n';
  out<<"Month: "<<s.date.getmonth()<<'\n';
  out<<"Year: "<<s.date.getyear()<<'\n';
  out<<"Hour: "<<s.time.gethour()<<'\n';
  out<<"Minute: "<<s.time.getminute()<<'\n';
  out<<"Second: "<<s.time.getsecond()<<'\n';
  out<<"Request: "<<s.request<<'\n';
  out<<"Status: "<<s.status<<'\n';
  out<<"Bytes: "<<s.number_of_bytes<<"\n\n";
  return out;
}

