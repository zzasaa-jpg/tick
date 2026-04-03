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

			// Handle string return type ------------------------------------
			if constexpr (std::is_same_v<T, std::string>)
			{
				std::string str_value;
				for(const auto& content : file_content)
				{
					str_value += content + "\n";
				}
				return str_value;
			}

			// Handle all integer types (int, long, long long etc.) ---------
			else if constexpr (std::is_integral_v<T>)
			{
				if(file_content.empty())
				{
					std::cout << "File is empty.[RCFV UTILITY]: " << file_path <<"\n";
					return -1;
				}
				try
				{
					return static_cast<T>(std::stoll(file_content[0]));
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
			// Unsupported type protection ----------------------------------
			else
			{
				static_assert(!sizeof(T), "Unsupported type used in [RCFV UTILITY]");
			}
		}
};

extern RCFV_UTILITY_CLASS rcfv_utility;

#endif // RCFV_UTILITY
