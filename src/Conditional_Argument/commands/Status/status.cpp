#include "./status.hpp"
#include "../../conditional_argument.hpp"

#include <iostream>
#include <string>

int Status(int argc, char* argv[])
{
	// User path mode ---------------------------------------------
	if(argc > 2)
	{
		std::string user_path = argv[2];
		std::string error = "Path does not exist! [Status arg]";
		if(!condtnl_arg_cls.path_exists(user_path, error)) return -1;

		std::cout << condtnl_arg_cls.read_status(user_path) << std::endl;
		return 1;
	}

	// Checking whether default path is not set than return -1
	if(condtnl_arg_cls.get_default_path() == "...")
	{
		std::cout << "Set the default path! [Status arg]\n";
		return -1;
	}
	// Default path mode ------------------------------------------
	std::cout << condtnl_arg_cls.read_status(condtnl_arg_cls.get_default_path()) << std::endl;
	return 1;
}
