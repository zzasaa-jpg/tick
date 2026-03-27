#ifndef PRINT_TIMER_UTILITY
#define PRINT_TIMER_UTILITY

#include <string>

class PRINT_TIMER_UTILITY_CLASS
{
	public:
		PRINT_TIMER_UTILITY_CLASS();
		void print_timer(long long elapses_seconds, const std::string& nes);
		std::string format_time_ostring_stream(long long elapsed_seconds);
};

extern PRINT_TIMER_UTILITY_CLASS print_timer_utility;

#endif // PRINT_TIMER_UTILITY
