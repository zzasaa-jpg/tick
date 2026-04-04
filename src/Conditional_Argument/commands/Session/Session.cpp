#include "./Session.hpp"
#include "../../conditional_argument.hpp"
#include "../../../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../../../Utility/Print_Timer_Utility/Print_Timer.hpp"

#include <iostream>

int Session(int argc, char* argv[])
{
	std::string base_path = "", error;
	if(argc > 2)
	{
		// User path mode -----------------------------------
		base_path = argv[2];

		// Checking the path is exists or no ----------------
		error = "Path does not exist! [Session arg]";
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
	time_t time_now = time(0);
	//-----------------------------------------------------------

	int time_1 = rcfv_utility.Read_content_from_vector<int>(base_path + "/t1.txt");
	std::cout << "Session Time: " <<print_timer_utility.print_timer(time_now - time_1) << std::endl;
	return 1;
}
