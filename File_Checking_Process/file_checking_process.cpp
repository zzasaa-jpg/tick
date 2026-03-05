#include "./file_checking_process.hpp"
#include "../All_file_names/All_file_names.hpp"
#include "../Program_boot/program_boot.hpp"
#include "../File_Operations/file_operations.hpp"

#include <vector>
#include <utility>
#include <string>

File_checking_process_class file_check_prcs;
File_checking_process_class::File_checking_process_class(){};

//Checking the files exists or no!----------------------------------
std::pair<int, std::vector<std::string>> Checking_file_exists() {
	std::vector<std::string> File_Names_ = AFNs_class.get_all_file_names();
	std::vector<std::string> Missing_Files_;
    	bool all_exist = true;

	for (const auto& i : File_Names_) {
		std::ifstream file(i);
	        if (!file.is_open()) {
			Missing_Files_.push_back(i);
			all_exist = false;
	        }
    	}
	return {all_exist ? 1 : 0, Missing_Files_};
}
//------------------------------------------------------------------

//Fils checking process---------------------------------------------
void File_checking_process_class::File_checking_process()
{
	auto status = Checking_file_exists();

	if (status.first) {
		prgm_boot.Program_Entry();
	} else{
		/*Missing files automatic generate after than 'Program_Entry'
	 	*execute*/
		std::vector<std::string> missingFiles = status.second;
		if(!missingFiles.empty()){
			for (const auto& file : missingFiles){
				const std::string directory_content = "default_path = ...";
				if(file == "directory.txt")
				{
					std::cout << "Create File: " << file << std::endl;
					file_oprs.write_file("directory.txt", directory_content + "\n");
				} else 
				{
					std::cout << "Create File: " << file << std::endl;
					file_oprs.write_file(file, 0);
				}
			}
		}
		prgm_boot.Program_Entry();
		//-----------------------------------------------------------
	}
}
//------------------------------------------------------------------
