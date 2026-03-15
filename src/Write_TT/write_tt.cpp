#include "./write_tt.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Conditional_Argument/conditional_argument.hpp"

#include <sstream>
#include <string>

Write_TT wrt_tt;
Write_TT::Write_TT(){};

/*cout_time_funtion for user saw the total and session time in one 
 * program cycle*/
void cout_time_fun(int seconds_, const std::string& mes){
	int hours = (seconds_ / 3600),
	    remainder = seconds_ % 3600,
	    minutes = remainder / 60,
	    seconds = remainder % 60;
	std::cout 
		<< mes
		<< (hours   < 10 ? "0" : "") << hours   << ":"
		<< (minutes < 10 ? "0" : "") << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds
		<< std::endl;
}
//------------------------------------------------------------------

std::string decide_default_or_user_path_(int du_flag, std::string& du_flag_path, std::string file_path)
{
	return du_flag == 2 ? du_flag_path + file_path : condtnl_arg_cls.get_default_path() + file_path;
}

//Write and calculate the Total time--------------------------------
void Write_TT::Write_total_time(int du_flag, std::string& du_flag_path)
{
	std::string t1_txt = decide_default_or_user_path_(du_flag, du_flag_path, "/t1.txt");
	std::string t2_txt = decide_default_or_user_path_(du_flag, du_flag_path, "/t2.txt");
	std::string tt_txt = decide_default_or_user_path_(du_flag, du_flag_path, "/tt.txt");
	std::string format_time_txt = decide_default_or_user_path_(du_flag, du_flag_path, "/format_time.txt");

	/*Read the t1 and t2 value store inside t1_value and t2_value
	 * varaibles inside*/
	int t1_value = rcfv_utility.Read_content_from_vector<int>(t1_txt),
	    t2_value = rcfv_utility.Read_content_from_vector<int>(t2_txt);
	//----------------------------------------------------------
	
	/*TT_time calclutaing and update the tt.txt file and format_
	  time.txt file*/
	if(t2_value < t1_value) t2_value += 24 * 3600;

	int Previous_stored_time = rcfv_utility.Read_content_from_vector<int>(tt_txt);
	int final_time = (t2_value - t1_value) + Previous_stored_time;
	file_oprs.write_file(tt_txt, final_time);

	int hours = (final_time / 3600),
	remainder = final_time % 3600,
	minutes = remainder / 60,
	seconds = remainder % 60;

	std::ostringstream oss;
	oss << (hours   < 10 ? "0" : "") << hours   << ":"
	    << (minutes < 10 ? "0" : "") << minutes << ":"
	    << (seconds < 10 ? "0" : "") << seconds;

	std::string format_time_string = oss.str();	
	file_oprs.write_file(format_time_txt, format_time_string);

	cout_time_fun(t2_value - t1_value, "Session Time: ");
	cout_time_fun(final_time, "Total Time: ");
	//----------------------------------------------------------
}
//------------------------------------------------------------------
