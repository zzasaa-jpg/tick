#ifndef DIR_PERMISSION_HPP
#define DIR_PERMISSION_HPP

#include <filesystem>

namespace fs = std::filesystem;

struct DirPermission {
    bool canRead;
    bool canWrite;
    bool canTraverse;
};

class DirPermissionChecker
{
	public:
		static DirPermission check(const fs::path& dirPath);
		static bool Print_Permission(const DirPermission& res, const fs::path& dirPath);
	private:
		static std::string randomName();
};

#endif // DIR_PERMISSION_HPP
