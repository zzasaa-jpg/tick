#include "./conditional_argument.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../File_Checking_Process/file_checking_process.hpp"
#include "../All_file_names/All_file_names.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.hpp"
#include "../Utility/Exists_Path_Utility/Exists_path.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

Conditional_Argument_Class condtnl_arg_cls;
Conditional_Argument_Class::Conditional_Argument_Class(){};

//Condition of arguments function-----------------------------------
int Conditional_Argument_Class::condition_of_arguments(char* argv[], int argc)
{
	std::string arg = argv[1];
	//Normalize
	transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

	if (arg == "status")
	{
		int running = rcfv_utility.Read_content_from_vector<int>("bool.txt");
		std::cout << running << std::endl;
		return 1;
	} else if(arg == "clear" || arg == "reset")
	{
		std::vector<std::string> Clearing_Files = AFNs_class.get_all_file_names();
		const std::string directory_content = "default_path = ...";
		for (auto& file : Clearing_Files)
		{
			if(file == "directory.txt")
			{
				file_oprs.write_file("directory.txt", directory_content);
				std::cout << "File Cleared: " << file << std::endl;
			} else
			{
				std::string file_content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");
				std::string default_path = default_path_utility.default_path(file_content);

				file_oprs.write_file(default_path + "/" + file, 0);
				std::cout << "File Cleared: " << default_path << "/" << file << std::endl;
			}
		}
		return 1;
	} else if(arg == "help")
	{
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
		std::string default_path = argv[2];

		if(!std::filesystem::exists("C://Users/zzsdr/Desktop/tick/directory.txt"))
		{
			std::cout << "directory.txt file not found![Default arg]\n";
			return -1;
		}

		if(!std::filesystem::exists(default_path))
		{
			std::cout << "Path does not exist![Default arg]" << std::endl;
			return -1;
		}

		if(exists_path_class.exists_path("C://Users/zzsdr/Desktop/tick/directory.txt", default_path))
		{
			std::cout << "Path is already written!!\n";
			return -1;
		}

		rmr_utility.RMR("C://Users/zzsdr/Desktop/tick/directory.txt", "...", default_path);
		return 0;
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
		}

		std::string new_path = argv[2];

		if(!std::filesystem::exists("C://Users/zzsdr/Desktop/tick/directory.txt"))
		{
			std::cout << "directory.txt file not found![New arg]\n";
			return -1;
		}

		if(!std::filesystem::exists(new_path))
		{
			std::cout << "Path does not exists![New arg]\n";
			return -1;
		}

		if(exists_path_class.exists_path("C://Users/zzsdr/Desktop/tick/directory.txt", new_path))
		{
			std::cout << "Path is already written!\n";
			return -1;
		}

		file_oprs.append_file("C://Users/zzsdr/Desktop/tick/directory.txt", new_path + " - 0\n");
		file_check_prcs.File_checking_process(2, new_path);
		return 0;
	}
	else 
	{
		std::cout << "Unknown argument: " << arg << std::endl;
		std::cout << "Use: cpp.exe help\n";
		return -1;
	}
}
//------------------------------------------------------------------
