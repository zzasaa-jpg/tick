#include "./RMR.hpp"
#include "../../File_Operations/file_operations.hpp"
#include "../Trim_Spaces_Utility/Trim_spaces.hpp"
#include "../RCFV_Utility/RCFV_Utility.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

RMR_UTILITY_CLASS rmr_utility;
RMR_UTILITY_CLASS::RMR_UTILITY_CLASS(){};

// RMR stands for read, modify, rewrite according to file_path, target, put_value, key.
int RMR_UTILITY_CLASS::RMR(std::string file_path, std::string target, std::string put_value, std::string key)
{
	// Reading file -------------------------------------------------------
	std::string file_content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");

	// Split into lines ---------------------------------------------------
	std::stringstream ss(file_content);
	std::string line;
	std::vector<std::string> lines_vector;

	// Modifying file content ---------------------------------------------
	while(getline(ss, line))
	{
	    size_t pos = line.find('=');
	    if(pos != std::string::npos)
	    {
		    std::string found_key = line.substr(0, pos);

		    // trim spaces --------------------------------------------
		    trim_spaces_class.trim_spaces(found_key);

		    if(found_key == key)
		    {
			// exact match found ----------------------------------
			size_t pos = line.find(target);

			// If target is only change status than last character only re-write.
			if(target == "1" || target == "0")
			{
				if(line.back() == '1')
				{
					line.back() = '0';
				} else
				{
					line.back() = '1';
				}
			}
			// Target length and pos according re-write. ----------
			else
			{
			    if(pos != std::string::npos)
			    {
				line.replace(pos, target.length(), put_value);
			    }
			}
		    }
		}
		lines_vector.push_back(line);
	}
	// --------------------------------------------------------------------

	// Write file ---------------------------------------------------------
	std::ofstream write_file_stream(file_path);
	for(const auto &content : lines_vector)
	{
		write_file_stream << content << "\n";
	}
	// --------------------------------------------------------------------
	return 0;
}
// ----------------------------------------------------------------------------
