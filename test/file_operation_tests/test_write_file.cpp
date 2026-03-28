#include "../../src/File_Operations/file_operations.hpp"
#include <cassert>
#include <iostream>

int main()
{
	file_oprs.write_file("./Test_Results/test1.txt", "Write file Pass!");

	auto result1 = file_oprs.read_file("./Test_Results/test1.txt");
	assert(result1[0] == "Write file Pass!");
	
	file_oprs.write_file("./Test_Results/test3.txt", 12345);

	auto result2 = file_oprs.read_file("./Test_Results/test3.txt");
	assert(result2[0] == "12345");

	std::cout << "Test passed\n";
	return 0;
}
