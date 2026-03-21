#include "./conditional_argument.hpp"
#include "./commands/Status/status.hpp"
#include "./commands/Clear/Clear.hpp"
#include "./commands/Help/Help.hpp"
#include "./commands/Default/Default.hpp"
#include "./commands/Search/Search.hpp"
#include "./commands/New/New.hpp"
#include "./commands/List/List.hpp"
#include "./commands/Session/Session.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.hpp"

#include <string>
#include <algorithm>
#include <filesystem>

Conditional_Argument_Class condtnl_arg_cls;
Conditional_Argument_Class::Conditional_Argument_Class(){};

// Helper functions ---------------------------------------------------------------------------
bool Conditional_Argument_Class::Is_directory(const std::string& path, const std::string& error)
{
	if(!std::filesystem::is_directory(path))
	{
		std::cout << path << error << std::endl;
		return false;
	}
	return true;
}


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
	// Normalize argument ----------------------------------------------
	transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

	// Program help command and does not need a directory.txt file -----
	if(arg == "help") return Help();

	// Checking the directory.txt file ---------------------------------
	std::string error_1 = "Directory.txt file does not exist! [arg]";
	if(!path_exists("directory.txt", error_1)) return -1;

	if (arg == "status") return Status(argc, argv);
	else if(arg == "clear" || arg == "reset") return Clear(argc, argv);
	else if(arg == "default") return Default(argc, argv);
	else if(arg == "search") return Search(argc, argv);
	else if (arg == "new_") return New(argc, argv);
	else if(arg == "list") return List();
	else if(arg == "session") return Session(argc, argv);
	else 
	{
		std::cout << "Unknown argument: " << arg << std::endl;
		std::cout << "Use: cpp.exe help\n";
		return -1;
	}
}
//---------------------------------------------------------------------------------------------
