
# include "RPN.hpp"




int main(int ac , char **av)
{
	if (ac != 2)
		return std::cerr << "ERROR " << std::endl, 1;
	try
	{
		
		RPN rpn(av[1]);
	}
	catch(char const *e)
	{
		std::cerr << e << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
