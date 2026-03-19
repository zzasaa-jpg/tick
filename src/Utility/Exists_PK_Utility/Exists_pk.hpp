#ifndef EXISTS_PK
#define EXISTS_PK

#include <string>

class Exists_pk_class
{
	public:
		Exists_pk_class();
		bool exists_path(const std::string& filename, const std::string& targetPath);
		bool exists_key(const std::string& filename, const std::string& targetKey);
};

extern Exists_pk_class exists_pk_class;

#endif // EXISTS_PK
