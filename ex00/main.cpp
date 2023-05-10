
# include "BitcoinExchange.hpp"




int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	try
	{
		BitcoinExchange test(av);
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
