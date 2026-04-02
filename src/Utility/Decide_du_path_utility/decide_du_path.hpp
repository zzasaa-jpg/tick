#ifndef DECIDE_DU_PATH
#define DECIDE_DU_PATH

#include <string>

class decide_default_or_user_path_class
{
	public:
		decide_default_or_user_path_class();
		std::string decide_du_path(int du_flag, const std::string& du_flag_path, const std::string& file_path);
};

extern decide_default_or_user_path_class decide_du_path_class;

#endif // DECIDE_DU_PATH
