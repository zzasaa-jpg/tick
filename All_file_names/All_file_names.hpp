#ifndef ALL_FILE_NAMES
#define ALL_FILE_NAMES

#include <vector>
#include <string>

class All_file_names_class{
	public:
		All_file_names_class();
		std::vector<std::string>& get_all_file_names();
	private:
		std::vector<std::string> All_file_names_vector;
};

extern All_file_names_class AFNs_class;
#endif // ALL_FILE_NAMES
