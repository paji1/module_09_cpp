#include "RPN.hpp"
#include <string.h>

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
RPN::RPN()
{
}

RPN::RPN(std::string _expres) : operators("+-/*")
{
	for (int i = 0; _expres[i] ; i++)
	{
		std::string token(1, _expres[i]);
		if (is_number(token))
			handle_number(token);
		else if (is_operator(token))
			handle_op(token);
		else if (isspace(_expres[i]))
			continue;
		else
			throw "ERROR";
	}
}

RPN::RPN(const RPN &other) 
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
RPN::~RPN()
{
	std::cout << rpn.top() << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
RPN&   RPN::operator=(RPN const & other )
{
	(void)other;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/


bool	RPN::is_operator(std::string &str)
{
	if (str.length() != 1)
		return false;
	for (int i = 0 ; str[i] ; i++)
		if (operators.find(str[i]) == operators.npos)
			return false;
	return true;
}

bool	RPN::is_number(std::string& str)
{
	for (int i = 0 ; str[i] ; i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}


void	RPN::handle_number(std::string &number)
{
	rpn.push(number);
}

void	RPN::perform_op(std::string &op, double b, double a)
{
	std::string resu;
	res = 0;
	if (op == "/")
	{
		res = (double)a / b;
		if (a == 0)
			throw "error";
	}
	else if (op == "*")
	{
		res = (double)a * b;
	}
	else if (op == "+")
	{
		res = a + b;
	}
	else
	{
		res = a - b;
	}
	std::ostringstream num;
	num << res;
	rpn.push(num.str());
}

void	RPN::handle_op(std::string &op)
{
	std::stringstream num;
	double a  = 0;
	double b  = 0;

	if (rpn.size() >= 1)
	{
		num << rpn.top();
		num >> a;
		rpn.pop();
	}
	else
		throw "error";

	if (rpn.size() >= 1)
	{
		num.clear();
		num << rpn.top();
		num >> b;
		rpn.pop();
	}
	else
		throw "error";

	perform_op(op, a, b);
}

/*** --------------------------------- ACCESSOR ---------------------------------*/

/*** --------------------------------- ACEPTION ---------------------------------*/

