#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class file_operations{
	public:
		file_operations();
		template<typename T>
		void write_file(const std::string& file_path, const T& value)
		{
			std::ofstream write_file_stream(file_path);
			if(!write_file_stream)
			{
				std::cout << "File not found![File oprs write]\n";
				return;
			}
			write_file_stream << value << std::endl;
			write_file_stream.close();
		}

		std::vector<std::string> read_file(const std::string& file_path);

		template<typename T>
		void append_file(const std::string& file_path, const T& value)
		{
			std::ofstream append_file_stream(file_path, std::ios::app);
			if(!append_file_stream)
			{
				std::cout << "File not found![File oprs append]\n";
			}
			append_file_stream << value;
			append_file_stream.close();
		}
};

extern file_operations file_oprs;

#endif // FILE_OPERATIONS
