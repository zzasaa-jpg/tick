#include "../../src/Utility/RMR_Utility/RMR.hpp"
#include "../../src/File_Operations/file_operations.hpp"

#include <string>
#include <iostream>

int main()
{
	// First Read file, modify content according target, re-write again
	std::string fileName = "./Testing_txt_files/test4.txt", fileContent = "a = C://Users/abcd/folder_path - 0";
	file_oprs.write_file(fileName, fileContent);

	// Status only re-write
	std::string target = "0", put_value = "1", key = "a";
	if(rmr_utility.RMR(fileName, target, put_value, key) == -1) { std::cout << -1 << std::endl; return -1; }

	// Target length according re-write
	std::string target1 = "C://Users/abcd/folder_path", put_value1 = "C://Users/efgh/folder_path", key1 = "a";
	if(rmr_utility.RMR(fileName, target1, put_value1, key1) == -1) { std::cout << -1 << std::endl; return -1; }

	// invalid file path handled
	std::string target3 = "C://Users/ijkl/folder_path", put_value3 = "C://Users/mnop/folder_path", key3 = "b";
	if(rmr_utility.RMR("./Testing_txt_files/abcd.txt", target3, put_value3, key3) == -1) { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
}
