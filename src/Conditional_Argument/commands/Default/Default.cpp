#include "./Default.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/RMR_Utility/RMR.hpp"
#include "../../../File_Checking_Process/file_checking_process.hpp"
#include "../../../Utility/Exists_PK_Utility/Exists_pk.hpp"
#include "../../../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../../../Utility/Dir_Permission_Checker_Utility/dir_permission.hpp"
#include "../../../Utility/REMOVE_SLASH_UTILITY/Remove_Slash.hpp"

#include <algorithm>

int Default(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "Default path is require!" << std::endl;
		return -1;
	}
	std::string default_path = argv[2], error, du_flag_path = "", path_key = "default_path",
		file_content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");

	// Normalize default_path ------------------------------------------
	#ifdef _WIN32
	transform(default_path.begin(), default_path.end(), default_path.begin(), ::tolower);
	#endif

	// Checking the default_path is exists or no -----------------------
	error = "Path does not exist! [Default arg]";
	if(!condtnl_arg_cls.path_exists(default_path, error)) return -1;

	// Checking the default_path is directory or not -------------------
	error = " -> This path is not a directory! [Default arg]";
	if(!condtnl_arg_cls.Is_directory(default_path, error)) return -1;

	// Checking the default_path location permissions ------------------
	auto res = DirPermissionChecker::check(default_path);
	if(!DirPermissionChecker::Print_Permission(res, default_path)) return -1;

	// Remove duplicate slash ------------------------------------------
	default_path = remove_slash_utility.remove_slash(default_path);

	// Checking whether a directory file contains a default path or not
	if(exists_pk_class.exists_pk("directory.txt", default_path, true))
	{
		std::cout << "Path is already written!!\n";
		return -1;
	}

	// If timer is active than did not set the default path just return -1
	if (condtnl_arg_cls.get_default_path() != "..." && condtnl_arg_cls.read_status(condtnl_arg_cls.get_default_path())) { return -1; }

	// Set the default path --------------------------------------------
	rmr_utility.RMR("directory.txt", file_content.find("...") != std::string::npos ? "..." : condtnl_arg_cls.get_default_path(), default_path, path_key);
	file_check_prcs.File_checking_process(0, du_flag_path, path_key);
	return 0;
}
