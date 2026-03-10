#ifndef RCFV_UTILITY
#define RCFV_UTILITY

#include "../../File_operations/file_operations.hpp"
#include <string>
#include <vector>

class RCFV_UTILITY_CLASS
{
	public:
		RCFV_UTILITY_CLASS();
		template<typename T>
		T Read_content_from_vector(const std::string& file_path)
		{
			std::vector<std::string> file_content = file_oprs.read_file(file_path);
			if constexpr (std::is_same_v<T, std::string>)
			{
				std::string str_value;	
				for(const auto& content : file_content)
				{
					str_value += content;
				}
				return str_value;
			}
			else if constexpr (std::is_same_v<T, int>)
			{
				return std::stoi(file_content[0]);
			}
		}
};

extern RCFV_UTILITY_CLASS rcfv_utility;

#endif // RCFV_UTILITY
