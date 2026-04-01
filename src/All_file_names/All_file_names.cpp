#include"./All_file_names.hpp"

#include <vector>
#include <string>

All_file_names_class AFNs_class;

// All required files stores in vector. New file can be easily removed and added for future need.
All_file_names_class::All_file_names_class()
{
	std::vector<std::string> file_names = {
		"t1.txt",
		"t2.txt",
		"tt.txt",
		"bool.txt",
		"format_time.txt",
	};

	for(const auto& file_name : file_names)
	{	
		All_file_names_vector.push_back(file_name);
	}
}
// --------------------------------------------------------------------------------------

// Return a vector of all file names to access the file names to run the program --------
std::vector<std::string>& All_file_names_class::get_all_file_names()
{
	return All_file_names_vector;
}
// --------------------------------------------------------------------------------------
