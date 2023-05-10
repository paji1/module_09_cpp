#include "BitcoinExchange.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
BitcoinExchange::BitcoinExchange()
{
	load_file("./data.csv", data, ",");
}
BitcoinExchange::BitcoinExchange(char **av)
{
	load_file("./data.csv", data, ",");
	for (int i = 1; av[i]; i++)
		load_file(av[i], data, "|");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
	std::map<std::string, double>::iterator it = data.begin();
	while (it != data.end())
	{
		other.data.insert(std::make_pair((*it).first, (*it).second));
		it++;
	}
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
BitcoinExchange::~BitcoinExchange()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	std::map<std::string, double>::iterator it = data.begin();
	while (it != data.end())
	{
		other.data.insert(std::make_pair((*it).first, (*it).second));
		it++;
	}
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

bool BitcoinExchange::isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

std::string trim(const std::string &s)
{
	std::string::const_iterator start = s.begin();
	while (start != s.end() && std::isspace(*start))
		start++;

	std::string::const_iterator end = s.end();
	do
	{
		end--;
	} while (start != end && std::isspace(*end));

	return std::string(start, end + 1);
}

bool BitcoinExchange::is_double(std::string num)
{
	if (num == "nan" || num == "+inf" || num == "inf" || num == "-inf")
		return true;
	size_t lenth = num.length();
	if (!lenth)
		return false;
	if (num[lenth - 1] == 'f')
		num[lenth - 1] = '0';
	size_t dot_pos;
	if ((dot_pos = num.find_last_of('.')) != num.find_first_of('.'))
		return false;
	if (dot_pos != num.npos)
		num[dot_pos] = '0';
	if (num[0] == '+' || num[0] == '-')
		num[0] = '0';
	for (int i = 0; num[i]; i++)
		if (!isdigit(num[i]))
			return false;
	return true;
}

bool BitcoinExchange::is_inrange(int day, int mounth, int year)
{
	int thirty_one[] = {1, 3, 5, 7, 8, 10, 12};
	if (day < 0 || day > 31)
		return false;
	if ((mounth == 2 && day == 29) && ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0))
		return false;
	for (int i = 0; i < 7 && day == 31; i++)
		if (thirty_one[i] == mounth)
			return true;
	if (day == 31)
		return false;
	return true;
}

std::string BitcoinExchange::get_date(std::string &output, int sp)
{
	struct tm tm;
	std::string date;
	char *time;

	date = trim(output.substr(0, sp));
	time = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (!time || *time != 0)
		throw "date isn't valid\n";
	if (!is_inrange(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900))
		throw "date isn't valid\n";
	return date;
}

double BitcoinExchange::get_value(std::string &output,
								  int sp, const char *filename)
{
	std::string valuestr;
	double value;

	valuestr = trim(output.substr(sp + 1));
	if (is_double(valuestr))
	{
		value = (double)atof(valuestr.c_str());
		if (std::string(filename) != "./data.csv")
		{
			if (value < 0)
				throw "Error: not a positive number.";
			if (value > 1000)
				throw "Error: too large a number.";
		}
	}
	else
		throw "Error value";
	return value;
}

double BitcoinExchange::get_lower(std::string &key)
{
	try
	{
		return data.at(key);
	}
	catch (...)
	{
		std::map<std::string, double>::iterator it = data.lower_bound(key);
		
		if (it == data.end())
			throw "not found";
		it--;
		try 
		{
			data.at((*it).first);
		}
		catch (...)
		{
			throw "not found";
		}
		return (*it).second;
	}
}

void BitcoinExchange::exucute(std::string &date, double value)
{
	std::cout << date << " => " << value << " = " << (value * get_lower(date)) << std::endl;
}

void BitcoinExchange::load_file(const char *filename, std::map<std::string, double> &_data, const char *delim)
{
	std::ifstream csvfile(filename);
	std::size_t sp = 0;
	std::string date;
	double value;

	if (!csvfile.is_open())
		throw "faild to open file";

	{
		std::string output;
		std::getline(csvfile, output);
	}
	for (std::string output; std::getline(csvfile, output);)
	{
		if (csvfile.fail() || csvfile.bad())
			throw "filed";
		if (output.empty())
			continue;
		try
		{
			sp = -1;
			if (std::string(filename) != "./data.csv" && output.find(" | ") == output.npos)
			{
				error = "Error: bad input => " + output;
				throw error.c_str();
			}
			if ((sp = output.find_first_of(delim)) != output.find_last_of(delim) || sp == output.npos)
			{
				error = "Error: bad input => " + output;
				throw error.c_str();
			}
			date = get_date(output, sp);
			value = get_value(output, sp, filename);
			if (std::string(filename) != "./data.csv")
				exucute(date, value);
			else
			{
				_data.insert(std::make_pair(date, value));
			}
		}
		catch (const char *e)
		{
			if (std::string(filename) == "./data.csv")
				throw e;
			if (std::string(e) == "filed")
				throw "error while reading";
			std::cerr << e << '\n';
		}
	}
}

/*** --------------------------------- ACCESSOR ---------------------------------*/

/*** --------------------------------- ACEPTION ---------------------------------*/
