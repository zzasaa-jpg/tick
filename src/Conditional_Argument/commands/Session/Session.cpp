#include "./Session.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/RCFV_Utility/RCFV_Utility.hpp"

//Get-seconds--------------------------------------------------------
void get_Seconds(tm* ltm, int time_1)
{
	int totalSeconds = 
		ltm-> tm_hour * 3600 +
		ltm-> tm_min * 60 +
		ltm-> tm_sec;
	int session_time = totalSeconds - time_1;
	int hours = (session_time / 3600),
		    remainder = session_time % 3600,
		    minutes = remainder / 60,
		    seconds = remainder % 60;
	std::cout 
		<< "Session Time: "
		<< (hours   < 10 ? "0" : "") << hours   << ":"
		<< (minutes < 10 ? "0" : "") << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds
		<< std::endl;
}
//-------------------------------------------------------------------

int Session(int argc, char* argv[])
{
	std::string base_path = "";
	if(argc > 2)
	{
		// User path mode -----------------------------------
		base_path = argv[2];

		// Checking the path is exists or no ----------------
		std::string error = "Path does not exist! [Session arg]";
		if(!condtnl_arg_cls.path_exists(base_path, error)) return -1;

		// Reading the content of user path bool.txt --------
		int bool_txt = rcfv_utility.Read_content_from_vector<int>(base_path + "/bool.txt");

		// If file is not found on user path location just return
		if(bool_txt == -1) return -1;

		// File is found but timer is not active than print info
		if(bool_txt != 1)
		{
			std::cout << base_path << " -> Timer is not active!\n";
			return -1;
		}
	} else
	{
		// Default path mode --------------------------------
		base_path = condtnl_arg_cls.get_default_path();

		// Checking whether default path is not set than return -1
		if(base_path == "...")
		{
			std::cout << "Set the default path! [Session arg]\n";
			return -1;
		}

		// Reading the content of default path bool.txt -----
		int bool_txt = rcfv_utility.Read_content_from_vector<int>(base_path + "/bool.txt");

		// File is found but timer is not active than print info
		if(bool_txt != 1)
		{
			std::cout << base_path << " -> Timer is not active!\n";
			return -1;
		}
	}

	//Time pointer initialization--------------------------------
	time_t now = time(0);
	tm *ltm = localtime(&now);
	//-----------------------------------------------------------

	int time_1 = rcfv_utility.Read_content_from_vector<int>(base_path + "/t1.txt");
	get_Seconds(ltm, time_1);
	return 1;
}
