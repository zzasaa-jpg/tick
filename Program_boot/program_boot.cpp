#include "./program_boot.hpp"
#include "../File_operations/file_operations.hpp"
#include "../Write_TT/write_tt.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

Program_boot prgm_boot;
Program_boot::Program_boot(){};

//Get-seconds-------------------------------------------------------
void get_Seconds(const std::string& file_path, tm* ltm)
{
	int totalSeconds = 
		ltm-> tm_hour * 3600 +
		ltm-> tm_min * 60 +
		ltm-> tm_sec;
	file_oprs.write_file(file_path, totalSeconds);
}
//------------------------------------------------------------------

void Program_boot::Program_Entry()
{
	//Bool value read-------------------------------------------
	int bool_value;
	std::vector<std::string> file_content = file_oprs.read_file("bool.txt");
	for(const auto& content : file_content)
	{
		bool_value = content[0] - '0';
	}
	//----------------------------------------------------------

	//Time pointer initialization-------------------------------
	time_t now = time(0);
	tm *ltm = localtime(&now);
	//----------------------------------------------------------

	//----------------------------------------------------------
	if (bool_value == false){
		//Store the current time inside t1.txt and toggle the bool value
		get_Seconds("t1.txt", ltm);
		file_oprs.write_file("bool.txt", 1);
	}else {
		/*Store the finished time inside t2.txt and toggle the bool value
		 *and Write the Total Time*/
		get_Seconds("t2.txt", ltm);
		file_oprs.write_file("bool.txt", 0);
		wrt_tt.Write_total_time();
	}
	//----------------------------------------------------------
}

