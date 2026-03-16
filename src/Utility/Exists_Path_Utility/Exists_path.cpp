#include "./Exists_path.hpp"
#include "../../Utility/RCFV_Utility/RCFV_Utility.hpp"

#include <string>
#include <unordered_set>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Exists_path_class exists_path_class;
Exists_path_class::Exists_path_class(){};

std::unordered_set<std::string> path_cache;
fs::file_time_type cached_time;

// Remove the spaces --------------------------------------
std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end   = s.find_last_not_of(" \t");

    if(start == std::string::npos)
        return "";

    return s.substr(start, end - start + 1);
}
// --------------------------------------------------------

// Extract base path from original path -------------------
std::string extract_base_path(const std::string& path)
{
    size_t pos = path.find(" - ");

    if(pos != std::string::npos)
        return path.substr(0, pos);

    return path;
}
// --------------------------------------------------------

// If directory.txt have a new content than load new paths
void load_paths(const std::string& filename)
{
	path_cache.clear();

	std::ifstream file(filename);
	std::string line;

	while(std::getline(file, line))
	{
		size_t pos = line.find('=');

		if(pos != std::string::npos)
		{
			std::string value = line.substr(pos + 1);
			value = trim(value); // Trim the path
			value = extract_base_path(value); // Extract the base path
			path_cache.insert(value);
		}
	}

	cached_time = fs::last_write_time(filename);
}
//---------------------------------------------------------

bool Exists_path_class::exists_path(const std::string& filename, const std::string& targetPath)
{
	// Last write time ------------------------------------------
	fs::file_time_type file_time = fs::last_write_time(filename);

	// File time is not eqaul to cached time than load new paths
	if(path_cache.empty() || file_time != cached_time)
	{
		load_paths(filename);
	}

	std::string base_target = trim(targetPath); // Trim the target path
	return path_cache.find(base_target) != path_cache.end();
}
