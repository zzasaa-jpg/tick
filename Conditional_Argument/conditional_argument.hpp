#ifndef CONDITIONAL_ARGUMENT
#define CONDITIONAL_ARGUMENT

class Conditional_Argument_Class{
	public:
		Conditional_Argument_Class();
		int condition_of_arguments(char* argv[], int argc);
};

extern Conditional_Argument_Class condtnl_arg_cls;

#endif // CONDITIONAL_ARGUMENT
