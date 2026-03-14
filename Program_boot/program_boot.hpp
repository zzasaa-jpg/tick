#ifndef PROGRAM_BOOT
#define PROGRAM_BOOT

#include <string>

class Program_boot{
	public:
		Program_boot();
		void Program_Entry(int du_flag, std::string& du_flag_path);
};

extern Program_boot prgm_boot;
#endif // PROGRAM_BOOT
