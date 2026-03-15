#include "./Default.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/RMR_Utility/RMR.hpp"
#include "../../../File_Checking_Process/file_checking_process.hpp"
#include "../../../Utility/Exists_Path_Utility/Exists_path.hpp"
#include "../../../Utility/RCFV_Utility/RCFV_Utility.hpp"

int Default(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "Default path is require!" << std::endl;
		return -1;
	}
	std::string default_path = argv[2];

	// Checking the directory.txt file ---------------------------------
	std::string error_1 = "Directory.txt file does not exist! [Default arg]";
	if(!condtnl_arg_cls.path_exists("directory.txt", error_1)) return -1;

	// Checking the default_path is exists or no -----------------------
	std::string error_2 = "Path does not exist! [Default arg]";
	if(!condtnl_arg_cls.path_exists(default_path, error_2)) return -1;

	// Checking whether a directory file contains a default path or not
	if(exists_path_class.exists_path("directory.txt", default_path))
	{
		std::cout << "Path is already written!!\n";
		return -1;
	}
	
	// Set the default path --------------------------------------------
	std::string Duplicate_path = "", de = "default_path";
	std::string content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");
	rmr_utility.RMR("directory.txt", content.find("...") != std::string::npos ? "..." : condtnl_arg_cls.get_default_path(),default_path, de);
	file_check_prcs.File_checking_process(0, Duplicate_path, de);
	return 0;
}
