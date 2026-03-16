#include "./Search.hpp"
#include "../../../Utility/Exists_Path_Utility/Exists_path.hpp"

#include <iostream>
#include <string>

int Search(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "Search path is require!\n";
		return -1;
	}

	std::string search_path = argv[2];
	std::string fileName = "directory.txt";

	if(exists_path_class.exists_path(fileName, search_path))
	{
		std::cout << "Path is found! [Search arg]\n";
		return 1;
	} else
	{
		std::cout << "Path is not found! [Search arg]\n";
		return -1;
	}
}
