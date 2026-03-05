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
		std::cout << "File not found!\n";
	}

	std::string line;
	while(std::getline(file, line))
	{
		file_oprs.get_read_content().push_back(line);
	}
	return file_oprs.get_read_content();
}

std::vector<std::string>& file_operations::get_read_content()
{
	return read_content;
}
