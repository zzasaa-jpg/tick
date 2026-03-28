#include "../../src/File_Operations/file_operations.hpp"
#include <cassert>
#include <iostream>

int main()
{
	file_oprs.write_file("./Test_Results/test.txt", "Hello world From CLI Timer Tool(Tick).");

	auto result = file_oprs.read_file("./Test_Results/test.txt");
	assert(result.size() == 1);
	assert(result[0] == "Hello world From CLI Timer Tool(Tick).");
	std::cout << "Test passed\n";
	return 0;
}
