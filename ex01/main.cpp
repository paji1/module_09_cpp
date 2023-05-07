
# include "BitcoinExchange.hpp"




int main(void)
{
	try
	{
		BitcoinExchange test;
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
