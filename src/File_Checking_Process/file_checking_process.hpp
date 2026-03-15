#ifndef FILE_CHECKING_PROCESS_HPP
#define FILE_CHECKING_PROCESS_HPP

#include <string>

class File_checking_process_class{
	public:
		File_checking_process_class();
		void File_checking_process(int du_flag, std::string& path_, std::string& key);
};

extern File_checking_process_class file_check_prcs;

#endif // FILE_CHECKING_PROCESS_HPP
