#include "./Default_Path.hpp"
#include "../Trim_Spaces_Utility/Trim_spaces.hpp"
#include "../../../src/Conditional_Argument/commands/Default/Default.hpp"

#include <string>
#include <iostream>
DEFAULT_PATH_UTILITY_CLASS default_path_utility;
DEFAULT_PATH_UTILITY_CLASS::DEFAULT_PATH_UTILITY_CLASS(){};

// Grab the default path in file content and white spaces trimed ------------------------
std::string DEFAULT_PATH_UTILITY_CLASS::default_path(const std::string& file_content)
{
	size_t start = file_content.find("=") + 1, end = file_content.find("-"),
	       eqaul = file_content.find("=") - 1;

	// Grab default path --------------------------------------------------
	std::string default_path = file_content.substr(start, end - start);

	/*
	 * Check if the directory file actually contains a valid "default_path" entry.
	 *
	 * If this entry is missing, it likely means the user manually deleted or
	 * modified the default path in the directory file.
	 *
	 * Without this validation, the program may incorrectly treat a user path
	 * as the default path, leading to an invalid architecture state and
	 * potential crash. This check prevents that condition.
	 */
	if(file_content.substr(0, eqaul) != "default_path") return "...";

	// Trim white spaces --------------------------------------------------
	return trim_spaces_class.trim_spaces(default_path);
}
// --------------------------------------------------------------------------------------
