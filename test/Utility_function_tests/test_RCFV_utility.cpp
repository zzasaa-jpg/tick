#include "../../src/Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../../src/File_Operations/file_operations.hpp"

#include <string>
#include <iostream>

int main()
{
	// Read Content From Vector
	file_oprs.write_file("./Test_Results/test3.txt", "default_path = C://Users/abcd/folder_path");
	std::string file_content = rcfv_utility.Read_content_from_vector<std::string>("./Test_Results/test3.txt");
	if(file_content != "default_path = C://Users/abcd/folder_path\n") { std::cout << -1; return -1; }

	// File does not exists
	std::string file_content1 = rcfv_utility.Read_content_from_vector<std::string>("./Test_Results/abcd.txt");
	std::cout << file_content1;

	std::cout << "Test passed\n";
	return 0;
}

