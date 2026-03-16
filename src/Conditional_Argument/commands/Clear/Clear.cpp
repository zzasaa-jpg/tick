#include "./Clear.hpp"
#include "../../conditional_argument.hpp"
#include "../../../All_file_names/All_file_names.hpp"
#include "../../../File_Operations/file_operations.hpp"

#include <iostream>
#include <string>

int Clear(int argc, char* argv[])
{
	std::vector<std::string> Clearing_Files = AFNs_class.get_all_file_names();
	const std::string directory_content = "default_path = ... - 0";

	std::string base_path;

	if(argc > 2)
	{
		// User path mode -------------------------------------
		base_path = argv[2];
		std::string error = "Path does not exist! [Clear/Reset arg]";
		if(!condtnl_arg_cls.path_exists(base_path, error)) return -1;

		int running = condtnl_arg_cls.read_status(base_path);
		std::cout << running << std::endl;
		if(running == -1) return -1;
	}
	else
	{
		// Default path mode ----------------------------------
		base_path = condtnl_arg_cls.get_default_path();

		// Checking whether default path is not set than return -1
		if(base_path == "...");
		{
			std::cout << "Set the default path! [Clear/Reset arg]\n";
			return -1;
		}
	}

	// If Program is active than terminate the clear/reset files --
	if(condtnl_arg_cls.read_status(base_path) == 1) return -1;

	for (auto& file : Clearing_Files)
	{
		std::string full =  base_path + "/" + file;

		if(file == "directory.txt")
		{
			file_oprs.write_file(full, directory_content);
		} else
		{
			file_oprs.write_file(full, 0);
		}
		std::cout << "File Cleared: " << full << std::endl;
	}
	return 1;
}
