#include "./New.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/Exists_PK_Utility/Exists_pk.hpp"
#include "../../../Program_boot/program_boot.hpp"
#include "../../../File_Operations/file_operations.hpp"
#include "../../../File_Checking_Process/file_checking_process.hpp"

#include <iostream>
#include <string>
#include <vector>

std::string trim0_(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end   = s.find_last_not_of(" \t");

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

	std::string new_path = argv[2];
	std::string path_key = argv[3];

	// Checking the new_path is exists or no ---------------------------
	std::string error = "Path does not exist! [New arg]";
	if(!condtnl_arg_cls.path_exists(new_path, error)) return -1;

	// Checking the user path key is exists or no ----------------------
	if(exists_pk_class.exists_key("directory.txt", path_key) == false){
		bool running = true;
		while(running){
			// If user path and key is not exists in directory file than terminate the
			// while loop move next execution
			if(
				exists_pk_class.exists_key("directory.txt", path_key) == false &&
				exists_pk_class.exists_path("directory.txt", new_path) == false)
			{
				running = false;
			}
			// User path key is invalid return -1 -------------------------------------
			else if(exists_pk_class.exists_key("directory.txt", path_key) == false)
			{
				std::cout << "Invalid key! [New arg]\n";
				return -1;
			}
		}

	}

	// Reading directory file for terminate execution to same key ------
	std::ifstream file("directory.txt");
	std::string line, path;
	while(std::getline(file, line))
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
			size_t dash_pos = line.find('-');
			size_t equal_pos = line.find('=');
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
	if(exists_pk_class.exists_path("directory.txt", new_path))
	{
		std::cout << "Path is already written! [New arg]\n";
		prgm_boot.Program_Entry(2, new_path, path_key);
		return -1;
	}
	file_oprs.append_file("directory.txt", path_key + " = " + new_path + " - 0\n");
	file_check_prcs.File_checking_process(2, new_path, path_key);
	return 0;

}
