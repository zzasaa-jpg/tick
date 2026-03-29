#include "../../src/Utility/Exists_PK_Utility/Exists_pk.hpp"
#include "../../src/File_Operations/file_operations.hpp"

#include <string>
#include <iostream>

int main()
{
	// Checking the targetKey and targetPath
	file_oprs.write_file("./Test_Results/test4.txt", "a = C://Users/abcd/folder_path - 0");
	std::string targetPath = "C://Users/abcd/folder_path", targetKey = "a", filename = "./Test_Results/test4.txt";

	if(!exists_pk_class.exists_path(filename, targetPath)) { std::cout << -1; return -1; }
	if(!exists_pk_class.exists_key(filename, targetKey)) {std::cout << -1; return -1; }

	std::cout << "Test passed\n";
}
