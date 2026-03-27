#include "./program_boot.hpp"
#include "../Conditional_Argument/conditional_argument.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Write_TT/write_tt.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

Program_boot prgm_boot;
Program_boot::Program_boot(){};

//Get-seconds-------------------------------------------------------
void get_Seconds(const std::string& file_path)
{
	time_t now = time(0);
	file_oprs.write_file(file_path, now);
}
//------------------------------------------------------------------

std::string decide_default_or_user_path(int du_flag, std::string& du_flag_path, std::string file_path)
{
	return du_flag == 2 ? du_flag_path + file_path : condtnl_arg_cls.get_default_path() + file_path;
}


void Program_boot::Program_Entry(int du_flag, std::string& du_flag_path, std::string& key)
{
	std::cout << du_flag << du_flag_path << std::endl;
	std::string bool_txt = decide_default_or_user_path(du_flag, du_flag_path, "/bool.txt");
	std::cout << bool_txt << std::endl;
	//Bool value read-------------------------------------------
	int bool_value;
	std::vector<std::string> file_content = file_oprs.read_file(bool_txt);
	for(const auto& content : file_content)
	{
		bool_value = content[0] - '0';
	}
	//----------------------------------------------------------

	//----------------------------------------------------------
	if (bool_value == false){
		//Store the current time inside t1.txt and toggle the bool value
		std::string t1_txt = decide_default_or_user_path(du_flag, du_flag_path, "/t1.txt");
		get_Seconds(t1_txt);
		if(du_flag != 2)
		{
			rmr_utility.RMR("directory.txt", "0", "1", "default_path");
		} else
		{
			rmr_utility.RMR("directory.txt", "0", "1", key);
		}
		std::string bool_txt = decide_default_or_user_path(du_flag, du_flag_path, "/bool.txt");
		file_oprs.write_file(bool_txt, 1);
	}else {
		/*Store the finished time inside t2.txt and toggle the bool value
		 *and Write the Total Time*/
		std::string t2_txt = decide_default_or_user_path(du_flag, du_flag_path, "/t2.txt");
		get_Seconds(t2_txt);
		if(du_flag != 2)
		{
			rmr_utility.RMR("directory.txt", "1", "0", "default_path");
		} else
		{
			rmr_utility.RMR("directory.txt", "1", "0", key);
		}
		file_oprs.write_file(bool_txt, 0);
		wrt_tt.Write_total_time(du_flag, du_flag_path);
	}
	//----------------------------------------------------------
}

