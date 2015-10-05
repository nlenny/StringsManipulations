// File:        main.cpp   
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Main body for logview application
//

////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "string.hpp"//added 
#include "logentry.hpp"

////////////////////////////////////////////////////////////
void output_usage_and_exit(const char cmd[], const std::vector<String>& opts);
    
////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    // Options
    std::vector<String> opt(3);
    opt[0] = "all";
    opt[1] = "bytes";
    opt[2] = "host";

    // Error if there are not 3 things on the command line
    if (argc != 3)
        { output_usage_and_exit(argv[0], opt); }

    // Open file, quit if open fails
    std::ifstream in(argv[2]);
    if (!in)
        { std::cerr << "Couldn't open " << argv[2] << "\n"; exit(2); }

    // Process the log file
    std::vector<LogEntry> log_entries = parse(in);

    // Close the in file
    in.close();

    // Handle the specified option
   
    String option(argv[1]);
   
    if (option == opt[0]) {
       
      // Output everything
        output_all(std::cout, log_entries);
    }
    else if (option == opt[1]) {
      
      // Output total number of bytes
        std::cout << "Total number of bytes sent: " 
                  << byte_count(log_entries) << std::endl;
    }
    else if (option == opt[2]) {
       
      // Host names will be out-putted here
        by_host(std::cout, log_entries);
    }
    else    {
       
        std::cerr << "Unrecognized option: " << option << std::endl;
        std::cerr << "Recognized options: " 
             << opt[0] << " "
             << opt[1] << " "
             << opt[2] << std::endl;
    }

    return 0;
}

////////////////////////////////////////////////////////////
void output_usage_and_exit(const char cmd[], const std::vector<String>& opt)
{
    
    std::cerr << "Usage: " << cmd << " [";
    
    for (std::vector<String>::size_type idx = 0; idx < opt.size() - 1; ++idx)
     
      std::cerr << opt[idx] << " | ";
   
    std::cerr << opt[opt.size() - 1] << "] log_file\n";

    // Will exit if there is an error and display that error
    exit(1);
}

