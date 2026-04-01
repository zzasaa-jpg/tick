#include "./file_checking_process.hpp"
#include "../All_file_names/All_file_names.hpp"
#include "../Program_boot/program_boot.hpp"
#include "../File_Operations/file_operations.hpp"
#include "../Utility/RCFV_Utility/RCFV_Utility.hpp"
#include "../Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.hpp"

#include <vector>
#include <utility>
#include <string>
#include <filesystem>

File_checking_process_class file_check_prcs;
File_checking_process_class::File_checking_process_class(){};

std::string File_checking_process_class::directory_content()
{
	const char* directory_content_str = "default_path = ... - 0";
	return directory_content_str;
}

//Checking the files exists or no!----------------------------------
std::pair<int, std::vector<std::string>> Checking_file_exists(std::string& du_flag_path) {
	std::vector<std::string> File_Names_ = AFNs_class.get_all_file_names(), Missing_Files_Vector;
    	bool all_exist = true;

	for (const auto& i : File_Names_) {
		std::ifstream file(du_flag_path + "/" + i);
	        if (!file.is_open()) {
			Missing_Files_Vector.push_back(i);
			all_exist = false;
	        }
    	}
	return {all_exist ? 1 : 0, Missing_Files_Vector};
}
//------------------------------------------------------------------

// Generate missing files function for default and user path mode---
void generate_missing_files(int status_first, std::vector<std::string>& status_second, int du_flag, std::string& du_flag_path, std::string& path_key)
{
	if (status_first)
	{
		prgm_boot.Program_Entry(du_flag, du_flag_path, path_key);
	} else
	{
		/* Missing files automatic generate after than 'Program_Entry'
		* execute. */
		std::vector<std::string> missingFiles = status_second;
		if(!missingFiles.empty())
		{
			for (const auto& file : missingFiles)
			{
				std::cout << "Create File: " << du_flag_path << "/" << file << std::endl;
				file_oprs.write_file(du_flag_path + "/" + file, 0);
			}
		}
		prgm_boot.Program_Entry(du_flag, du_flag_path, path_key);
		//-----------------------------------------------------------
	}
}
//-------------------------------------------------------------------

//Files checking process---------------------------------------------
void File_checking_process_class::File_checking_process(int du_flag, std::string& du_flag_path, std::string& path_key)
{
	if(std::filesystem::exists("directory.txt"))
	{
		/* If du_flag is true than did not call the default path.
		 * Directly executing the generate_missing_files function
		 * via user path. */

		std::cout << "[[" << du_flag << "]]\n";
		if (du_flag)
		{
			auto status = Checking_file_exists(du_flag_path);
			generate_missing_files(status.first, status.second, du_flag, du_flag_path, path_key);
			return;
		}

		// Read the directory.txt file for default path ------------
		std::string file_content = rcfv_utility.Read_content_from_vector<std::string>("directory.txt");
		//----------------------------------------------------------

		// Checking the default path is exists or no ---------------
		int res = file_content.find("...");
		if (res != std::string::npos)
		{
			std::cout << "Set the Default Path!\n";
			std::cout << "Checkout cpp.exe help\n";
			return;
		}
		//----------------------------------------------------------

		else
		{
			// Extract the default path ------------------------
			std::string default_path = default_path_utility.default_path(file_content);
			//--------------------------------------------------

			/* Executing the generate_missing_files function via
			 * default path. */
			auto status = Checking_file_exists(default_path);
			generate_missing_files(status.first, status.second, du_flag, default_path, path_key);
			//--------------------------------------------------
		}
	}
	else
	{
		// First init the directory.txt file for program boot ------
		std::ifstream file("directory.txt");
		if(!file.is_open())
		{
			std::cout << "Create File: directory.txt" << std::endl;
			file_oprs.write_file("directory.txt", directory_content());
		}
		//----------------------------------------------------------
	}
}
//------------------------------------------------------------------
