#include "../../src/File_Operations/file_operations.hpp"

#include <iostream>

int main()
{
	// Append file value string
	file_oprs.append_file("./Testing_txt_files/test1.txt", "Append file Pass!");

	auto result1 = file_oprs.read_file("./Testing_txt_files/test1.txt");
	if(result1[1] != "Append file Pass!") { std::cout << -1 << std::endl; return -1; }
	
	// Append file value integer
	file_oprs.append_file("./Testing_txt_files/test3.txt", 67890);

	auto result2 = file_oprs.read_file("./Testing_txt_files/test3.txt");
	if(result2[1] != "67890") { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
	return 0;
}
