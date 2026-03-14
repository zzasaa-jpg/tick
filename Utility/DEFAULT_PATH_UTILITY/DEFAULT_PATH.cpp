#include "./DEFAULT_PATH.hpp"

#include <string>

DEFAULT_PATH_UTILITY_CLASS default_path_utility;
DEFAULT_PATH_UTILITY_CLASS::DEFAULT_PATH_UTILITY_CLASS(){};

std::string DEFAULT_PATH_UTILITY_CLASS::default_path(const std::string& file_content)
{
	size_t start = file_content.find("=") + 1;
	size_t end = file_content.find("-");

	// Grab default path --------------------------------------------------
	std::string default_path = file_content.substr(start, end - start);

	// Removing spaces ----------------------------------------------------
	default_path.erase(0, default_path.find_first_not_of(" "));
	default_path.erase(default_path.find_last_not_of(" ") + 1);
	
	return default_path;
}
