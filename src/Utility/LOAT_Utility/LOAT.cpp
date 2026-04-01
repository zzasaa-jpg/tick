#include "./LOAT.hpp"
#include "../../Utility/RCFV_Utility/RCFV_Utility.hpp"

#include <fstream>
#include <string>

LOAT_UTILITY_CLASS loat_utility;
LOAT_UTILITY_CLASS::LOAT_UTILITY_CLASS(){};

void LOAT_UTILITY_CLASS::loat()
{
	// Reading file ---------------------------------------------
	std::string file_name = "directory.txt";
	std::ifstream read_file_stream(file_name);
	if(!read_file_stream)
	{
		std::cout << "File not found![LOAT UTILITY]\n";
		return;
	}

	std::vector<std::string> file_content;
	std::string line;
	while(std::getline(read_file_stream, line))
	{
		file_content.push_back(line);
	}
	read_file_stream.close();
	// ----------------------------------------------------------

	// Print active timers --------------------------------------
	bool found = false;
	for(auto &content : file_content)
	{
		if(content.find("- 1") != std::string::npos)
		{
			std::cout << content << std::endl;
			found = true;
		}
	}

	if(!found) std::cout << "No active timers!\n";
	// ----------------------------------------------------------
}
