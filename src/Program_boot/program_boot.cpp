#include "./program_boot.hpp"
#include "../Conditional_Argument/conditional_argument.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Write_TT/write_tt.hpp"
#include "../Utility/RMR_Utility/RMR.hpp"
#include "../Utility/Decide_du_path_utility/decide_du_path.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

Program_boot prgm_boot;
Program_boot::Program_boot(){};
namespace Paths
{
    constexpr const char* bool_txt_path = "/bool.txt";
    constexpr const char* t1_txt_path   = "/t1.txt";
    constexpr const char* t2_txt_path   = "/t2.txt";
}

//Get-seconds-------------------------------------------------------
void get_Seconds(const std::string& file_path)
{
	time_t time_now = time(0);
	file_oprs.write_file(file_path, time_now);
}
//------------------------------------------------------------------

// Helper function for user path timer active status change according to du_flag
void User_path_timer_active_status_change(int du_flag, const std::string& target, const std::string& put_value, const std::string& path_key)
{
	if(du_flag != 1)
	{
		rmr_utility.RMR("directory.txt", target, put_value, "default_path");
	} else
	{
		rmr_utility.RMR("directory.txt", target, put_value, path_key);
	}
}
// -----------------------------------------------------------------

// Entry validation process that checks module readiness -----------
void Program_boot::Program_Entry(int du_flag, std::string& du_flag_path, std::string& path_key)
{
	std::cout << du_flag << du_flag_path << std::endl;
	std::string bool_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::bool_txt_path);
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
	std::string t1_txt_file_content, t2_txt_file_content, target, put_value;
	if (bool_value == false){
		// Store the current time inside t1.txt and toggle the bool value
		t1_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::t1_txt_path);
		get_Seconds(t1_txt_file_content);

		// du_flag according toggle the active status in directory file
		target = "0", put_value = "1";
		User_path_timer_active_status_change(du_flag, target, put_value, path_key);

		// bool.txt file status toggle
		file_oprs.write_file(bool_txt_file_content, 1);
	} else {
		/*Store the finished time inside t2.txt and toggle the bool value
		 *and Write the Total Time*/
		t2_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::t2_txt_path);
		get_Seconds(t2_txt_file_content);

		// du_flag according toggle the active status in directory file
		target = "1", put_value = "0";
		User_path_timer_active_status_change(du_flag, target, put_value, path_key);

		// bool.txt file status toggle
		file_oprs.write_file(bool_txt_file_content, 0);

		// Write total elapsed time
		wrt_tt.Write_total_time(du_flag, du_flag_path);
	}
	//----------------------------------------------------------
}

