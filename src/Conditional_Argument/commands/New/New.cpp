#include "./New.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/Exists_PK_Utility/Exists_pk.hpp"
#include "../../../Program_boot/program_boot.hpp"
#include "../../../File_Operations/file_operations.hpp"
#include "../../../File_Checking_Process/file_checking_process.hpp"
#include "../../../Utility/Dir_Permission_Checker_Utility/dir_permission.hpp"
#include "../../../Utility/REMOVE_SLASH_UTILITY/Remove_Slash.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string trim0_(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t"),
	   end   = s.find_last_not_of(" \t");

    if(start == std::string::npos)
        return "";

    return s.substr(start, end - start + 1);
}

int New(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "New path is required! [New arg]\n";
		return -1;
	}
	else if(argc < 4)
	{
		std::cout << "Path key is required! [New arg]\n";
		return -1;
	}

	std::string new_path = argv[2], path_key = argv[3], error;

	// Normalize new_path and path_key ---------------------------------
	#ifdef _WIN32
	transform(new_path.begin(), new_path.end(), new_path.begin(), ::tolower);
	transform(path_key.begin(), path_key.end(), path_key.begin(), ::tolower);
	#endif

	// Checking the new_path is exists or no ---------------------------
	error = "Path does not exist! [New arg]";
	if(!condtnl_arg_cls.path_exists(new_path, error)) return -1;

	// Checking the new_path is directory or not -----------------------
	error = " -> This path is not a directory! [New arg]";
	if(!condtnl_arg_cls.Is_directory(new_path, error)) return -1;

	// Checking the new_path location permissions ----------------------
	auto res = DirPermissionChecker::check(new_path);
	if(!DirPermissionChecker::Print_Permission(res, new_path)) return -1;

	// Remove duplicate slash ------------------------------------------
	new_path = remove_slash_utility.remove_slash(new_path);

	// Checking the user path key is exists or no ----------------------
	if(exists_pk_class.exists_pk("directory.txt", path_key, false) == false){
		bool running = true;
		while(running){
			// If user path and key is not exists in directory file than terminate the
			// while loop move next execution
			if(
				exists_pk_class.exists_pk("directory.txt", path_key, false) == false &&
				exists_pk_class.exists_pk("directory.txt", new_path, true) == false)
			{
				running = false;
			}
			// User path key is invalid return -1 -------------------------------------
			else if(exists_pk_class.exists_pk("directory.txt", path_key, false) == false)
			{
				std::cout << "Invalid key! [New arg]\n";
				return -1;
			}
		}
	}

	// Reading directory file for terminate execution to same key ------
	std::ifstream read_file_stream("directory.txt");
	std::string line, path;
	while(std::getline(read_file_stream, line))
	{
		size_t pos = line.find('=');
		if(pos != std::string::npos)
		{
		    std::string found_key = line.substr(0, pos);

		    // trim spaces
		    found_key.erase(0, found_key.find_first_not_of(" "));
		    found_key.erase(found_key.find_last_not_of(" ") + 1);

		    if(found_key == path_key)
		    {
			// exact match found
			size_t dash_pos = line.find('-'), equal_pos = line.find('=');
			if(dash_pos != std::string::npos && equal_pos != std::string::npos)
			{
				std::string path_ = line.substr(equal_pos + 1, dash_pos - equal_pos - 1);
				path_ = trim0_(path_);
				if(path_ != new_path)
				{
					std::cout << path_key << " -> This key is not user path key OR same key exists in directory file [New arg]\n";
					return -1;
				}
			}
		    }
		}
	}

	// Checking whether a directory file contains a new_path or not ----
	if(exists_pk_class.exists_pk("directory.txt", new_path, true))
	{
		std::cout << "Path is already written! [New arg]\n";
		prgm_boot.Program_Entry(1, new_path, path_key);
		return -1;
	}

	file_oprs.append_file("directory.txt", path_key + " = " + new_path + " - 0\n");
	file_check_prcs.File_checking_process(1, new_path, path_key);
	return 0;
}
