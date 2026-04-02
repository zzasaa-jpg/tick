#ifndef TRIM_SPACE
#define TRIM_SPACE

#include <string>

class Trim_spaces_class
{
	public:
		Trim_spaces_class();
		std::string trim_spaces(std::string& str);
};

extern Trim_spaces_class trim_spaces_class;

#endif // TRIM_SPACE
