#include "./write_tt.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Conditional_Argument/conditional_argument.hpp"
#include "../Utility/Print_Timer_Utility/Print_Timer.hpp"
#include "../Utility/Decide_du_path_utility/decide_du_path.hpp"

#include <string>

Write_TT wrt_tt;
Write_TT::Write_TT(){};
namespace Paths
{
	constexpr const char* t1_txt_path = "/t1.txt";
	constexpr const char* t2_txt_path = "/t2.txt";
	constexpr const char* tt_txt_path = "/tt.txt";
	constexpr const char* format_time_txt_path = "/format_time.txt";
}

//Write and calculate the Total time----------------------------------
void Write_TT::Write_total_time(int du_flag, const std::string& du_flag_path)
{
	// String declaration ---------------------------------------
	std::string format_time_string,
		t1_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::t1_txt_path),
		t2_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::t2_txt_path),
		tt_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::tt_txt_path),
		format_time_txt_file_content = decide_du_path_class.decide_du_path(du_flag, du_flag_path, Paths::format_time_txt_path);

	// long long int declaration --------------------------------
	long long
		t1_value = rcfv_utility.Read_content_from_vector<long long>(t1_txt_file_content),
		t2_value = rcfv_utility.Read_content_from_vector<long long>(t2_txt_file_content),
		Previous_stored_time = rcfv_utility.Read_content_from_vector<long long>(tt_txt_file_content),
		final_time = (t2_value - t1_value) + Previous_stored_time;

	// Write the final elapsed seconds --------------------------
	file_oprs.write_file(tt_txt_file_content, final_time);

	// Elapsed seconds convert to readable format time ----------
	format_time_string = print_timer_utility.format_time_ostring_stream(final_time);
	file_oprs.write_file(format_time_txt_file_content, format_time_string);

	// Print session and total timer of one program cycle -------
	print_timer_utility.print_timer(t2_value - t1_value, "Session Time: ");
	print_timer_utility.print_timer(final_time, "Total Time: ");
	//------------------------------------------------------------
}
//--------------------------------------------------------------------
