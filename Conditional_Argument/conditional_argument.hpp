#ifndef CONDITIONAL_ARGUMENT
#define CONDITIONAL_ARGUMENT

#include <string>

class Conditional_Argument_Class{
	public:
		Conditional_Argument_Class();
		int condition_of_arguments(char* argv[], int argc);
	private:
		bool path_exists(const std::string& path, const std::string& arg);
		int read_status(const std::string& path);
		std::string get_default_path();
};

extern Conditional_Argument_Class condtnl_arg_cls;

#endif // CONDITIONAL_ARGUMENT
