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
	std::ifstream file(file_name);
	if(!file)
	{
		std::cout << "File not found![LOAT Utility]\n";
		return;
	}

	std::vector<std::string> content;
	std::string line;
	while(std::getline(file, line))
	{
		content.push_back(line);
	}
	file.close();
	// ----------------------------------------------------------

	// Print active timers --------------------------------------
	bool found = false;
	for(auto &con : content)
	{
		if(con.find("- 1") != std::string::npos)
		{
			std::cout << con << std::endl;
			found = true;
		}
	}

	if(!found) std::cout << "No active timers!\n";
	// ----------------------------------------------------------
}
