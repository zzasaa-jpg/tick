#include "./Default_Path.hpp"
#include "../Trim_Spaces_Utility/Trim_spaces.hpp"

#include <string>

DEFAULT_PATH_UTILITY_CLASS default_path_utility;
DEFAULT_PATH_UTILITY_CLASS::DEFAULT_PATH_UTILITY_CLASS(){};

std::string DEFAULT_PATH_UTILITY_CLASS::default_path(const std::string& file_content)
{
	size_t start = file_content.find("=") + 1, end = file_content.find("-");

	// Grab default path --------------------------------------------------
	std::string default_path = file_content.substr(start, end - start);

	return trim_spaces_class.trim_spaces(default_path);
}
