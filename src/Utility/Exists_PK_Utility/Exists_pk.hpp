#ifndef EXISTS_PK
#define EXISTS_PK

#include <string>

class Exists_pk_class
{
	public:
		Exists_pk_class();
		bool exists_pk(const std::string& filename, std::string& targetPK, bool PK);
};

extern Exists_pk_class exists_pk_class;

#endif // EXISTS_PK
