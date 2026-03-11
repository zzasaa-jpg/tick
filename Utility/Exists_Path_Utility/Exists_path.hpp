#ifndef EXISTS_PATH
#define EXISTS_PATH

#include <string>

class Exists_path_class
{
	public:
		Exists_path_class();
		bool exists_path(const std::string& filename, const std::string& targetPath);
};

extern Exists_path_class exists_path_class;

#endif // EXISTS_PATH
