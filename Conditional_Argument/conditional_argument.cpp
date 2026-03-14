#include "./conditional_argument.hpp"
#include "../Program_boot/program_boot.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../File_Checking_Process/file_checking_process.hpp"
#include "../All_file_names/All_file_names.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.hpp"
#include "../Utility/Exists_Path_Utility/Exists_path.hpp"
#include "../Utility/LOAT_Utility/LOAT.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

Conditional_Argument_Class condtnl_arg_cls;
Conditional_Argument_Class::Conditional_Argument_Class(){};

// Helper functions ---------------------------------------------------------------------------
bool Conditional_Argument_Class::path_exists(const std::string& path, const std::string& error)
{
    if(!std::filesystem::exists(path))
    {
        std::cout << error << std::endl;
        return false;
    }
    return true;
}

int Conditional_Argument_Class::read_status(const std::string& path)
{
    return rcfv_utility.Read_content_from_vector<int>(path + "/bool.txt");
}

std::string Conditional_Argument_Class::get_default_path()
{
    std::string content =
        rcfv_utility.Read_content_from_vector<std::string>("directory.txt");

    return default_path_utility.default_path(content);
}
// --------------------------------------------------------------------------------------------

// Condition of arguments function-------------------------------------------------------------
int Conditional_Argument_Class::condition_of_arguments(char* argv[], int argc)
{
	std::string arg = argv[1];
	//Normalize
	transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

	// Checking the directory.txt file ---------------------------------
	std::string error_1 = "Directory.txt file does not exist! [arg]";
	if(!path_exists("directory.txt", error_1)) return -1;

	if (arg == "status")
	{
		// User path mode ---------------------------------------------
		if(argc > 2)
		{
			std::string user_path = argv[2];
			std::string error = "Path does not exist! [Status arg]";
			if(!path_exists(user_path, error)) return -1;

			std::cout << read_status(user_path) << std::endl;
			return 1;
		}

		// Checking whether default path is not set than return -1
		if(condtnl_arg_cls.get_default_path() == "...\n")
		{
			std::cout << "Set the default path! [Status arg]\n";
			return -1;
		}
		// Default path mode ------------------------------------------
		std::cout << read_status(condtnl_arg_cls.get_default_path()) << std::endl;
		return 1;
	} else if(arg == "clear" || arg == "reset")
	{
		std::vector<std::string> Clearing_Files = AFNs_class.get_all_file_names();
		const std::string directory_content = "default_path = ... - 0";

		std::string base_path;

		if(argc > 2)
		{
			// User path mode -------------------------------------
			base_path = argv[2];
			std::string error = "Path does not exist! [Clear/Reset arg]";
			if(!path_exists(base_path, error)) return -1;

			int running = read_status(base_path);
			std::cout << running << std::endl;
			if(running == -1) return -1;
		}
		else
		{
			// Default path mode ----------------------------------
			base_path = condtnl_arg_cls.get_default_path();

			// Checking whether default path is not set than return -1
			if(base_path == "...\n")
			{
				std::cout << "Set the default path! [Clear/Reset arg]\n";
				return -1;
			}
		}

		// If Program is active than terminate the clear/reset files --
		if(read_status(base_path) == 1) return -1;

		for (auto& file : Clearing_Files)
		{
			std::string full =  base_path + "/" + file;

			if(file == "directory.txt")
			{
				file_oprs.write_file(full, directory_content);
			} else
			{
				file_oprs.write_file(full, 0);
			}
			std::cout << "File Cleared: " << full << std::endl;
		}
		return 1;
	} else if(arg == "help")
	{
		std::cout << "Usage:\n";
		std::cout << "  cpp.exe             -> Start / Stop timer\n";
		std::cout << "  cpp.exe status      -> Show running status at default path\n";
		std::cout << "  cpp.exe clear       -> Reset all time data at default path\n";
		std::cout << "  cpp.exe default     -> Set default path\n";
		std::cout << "  cpp.exe new_        -> Set user path\n";
		std::cout << "  cpp.exe status path -> Show running status at user path\n";
		std::cout << "  cpp.exe clear path  -> Reset all time data at user path\n";
		std::cout << "  cpp.exe list        -> List of active timers\n";
		std::cout << "  cpp.exe help        -> Show this help\n";
		return 1;
	} else if(arg == "default")
	{
		if(argc < 3)
		{
			std::cout << "Default path is require!" << std::endl;
			return -1;
		}
		std::string default_path = argv[2];

		// Checking the directory.txt file ---------------------------------
		std::string error_1 = "Directory.txt file does not exist! [Default arg]";
		if(!path_exists("directory.txt", error_1)) return -1;

		// Checking the default_path is exists or no -----------------------
		std::string error_2 = "Path does not exist! [Default arg]";
		if(!path_exists(default_path, error_2)) return -1;

		// Checking whether a directory file contains a default path or not
		if(exists_path_class.exists_path("directory.txt", default_path))
		{
			std::cout << "Path is already written!!\n";
			return -1;
		}

		rmr_utility.RMR("directory.txt", "...", default_path, "default_path");
		std::string Duplicate_path = "", de = "default_path";
		file_check_prcs.File_checking_process(0, Duplicate_path, de);
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
		else if(argc < 4)
		{
			std::cout << "Path key is required!\n";
			return -1;
		}

		std::string new_path = argv[2];
		std::string path_key = argv[3];

		// Checking the directory.txt file ---------------------------------
		std::string error_1 = "Directory.txt file does not exist! [New arg]";
		if(!path_exists("directory.txt", error_1)) return -1;

		// Checking the new_path is exists or no ---------------------------
		std::string error_2 = "Path does not exist! [New arg]";
		if(!path_exists(new_path, error_2)) return -1;

		// Checking whether a directory file contains a new_path or not ----
		if(exists_path_class.exists_path("directory.txt", new_path))
		{
			std::cout << "Path is already written!\n";
			prgm_boot.Program_Entry(2, new_path, path_key);
			return -1;
		}

		file_oprs.append_file("directory.txt", path_key + " = " + new_path + " - 0\n");
		file_check_prcs.File_checking_process(2, new_path, path_key);
		return 0;
	}else if(arg == "list")
	{
		loat_utility.loat();
		return 1;
	}
	else 
	{
		std::cout << "Unknown argument: " << arg << std::endl;
		std::cout << "Use: cpp.exe help\n";
		return -1;
	}
}
//---------------------------------------------------------------------------------------------
