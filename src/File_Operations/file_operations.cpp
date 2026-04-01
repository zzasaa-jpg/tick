#include "./file_operations.hpp"
#include <iostream> 
#include <fstream>

file_operations file_oprs;
file_operations::file_operations() {};

std::vector<std::string> file_operations::read_file(const std::string& file_path)
{
	std::ifstream read_file_stream(file_path);
	if(!read_file_stream)
	{
		std::cout << "File not found![File oprs read]\n";
		return {};
	}

	std::vector<std::string> content;
	std::string line;
	while(std::getline(read_file_stream, line))
	{
		content.push_back(line);
	}
	read_file_stream.close();
	return content;
}
