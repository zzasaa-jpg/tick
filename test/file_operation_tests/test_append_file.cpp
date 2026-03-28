#include "../../src/File_Operations/file_operations.hpp"
#include <cassert>
#include <iostream>

int main()
{
	file_oprs.append_file("./Test_Results/test1.txt", "Append file Pass!");

	auto result1 = file_oprs.read_file("./Test_Results/test1.txt");
	assert(result1[1] == "Append file Pass!");
	
	file_oprs.append_file("./Test_Results/test3.txt", 67890);

	auto result2 = file_oprs.read_file("./Test_Results/test3.txt");
	assert(result2[1] == "67890");

	std::cout << "Test passed\n";
	return 0;
}
