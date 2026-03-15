#include "./New.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/Exists_Path_Utility/Exists_path.hpp"
#include "../../../Program_boot/program_boot.hpp"
#include "../../../File_Operations/file_operations.hpp"
#include "../../../File_Checking_Process/file_checking_process.hpp"

#include <iostream>
#include <string>

int New(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "New path is required!\n";
		return -1;
	}
	else if(argc < 4)
	{
		std::cout << "Path key is required!\n";
		return -1;
	}

	std::string new_path = argv[2];
	std::string path_key = argv[3];

	// Checking the directory.txt file ---------------------------------
	std::string error_1 = "Directory.txt file does not exist! [New arg]";
	if(!condtnl_arg_cls.path_exists("directory.txt", error_1)) return -1;

	// Checking the new_path is exists or no ---------------------------
	std::string error_2 = "Path does not exist! [New arg]";
	if(!condtnl_arg_cls.path_exists(new_path, error_2)) return -1;

	// Checking whether a directory file contains a new_path or not ----
	if(exists_path_class.exists_path("directory.txt", new_path))
	{
		std::cout << "Path is already written!\n";
		prgm_boot.Program_Entry(2, new_path, path_key);
		return -1;
	}

	file_oprs.append_file("directory.txt", path_key + " = " + new_path + " - 0\n");
	file_check_prcs.File_checking_process(2, new_path, path_key);
	return 0;
}
