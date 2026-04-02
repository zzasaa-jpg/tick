#include "./File_Checking_Process/file_checking_process.hpp"
#include "./Conditional_Argument/conditional_argument.hpp"

#include <string>

using namespace std;

int main(int argc, char* argv[]){
	if (argc == 1){
		// Normal execution--------------
		std::string du_flag_path = "", path_key = "default_path";
		file_check_prcs.File_checking_process(0, du_flag_path, path_key);
		return 0;
	}

	// Arguments execution ------------------
	int result = condtnl_arg_cls.condition_of_arguments(argv, argc);

	// IF unknown argumet, do NOT run timer--
	if (result <= 0) return 0;

	return 0;
}
