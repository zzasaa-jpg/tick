#include "../../src/File_Operations/file_operations.hpp"
#include "../../src/Utility/Dir_Permission_Checker_Utility/dir_permission.hpp"

#include <iostream>
#include <string>

int main()
{
	file_oprs.write_file("./Testing_txt_files/test2.txt", "Hello World");
	
	// Checking directory permission
	std::string path = "./Testing_txt_files";
	auto res = DirPermissionChecker::check(path);
	if(!DirPermissionChecker::Print_Permission(res, path)) { std::cout << -1 << std::endl; return -1; }

	std::cout << "Test passed\n";
	return 0;
}
