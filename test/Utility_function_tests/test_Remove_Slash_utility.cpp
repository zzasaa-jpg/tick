#include "../../src/Utility/REMOVE_SLASH_UTILITY/Remove_Slash.hpp"
#include "../../src/File_Operations/file_operations.hpp"

#include <string>
#include <iostream>

int main()
{
	// Windows path
	std::string fileName = "./Testing_txt_files/test5.txt", fileContent = "C://Users/abcd/////folder_path/\\/\\";
	std::string remove_slash_path = remove_slash_utility.remove_slash(fileContent);

	if(remove_slash_path != "C:/Users/abcd/folder_path") { std::cout << -1 << std::endl; return -1; }
	file_oprs.write_file(fileName, remove_slash_path);

	// Linux path
	std::string fileContent1 = "/home/abcd/////folder_path/\\/\\";
	std::string remove_slash_path1 = remove_slash_utility.remove_slash(fileContent1);

	if(remove_slash_path1 != "/home/abcd/folder_path") { std::cout << -1 << std::endl; return -1; }
	file_oprs.append_file(fileName, remove_slash_path1);

	std::cout << "Test passed\n";
	return 0;
}
