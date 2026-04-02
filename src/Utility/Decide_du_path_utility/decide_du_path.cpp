#include "./decide_du_path.hpp"
#include "../../../src/Conditional_Argument/conditional_argument.hpp"

#include <string>

decide_default_or_user_path_class decide_du_path_class;
decide_default_or_user_path_class::decide_default_or_user_path_class(){};

// Helper function to decide default or user path according to du_flag
std::string decide_default_or_user_path_class::decide_du_path(int du_flag, const std::string& du_flag_path, const std::string& file_path)
{
	return du_flag == 1 ? du_flag_path + file_path : condtnl_arg_cls.get_default_path() + file_path;
}
// -------------------------------------------------------------------
