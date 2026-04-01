#include "./Search.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/Exists_PK_Utility/Exists_pk.hpp"

#include <iostream>
#include <string>

int Search(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "Search path is require!\n";
		return -1;
	}

	std::string search_path = argv[2], fileName = "directory.txt", error;

	// Checking the search_path is exists or no ---------------------------
	error = "Path does not exist! [Search arg]";
	if(!condtnl_arg_cls.path_exists(search_path, error)) return -1;

	if(exists_pk_class.exists_path(fileName, search_path))
	{
		std::cout << "Path is found! [Search arg]\n";
		return 1;
	} else
	{
		std::cout << "Path is not found! [Search arg]\n";
		return -1;
	}
}
