#ifndef RCFV_UTILITY
#define RCFV_UTILITY

#include "../../File_Operations/file_operations.hpp"
#include <string>
#include <vector>
#include <iostream>

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
					str_value += content + "\n";
				}
				return str_value;
			}
			else if constexpr (std::is_same_v<T, int>)
			{
				if(file_content.empty())
				{
					std::cout << "File is empty.[RCFV UTILITY]: " << file_path <<"\n";
					return -1;
				}
				try
				{
					return std::stoi(file_content[0]);
				}
				catch(const std::invalid_argument&)
				{
					std::cout << "Invalid number in file.[RCFV UTILITY]: " << file_path << "\n";
					return -1;
				}
				catch(const std::out_of_range&)
				{
					std::cout << "Number out of range in file.[RCFV UTILITY]: " << file_path << "\n";
					return -1;
				}
			}
		}
};

extern RCFV_UTILITY_CLASS rcfv_utility;

#endif // RCFV_UTILITY
