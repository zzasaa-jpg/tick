#include "./Help.hpp"

#include <iostream>
#include <string>

int Help()
{
	std::cout << "Usage:\n";
	std::cout << "*-----------------------------------------------------------------------------*\n";
	std::cout << "|  Commands              | Usages                                             |\n";
	std::cout << "|------------------------|----------------------------------------------------|\n";
	std::cout << "|  cpp.exe               | Start / Stop timer                                 |\n";
	std::cout << "|  cpp.exe status        | Show running status at default path                |\n";
	std::cout << "|  cpp.exe clear         | Reset all time data at default path                |\n";
	std::cout << "|  cpp.exe default       | Set default path                                   |\n";
	std::cout << "|  cpp.exe new_ path key | Set user path                                      |\n";
	std::cout << "|  cpp.exe status path   | Show running status at user path                   |\n";
	std::cout << "|  cpp.exe clear path    | Reset all time data at user path                   |\n";
	std::cout << "|  cpp.exe list          | List of active timers                              |\n";
	std::cout << "|  cpp.exe session       | Show default path session time with out timer stop |\n";
	std::cout << "|  cpp.exe session path  | Show user path session time with out timer stop    |\n";
	std::cout << "|  cpp.exe help          | Show this help                                     |\n";
	std::cout << "|  cpp.exe version       | Print the tool current version                     |\n";
	std::cout << "|  cpp.exe search        | Search specific timer path in directory file       |\n";
	std::cout << "*-----------------------------------------------------------------------------*\n";
	return 1;
}
