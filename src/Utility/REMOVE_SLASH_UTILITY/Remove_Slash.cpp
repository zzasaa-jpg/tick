#include "Remove_Slash.hpp"
#include <iostream>

REMOVE_SLASH_UTILITY_CLASS remove_slash_utility;
REMOVE_SLASH_UTILITY_CLASS::REMOVE_SLASH_UTILITY_CLASS() {};

std::string REMOVE_SLASH_UTILITY_CLASS::remove_slash(std::string& path)
{
	// Convert '\' to '/'
	for (char &c : path)
	{
		if(c == '\\') c = '/';
	}

	// Remove duplicates '/'
	std::string result;
	bool slash = false;

	for(char c : path)
	{
		if(c == '/')
		{
			if(!slash)
			{
				result += c;
				slash = true;
			}
		} else
		{
			result += c;
			slash = false;
		}
	}

	// Remove last slash
	while(!result.empty() && (result.back() == '/' || result.back() == '\\'))
	{
        	result.pop_back();
	}
	return result;
}
