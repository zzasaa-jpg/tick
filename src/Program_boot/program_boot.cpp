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
	time_t time_now = time(0);
	file_oprs.write_file(file_path, time_now);
}
//------------------------------------------------------------------

std::string decide_default_or_user_path(int du_flag, std::string& du_flag_path, std::string file_path)
{
	return du_flag == 1 ? du_flag_path + file_path : condtnl_arg_cls.get_default_path() + file_path;
}

void User_path_timer_active_status_change(int du_flag, std::string& target, std::string& put_value, std::string& path_key)
{
	if(du_flag != 1)
	{
		rmr_utility.RMR("directory.txt", target, put_value, "default_path");
	} else
	{
		rmr_utility.RMR("directory.txt", target, put_value, path_key);
	}
}

void Program_boot::Program_Entry(int du_flag, std::string& du_flag_path, std::string& path_key)
{
	std::cout << du_flag << du_flag_path << std::endl;
	std::string bool_txt_file_content = decide_default_or_user_path(du_flag, du_flag_path, "/bool.txt");
	std::cout << bool_txt_file_content << std::endl;
	//Bool value read-------------------------------------------
	int bool_value;
	std::vector<std::string> file_content = file_oprs.read_file(bool_txt_file_content);
	for(const auto& content : file_content)
	{
		bool_value = content[0] - '0';
	}
	//----------------------------------------------------------

	//----------------------------------------------------------
	if (bool_value == false){
		//Store the current time inside t1.txt and toggle the bool value
		std::string t1_txt_file_content = decide_default_or_user_path(du_flag, du_flag_path, "/t1.txt");
		get_Seconds(t1_txt_file_content);
		std::string target = "0", put_value = "1";
		User_path_timer_active_status_change(du_flag, target, put_value, path_key);
		std::string bool_txt_file_content = decide_default_or_user_path(du_flag, du_flag_path, "/bool.txt");
		file_oprs.write_file(bool_txt_file_content, 1);
	}else {
		/*Store the finished time inside t2.txt and toggle the bool value
		 *and Write the Total Time*/
		std::string t2_txt_file_content = decide_default_or_user_path(du_flag, du_flag_path, "/t2.txt");
		get_Seconds(t2_txt_file_content);
		std::string target = "1", put_value = "0";
		User_path_timer_active_status_change(du_flag, target, put_value, path_key);
		file_oprs.write_file(bool_txt_file_content, 0);
		wrt_tt.Write_total_time(du_flag, du_flag_path);
	}
	//----------------------------------------------------------
}

