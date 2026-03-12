#include "./file_operations.hpp"
#include <iostream> 
#include <fstream>

file_operations file_oprs;
file_operations::file_operations() {};

std::vector<std::string> file_operations::read_file(const std::string& file_path)
{
	std::ifstream file(file_path);
	if(!file)
	{
		std::cout << "File not found![File oprs read]\n";
		return {};
	}

	std::vector<std::string> content;
	std::string line;
	while(std::getline(file, line))
	{
		content.push_back(line);
	}
	return content;
}
