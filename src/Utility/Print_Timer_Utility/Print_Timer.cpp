#include "./Print_Timer.hpp"

#include <sstream>
#include <iostream>
#include <vector>

PRINT_TIMER_UTILITY_CLASS print_timer_utility;
PRINT_TIMER_UTILITY_CLASS::PRINT_TIMER_UTILITY_CLASS(){};

std::string PRINT_TIMER_UTILITY_CLASS::format_time_ostring_stream(long long elapsed_seconds)
{
	struct Unit { long long value; const char* label; };

	const std::vector<Unit> units = 
	{
		{100LL * 365 * 24 * 3600, "c"},
		{10LL  * 365 * 24 * 3600, "dec"},
		{365LL * 24  * 3600, "y" },
		{30LL  * 24  * 3600, "m"},
		{24LL  * 3600, "d"}
	};

	std::ostringstream out;

	for(auto &u : units)
	{
		long long v = elapsed_seconds / u.value;
		elapsed_seconds %= u.value;

		if(v > 0 || out.tellp() > 0) out << (v < 10 ? "0" : "") << v << u.label << ":";
	}

	int hours   = elapsed_seconds / 3600; elapsed_seconds %= 3600;
	int minutes = elapsed_seconds / 60; elapsed_seconds %= 60;

	auto pad = [](int x){return (x < 10 ? "0" : "") + std::to_string(x); };

	out << pad(hours) << ":"  << pad(minutes) << ":" << pad(elapsed_seconds);
	return out.str();
}

void PRINT_TIMER_UTILITY_CLASS::print_timer(long long elapsed_seconds, const std::string& mes)
{
	std::cout << mes
		  << format_time_ostring_stream(elapsed_seconds)
		  << std::endl;
}
