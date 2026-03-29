#include "../../src/File_Operations/file_operations.hpp"

#include <iostream>

int main()
{
	// Writing file value string
	file_oprs.write_file("./Testing_txt_files/test1.txt", "Write file Pass!");

	auto result1 = file_oprs.read_file("./Testing_txt_files/test1.txt");
	if(result1[0] != "Write file Pass!") { std::cout << -1 << std::endl; return -1; }
	
	// Writing file value integer
	file_oprs.write_file("./Testing_txt_files/test3.txt", 12345);

	auto result2 = file_oprs.read_file("./Testing_txt_files/test3.txt");
	if(result2[0] != "12345") { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
	return 0;
}
