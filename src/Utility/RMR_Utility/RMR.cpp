#include "./RMR.hpp"
#include "../../File_Operations/file_operations.hpp"

#include <string>
#include <vector>
#include <iostream>

RMR_UTILITY_CLASS rmr_utility;
RMR_UTILITY_CLASS::RMR_UTILITY_CLASS(){};

int RMR_UTILITY_CLASS::RMR(std::string file_path, std::string target, std::string put_value, std::string key)
{
	// Reading file -------------------------------------------------------
	std::ifstream inFile(file_path);
	if(!inFile)
	{
		std::cout << "directory.txt file not found![RMR Utility]\n";
		return -1;
	}

	std::vector<std::string> lines;
	std::string line;

	while(getline(inFile, line))
	{
	    lines.push_back(line);
	}
	inFile.close();
	// --------------------------------------------------------------------

	// Modifying file content ---------------------------------------------
	for(auto &content : lines)
	{
		size_t pos = content.find('=');
		if(pos != std::string::npos)
		{
		    std::string found_key = content.substr(0, pos);

		    // trim spaces
		    found_key.erase(0, found_key.find_first_not_of(" "));
		    found_key.erase(found_key.find_last_not_of(" ") + 1);

		    if(found_key == key)
		    {
			// exact match found
			size_t pos = content.find(target);

			    if(pos != std::string::npos)
			    {
				content.replace(pos, target.length(), put_value);
			    }
		    }
		}
	}
	// --------------------------------------------------------------------

	// Write file ---------------------------------------------------------
	std::ofstream out(file_path);

	for(const auto& l : lines)
	{
	    out << l << "\n";
	}
	// --------------------------------------------------------------------

	return 0;
}

