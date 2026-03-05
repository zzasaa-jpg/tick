#include "./conditional_argument.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../All_file_names/All_file_names.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

Conditional_Argument_Class condtnl_arg_cls;
Conditional_Argument_Class::Conditional_Argument_Class(){};

int Read_content_from_vector1(const std::string& file_path)
{
	int value;
	std::vector<std::string> file_content = file_oprs.read_file(file_path);
	for(const auto& content : file_content)
	{
		value = std::stoi(content);
	}
	return value;
}

//Condition of arguments function-----------------------------------
int Conditional_Argument_Class::condition_of_arguments(char* argv[], int argc)
{
	std::string arg = argv[1];
	//Normalize
	transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

	if (arg == "status"){
		int running = Read_content_from_vector1("bool.txt");
		std::cout << running << std::endl;
		return 1;
	} else if(arg == "clear" || arg == "reset"){
		std::vector<std::string> Clearing_Files = AFNs_class.get_all_file_names();
		const std::string directory_content = "default_path = ...";
		for (auto& file : Clearing_Files){
			if(file == "directory.txt")
			{
				file_oprs.write_file("directory.txt", directory_content);
				std::cout << "File Cleared: " << file << std::endl;
			} else
			{
				file_oprs.write_file(file, 0);
				std::cout << "File Cleared: " << file << std::endl;
			}
		}
		return 1;
	} else if(arg == "help"){
		std::cout << "Usage:\n";
		std::cout << "  cpp.exe        -> Start / Stop timer\n";
		std::cout << "  cpp.exe status -> Show running status\n";
		std::cout << "  cpp.exe clear  -> Reset all time data\n";
		std::cout << "  cpp.exe help   -> Show this help\n";
		return 1;
	} else if(arg == "default")
	{
		if(argc < 3)
		{
			std::cout << "Default path is require!" << std::endl;
			return -1;
		}
		else
		{
			std::string default_path = argv[2];
			if(!std::filesystem::exists(default_path))
			{
				std::cout << "Path does not exist!" << std::endl;
				return -1;
			}
			rmr_utility.RMR("C://Users/zzsdr/Desktop/tick/directory.txt", "...", default_path);
			return 0;
		}
	} else if(arg == "search")
	{
		if(argc < 3)
		{
			std::cout << "Search path is require!\n";
			return -1;
		}
		else
		{
			std::string search_path = argv[2];
			//std::cout << Linear_Search("./directory.txt", search_path);
			return 0;
		}
	}else if (arg == "new_")
	{
		if(argc < 3)
		{
			std::cout << "New path is required!\n";
			return -1;
		}else
		{
			std::string new_path = argv[2];
			file_oprs.append_file("C://Users/zzsdr/Desktop/tick/directory.txt", new_path + " - 0\n");
			return 0;
		}
	}
	else 
	{
		std::cout << "Unknown argument: " << arg << std::endl;
		std::cout << "Use: cpp.exe help\n";
		return -1;
	}
}
//------------------------------------------------------------------
