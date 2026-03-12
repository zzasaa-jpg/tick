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
			std::ofstream file(file_path);
			if(!file)
			{
				std::cout << "File not found![File oprs write]\n";
				return;
			}
			file << value;
			file.close();
		}

		std::vector<std::string> read_file(const std::string& file_path);

		template<typename T>
		void append_file(const std::string& file_path, const T& value)
		{
			std::ofstream file(file_path, std::ios::app);
			if(!file)
			{
				std::cout << "File not found![File oprs append]\n";
			}
			file << value;
		}
};

extern file_operations file_oprs;

#endif // FILE_OPERATIONS
