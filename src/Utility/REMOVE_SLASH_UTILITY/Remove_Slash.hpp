#ifndef REMOVE_SLASH_UTILITY
#define REMOVE_SLASH_UTILITY

#include <string>

class REMOVE_SLASH_UTILITY_CLASS
{
	public:
		REMOVE_SLASH_UTILITY_CLASS();
		std::string remove_slash(std::string& path);
};

extern REMOVE_SLASH_UTILITY_CLASS remove_slash_utility;

#endif // REMOVE_SLASH_UTILITY
