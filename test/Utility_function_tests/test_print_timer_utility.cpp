#include "../../src/Utility/Print_Timer_Utility/Print_Timer.hpp"
#include "../../src/File_Operations/file_operations.hpp"

#include <string>
#include <iostream>

int main()
{
	// seconds converting formatting time
	long long elapsed_seconds = 1774898890 - 1774617731;
	std::string fileName = "./Testing_txt_files/test6.txt";

	if(elapsed_seconds < 0) { std::cout << -1 << std::endl; return -1; }
	std::string formatted_time = print_timer_utility.format_time_ostring_stream(elapsed_seconds);
	file_oprs.write_file(fileName, formatted_time);

	std::cout << "Test passed\n";
	return 0;
}
