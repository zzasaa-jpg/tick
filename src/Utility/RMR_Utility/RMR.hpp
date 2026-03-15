#ifndef RMR_UTILITY
#define RMR_UTILITY

#include <string>

class RMR_UTILITY_CLASS
{
	public:
		RMR_UTILITY_CLASS();
		int RMR(std::string file_path, std::string target, std::string put_value, std::string key);
};

extern RMR_UTILITY_CLASS rmr_utility;

#endif // RMR_UTILITY
