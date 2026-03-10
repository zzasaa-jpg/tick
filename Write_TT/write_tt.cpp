#include "./write_tt.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"

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

//Write and calculate the Total time--------------------------------
void Write_TT::Write_total_time()
{
	/*Read the t1 and t2 value store inside t1_value and t2_value
	 * varaibles inside*/
	int t1_value = rcfv_utility.Read_content_from_vector<int>("t1.txt"),
	    t2_value = rcfv_utility.Read_content_from_vector<int>("t2.txt");
	//----------------------------------------------------------
	
	/*TT_time calclutaing and update the tt.txt file and format_
	  time.txt file*/
	if(t2_value < t1_value) t2_value += 24 * 3600;

	int Previous_stored_time = rcfv_utility.Read_content_from_vector<int>("tt.txt");
	int final_time = (t2_value - t1_value) + Previous_stored_time;
	file_oprs.write_file("tt.txt", final_time);

	int hours = (final_time / 3600),
	remainder = final_time % 3600,
	minutes = remainder / 60,
	seconds = remainder % 60;

	std::ostringstream oss;
	oss << (hours   < 10 ? "0" : "") << hours   << ":"
	    << (minutes < 10 ? "0" : "") << minutes << ":"
	    << (seconds < 10 ? "0" : "") << seconds;

	std::string format_time_string = oss.str();	
	file_oprs.write_file("format_time.txt", format_time_string);

	cout_time_fun(t2_value - t1_value, "Session Time: ");
	cout_time_fun(final_time, "Total Time: ");
	//----------------------------------------------------------
}
//------------------------------------------------------------------
