#ifndef WRITE_TT
#define WRITE_TT

#include <string>

class Write_TT{
	public:
		Write_TT();
		void Write_total_time(int du_flag, std::string& du_flag_path);
};

extern Write_TT wrt_tt;

#endif // WRITE_TT
