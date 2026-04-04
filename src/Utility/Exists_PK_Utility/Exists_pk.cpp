#include "./Exists_pk.hpp"
#include "../RCFV_Utility/RCFV_Utility.hpp"
#include "../Trim_Spaces_Utility/Trim_spaces.hpp"

#include <string>
#include <unordered_set>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Exists_pk_class exists_pk_class;
Exists_pk_class::Exists_pk_class(){};

std::unordered_set<std::string> path_cache, key_cache;
fs::file_time_type cached_time;

// Extract base path from original path -------------------
std::string extract_base_path(const std::string& path)
{
    size_t pos = path.find(" - ");

    if(pos != std::string::npos)
        return path.substr(0, pos);

    return path;
}
// --------------------------------------------------------

// If directory.txt have a new content than load new paths and keys
void load_path_and_keys(const std::string& filename)
{
	path_cache.clear();

	std::ifstream read_file_stream(filename);
	std::string line;

	while(std::getline(read_file_stream, line))
	{
		size_t pos = line.find('=');

		if(pos != std::string::npos)
		{
			// caching the paths ------------------------
			std::string path_ = line.substr(pos + 1);
			path_ = trim_spaces_class.trim_spaces(path_); // Trim the path
			path_ = extract_base_path(path_); // Extract the base path
			path_cache.insert(path_);

			// caching the keys -------------------------
			std::string key_ = line.substr(0, pos);
			key_ = trim_spaces_class.trim_spaces(key_); // Trim the key
			key_cache.insert(key_);
		}
	}
	cached_time = fs::last_write_time(filename);
}
//---------------------------------------------------------

// Checking path & key existence in directory file --------
bool Exists_pk_class::exists_pk(const std::string& filename, std::string& targetPK, bool PK)
{
	// Last write time ------------------------------------------
	fs::file_time_type last_write_time_of_filename = fs::last_write_time(filename);

	// File time is not eqaul to cached time than load new paths & keys
	if(key_cache.empty() || path_cache.empty() || last_write_time_of_filename != cached_time)
	{
		load_path_and_keys(filename);
	}

	if(PK)
	{
		// Trim the target path
		std::string base_target = trim_spaces_class.trim_spaces(targetPK);
		return path_cache.find(base_target) != path_cache.end();
	} else
	{
		// Trim the target key
		std::string base_key = trim_spaces_class.trim_spaces(targetPK);
		return key_cache.find(base_key) != key_cache.end();
	}
}
// --------------------------------------------------------
