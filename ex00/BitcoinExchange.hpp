#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <ctime>
# include <map>
# include <string>
# include <fstream>
# include <algorithm>
# include <math.h>

class BitcoinExchange
{
private:
	std::	string error;
	std::	map<std::string, double> data;
	bool	isdigit(int);
	bool	is_double(std::string);
	bool	is_inrange(int, int, int);
	std::string get_date(std::string& output, int sp);
	double	get_value(std::string& output, int sp, const char *filename);
	void	exucute(std::string& , double);
	double get_lower(std::string &key);
	void	load_file(const char*, std::map<std::string, double>&, const char *);

public:
	BitcoinExchange();
	BitcoinExchange(char **av);
	BitcoinExchange(BitcoinExchange  &);
	~BitcoinExchange();

	BitcoinExchange&	operator=(BitcoinExchange  &);
};

#endif /* * SPAN_H */
