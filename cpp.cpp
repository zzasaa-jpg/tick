#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//All files name----------------------------------------------------
vector<string> All_Files_Name(){
	return {
		"t1.txt",
		"t2.txt",
		"tt.txt",
		"bool.txt",
		"format_time.txt"
    };
}
//------------------------------------------------------------------

//Reading, Writing file helper function's---------------------------
//Writing file------------------------------------------------------
void Write_File(string File_Name, int _value){
	ofstream file(File_Name);
	if (!file) {
		return;
	}
	file << _value;
	file.close();
}
//------------------------------------------------------------------

//Reading file------------------------------------------------------
int Read_File(string File_Name){
	ifstream file(File_Name);
	if (!file) {
		return 0;
	}
	int file_content = 0;
	file >> file_content;
	file.close();
	return file_content;
}
//------------------------------------------------------------------

//Get-seconds-------------------------------------------------------
void get_Seconds(string file_name, tm* ltm){
	int totalSeconds = 
		ltm-> tm_hour * 3600 +
		ltm-> tm_min * 60 +
		ltm-> tm_sec;
	Write_File(file_name, totalSeconds);
}
//------------------------------------------------------------------

/*cout_time_funtion for user saw the total and session time in one 
 * program cycle*/
void cout_time_fun(int seconds_, string mes){
	int hours = (seconds_ / 3600),
	remainder = seconds_ % 3600,
	minutes = remainder / 60,
	seconds = remainder % 60;
	cout 
		<< mes
		<< (hours   < 10 ? "0" : "") << hours   << ":"
		<< (minutes < 10 ? "0" : "") << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds
		<< endl;
}
//------------------------------------------------------------------

//Write and calculate the Total time--------------------------------
void Write_TT(){
	/*Read the t1 and t2 value store inside t1_value and t2_value
	 * varaibles inside*/
	int t1_value = Read_File("t1.txt"), t2_value = Read_File("t2.txt");
	//----------------------------------------------------------
	
	/*TT_time calclutaing and update the tt.txt file and format_
	  time.txt file*/
	if(t2_value < t1_value) t2_value += 24 * 3600;

	int Previous_stored_time = Read_File("tt.txt");
	int final_time = (t2_value - t1_value) + Previous_stored_time;
	Write_File("tt.txt", final_time);

	int hours = (final_time / 3600),
	remainder = final_time % 3600,
	minutes = remainder / 60,
	seconds = remainder % 60;

	ofstream file("format_time.txt");
	if (!file) {
		return;
	}
	file 
		<< (hours   < 10 ? "0" : "") << hours   << ":"
		<< (minutes < 10 ? "0" : "") << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds
		<< endl;
	file.close();
	cout_time_fun(t2_value - t1_value, "Session Time: ");
	cout_time_fun(final_time, "Total Time: ");
	//----------------------------------------------------------
}
//------------------------------------------------------------------

//Checking the files exists or no!----------------------------------
pair<int, vector<string>> Checking_file_exists() {
    vector<string> File_Names_ = All_Files_Name();
    vector<string> Missing_Files_;
    bool all_exist = true;

    for (const auto& i : File_Names_) {
        ifstream file(i);
        if (!file.is_open()) {
		Missing_Files_.push_back(i);
		all_exist = false;
        }
    }
    return {all_exist ? 1 : 0, Missing_Files_};
}
//------------------------------------------------------------------

//Program_Entry point or function-----------------------------------
void Program_Entry(){
	//Bool value read-------------------------------------------
	int bool_value = Read_File("bool.txt");
	//----------------------------------------------------------

	//Time pointer initialization-------------------------------
	time_t now = time(0);
	tm *ltm = localtime(&now);
	//----------------------------------------------------------

	//----------------------------------------------------------
	if (bool_value == false){
		//Store the current time inside t1.txt and toggle the bool value
		get_Seconds("t1.txt", ltm);
		Write_File("bool.txt", 1);
	}else {
		/*Store the finished time inside t2.txt and toggle the bool value
		 *and Write the Total Time*/
		get_Seconds("t2.txt", ltm);
		Write_File("bool.txt", 0);
		Write_TT();
	}
	//----------------------------------------------------------
}
//------------------------------------------------------------------

//Fils checking process---------------------------------------------
void File_checking_process(){
	auto status = Checking_file_exists();

	if (status.first) {
		Program_Entry();
	} else{
		/*Missing files automatic generate after than 'Program_Entry'
	 	*execute*/
		vector<string> missingFiles = status.second;
		if(!missingFiles.empty()){
			for (const auto& file : missingFiles){
				cout << "Create File: " << file << endl;
				Write_File(file, 0);
			}
		}
		Program_Entry();
		//-----------------------------------------------------------
	}
}
//------------------------------------------------------------------

//Condition of arguments function-----------------------------------
int condition_of_arguments(string arg){
	//Normalize
	transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

	if (arg == "status"){
		int running = Read_File("bool.txt");
		cout << running << endl;
		return 1;
	} else if(arg == "clear" || arg == "reset"){
		vector<string> Clearing_Files = All_Files_Name();
		for (auto& file : Clearing_Files){
			Write_File(file, 0);
			cout << "File Cleared: " << file << endl;
		}
		return 1;
	} else if(arg == "help"){
		cout << "Usage:\n";
		cout << "  cpp.exe        -> Start / Stop timer\n";
		cout << "  cpp.exe status -> Show running status\n";
		cout << "  cpp.exe clear  -> Reset all time data\n";
		cout << "  cpp.exe help   -> Show this help\n";
		return 1;
	} else {
		cout << "Unknown argument: " << arg << endl;
		cout << "Use: cpp.exe help\n";
		return -1;
	}
}
//------------------------------------------------------------------

int main(int agrc, char* argv[]){
	if (agrc == 1){
		//Normal execution
		File_checking_process();
		return 0;
	}

	//Arguments execution
	string arg = argv[1];
	int result = condition_of_arguments(arg);

	//IF unknown argumet, do NOT run timer
	if (result <= 0) return 0;

	return 0;
}
