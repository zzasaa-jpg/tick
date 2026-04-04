#ifndef PRINT_TIMER_UTILITY
#define PRINT_TIMER_UTILITY

#include <string>

class PRINT_TIMER_UTILITY_CLASS
{
	public:
		PRINT_TIMER_UTILITY_CLASS();
		std::string print_timer(long long elapses_seconds);
};

extern PRINT_TIMER_UTILITY_CLASS print_timer_utility;

#endif // PRINT_TIMER_UTILITY
