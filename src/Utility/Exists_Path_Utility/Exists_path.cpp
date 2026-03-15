#include "./Exists_path.hpp"
#include "../../Utility/RCFV_Utility/RCFV_Utility.hpp"

#include <string>

Exists_path_class exists_path_class;
Exists_path_class::Exists_path_class(){};

bool Exists_path_class::exists_path(const std::string& filename, const std::string& targetPath)
{
	std::string file_content = rcfv_utility.Read_content_from_vector<std::string>(filename);
	if(file_content.find(targetPath) != std::string::npos) return true;
	return false;
}
