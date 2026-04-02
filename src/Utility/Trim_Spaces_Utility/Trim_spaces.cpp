#include "./Trim_spaces.hpp"
#include <iostream>

Trim_spaces_class trim_spaces_class;
Trim_spaces_class::Trim_spaces_class(){};

// str parameter according trim spaces and tabs -----------
std::string Trim_spaces_class::trim_spaces(std::string& str)
{
	size_t start = str.find_first_not_of(" \t"),
	       end   = str.find_last_not_of(" \t");

	if(start == std::string::npos)
	{
		str.clear();
		return str;
	}

	str.erase(end + 1);
	str.erase(0, start);
	return str;
}
// --------------------------------------------------------
