#include "../../src/Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.hpp"
#include "../../src/File_Operations/file_operations.hpp"
#include "../../src/Utility/RCFV_Utility/RCFV_Utility.hpp"

#include <iostream>
#include <string>

int main()
{
	// Windows path
	file_oprs.write_file("./Testing_txt_files/test.txt", "default_path = C://Users/abcd/folder_path");
	std::string file_content1 = rcfv_utility.Read_content_from_vector<std::string>("./Testing_txt_files/test.txt");
	std::string default_path1 = default_path_utility.default_path(file_content1);

	if(default_path1 != "C://Users/abcd/folder_path\n") { std::cout << -1 << std::endl; return -1; }

	// linux path
	file_oprs.write_file("./Testing_txt_files/test1.txt", "default_path = /home/abcd/folder_path");
	std::string file_content2 = rcfv_utility.Read_content_from_vector<std::string>("./Testing_txt_files/test1.txt");
	std::string default_path2 = default_path_utility.default_path(file_content2);

	if(default_path2 != "/home/abcd/folder_path\n") { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
	return 0;
} 
