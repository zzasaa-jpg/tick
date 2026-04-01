#include "./write_tt.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Conditional_Argument/conditional_argument.hpp"
#include "../Utility/Print_Timer_Utility/Print_Timer.hpp"

#include <string>

Write_TT wrt_tt;
Write_TT::Write_TT(){};

std::string decide_default_or_user_path_(int du_flag, std::string& du_flag_path, std::string& file_path)
{
	return du_flag == 1 ? du_flag_path + file_path : condtnl_arg_cls.get_default_path() + file_path;
}

//Write and calculate the Total time--------------------------------
void Write_TT::Write_total_time(int du_flag, std::string& du_flag_path)
{
	std::string t1_txt_path = "/t1.txt", t2_txt_path ="/t2.txt", tt_txt_path ="/tt.txt",
		format_time_txt_path = "/format_time.txt", format_time_string,
		t1_txt_file_content = decide_default_or_user_path_(du_flag, du_flag_path, t1_txt_path),
		t2_txt_file_content = decide_default_or_user_path_(du_flag, du_flag_path, t2_txt_path),
		tt_txt_file_content = decide_default_or_user_path_(du_flag, du_flag_path, tt_txt_path),
		format_time_txt_file_content = decide_default_or_user_path_(du_flag, du_flag_path, format_time_txt_path);

	long long t1_value = rcfv_utility.Read_content_from_vector<int>(t1_txt_file_content),
	    t2_value = rcfv_utility.Read_content_from_vector<int>(t2_txt_file_content),
	    Previous_stored_time = rcfv_utility.Read_content_from_vector<int>(tt_txt_file_content),
	    final_time = (t2_value - t1_value) + Previous_stored_time;
	file_oprs.write_file(tt_txt_file_content, final_time);

	format_time_string = print_timer_utility.format_time_ostring_stream(final_time);
	file_oprs.write_file(format_time_txt_file_content, format_time_string);

	print_timer_utility.print_timer(t2_value - t1_value, "Session Time: ");
	print_timer_utility.print_timer(final_time, "Total Time: ");
	//----------------------------------------------------------
}
//------------------------------------------------------------------
