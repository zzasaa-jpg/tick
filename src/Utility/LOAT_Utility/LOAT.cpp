#include "./LOAT.hpp"
#include "../../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../../../src/Utility/RCFV_Utility/RCFV_Utility.hpp"

#include <fstream>
#include <string>
#include <sstream>

LOAT_UTILITY_CLASS loat_utility;
LOAT_UTILITY_CLASS::LOAT_UTILITY_CLASS(){};

// List of active timers print --------------------------------------
void LOAT_UTILITY_CLASS::loat()
{
	// Reading file ---------------------------------------------
	std::string file_content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");

	// Split into lines -----------------------------------------
	std::stringstream ss(file_content);
	std::string line;

	bool found = false;
	// Print active timers --------------------------------------
	while(std::getline(ss, line))
	{
		if(line.find("- 1") != std::string::npos)
		{
			std::cout << line << std::endl;
			found = true;
		}
	}

	if(!found) std::cout << "No active timers!\n";
	// ----------------------------------------------------------
}
// ------------------------------------------------------------------
