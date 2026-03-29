#include "../../src/File_Operations/file_operations.hpp"

#include <iostream>

int main()
{
	// Writing file
	file_oprs.write_file("./Testing_txt_files/test.txt", "Hello world From CLI Timer Tool(Tick).");

	// Reading file
	auto result = file_oprs.read_file("./Testing_txt_files/test.txt");

	if(result[0] != "Hello world From CLI Timer Tool(Tick).") { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
	return 0;
}
