#ifndef DEFAULT_PATH_UTILITY
#define DEFAULT_PATH_UTILITY

#include <string>

class DEFAULT_PATH_UTILITY_CLASS
{
	public:
		DEFAULT_PATH_UTILITY_CLASS();
		std::string default_path(const std::string& file_content);
};

extern DEFAULT_PATH_UTILITY_CLASS default_path_utility;

#endif // DEFAULT_PATH_UTILITY
