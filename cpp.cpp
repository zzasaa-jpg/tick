#include "./File_Checking_Process/file_checking_process.hpp"
#include "./Conditional_Argument/conditional_argument.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// split the path into tokens and compare each token exactly.
int Linear_Search(string file_path, string target)
{
	ifstream inFile(file_path);
	if(!inFile)
	{
		cout << "File not found!\n";
		return -1;
	}

	string line;
	while(getline(inFile, line))
	{
		string token = "";

		for (size_t i = 0;  i <= line.size(); i++)
		{
			if(i == line.size() || line[i] == '/' || line[i] == '\\')
			{
				if(token == target)
				{
					inFile.close();
					return 1;
				}
				token = "";
			}else
			{
				token += line[i];
			}
		}
	}
	inFile.close();
	return -1;
}

int main(int agrc, char* argv[]){
	if (agrc == 1){
		//Normal execution
		/* To successfully execute the file checking process module,
		 * the dummy path is an empty path. */
		std::string Duplicate_path = "";
		file_check_prcs.File_checking_process(0, Duplicate_path);
		return 0;
	}

	//Arguments execution
	int result = condtnl_arg_cls.condition_of_arguments(argv, agrc);

	//IF unknown argumet, do NOT run timer
	if (result <= 0) return 0;

	return 0;
}

//g++ cpp.cpp ./All_file_names/All_file_names.cpp ./Program_boot/program_boot.cpp ./File_operations/file_operations.cpp ./Write_TT/write_tt.cpp ./File_Checking_Process/file_checking_process.cpp ./Conditional_Argument/conditional_argument.cpp ./Utility/RMR_Utility/RMR.cpp ./Utility/RCFV_Utility/RCFV_Utility.cpp ./Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.cpp ./Utility/Exists_Path_Utility/Exists_path.cpp -o cpp
