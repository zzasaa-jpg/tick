#include "./Search.hpp"

#include <iostream>
#include <string>

int Search(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "Search path is require!\n";
		return -1;
	}
	else
	{
		std::string search_path = argv[2];
		//std::cout << Linear_Search("./directory.txt", search_path);
		return 0;
	}
}
