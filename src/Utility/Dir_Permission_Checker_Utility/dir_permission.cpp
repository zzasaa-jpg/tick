#include "dir_permission.hpp"

#include <fstream>
#include <random>
#include <iostream>

std::string DirPermissionChecker::randomName()
{
	static std::mt19937 rng(std::random_device{}());
	static std::uniform_int_distribution<int> dist(100000, 999999);
	return ".perm_test_" + std::to_string(dist(rng));
}

bool DirPermissionChecker::Print_Permission(const DirPermission& res, const fs::path& dirPath)
{
	bool ok = true;
	
	if(!res.canRead) 
	{
		std::cout << "Read permission denied at -> " << dirPath << std::endl;
		ok = false;
	}
	if(!res.canWrite)
	{
		std::cout << "Write permission denied at -> "<< dirPath << std::endl;
		ok = false;
	}

	if(!res.canTraverse)
	{
		std::cout << "Traverse permission denied at -> " << dirPath << std::endl;
		ok = false;
	}
	return ok;
}

DirPermission DirPermissionChecker::check(const fs::path& dirPath)
{
	DirPermission result{false, false, false};

	if(!fs::exists(dirPath) || !fs::is_directory(dirPath))
	{
		return result;
	}

	// READ + TRAVERSE
	try
	{
		for(const auto& entry : fs::directory_iterator(dirPath))
		{
			(void)entry;
			break;
		}
		result.canRead = true;
		result.canTraverse = true;
	} catch (...)
	{
		result.canRead = false;
		result.canTraverse = false;
	}

	// WRITE
	fs::path tempFile = dirPath / randomName();
	std::ofstream file(tempFile, std::ios::out | std::ios::trunc);

	if(file.is_open())
	{
		file.close();
		std::error_code ec;
		fs::remove(tempFile, ec);
		result.canWrite = true;
	}

	return result;
}
