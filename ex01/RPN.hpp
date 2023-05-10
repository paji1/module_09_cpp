#ifndef RPN_HPP
# define RPN_HPP

# include <sstream>
# include <iostream>
# include <string>
# include <set>
# include <stack>
# include <algorithm>
# include <math.h>
class RPN
{
private:
	const std::string operators;
	double res;
	std::stack<std::string> rpn;
	
	bool	is_operator(std::string &);
	bool	is_number(std::string &);

	void	handle_number(std::string &);
	void	handle_op(std::string &);

	void	perform_op(std::string & , double, double);
	
public:
	RPN();
	RPN(std::string express);
	RPN(RPN const &);
	~RPN();

	RPN&	operator=(RPN const &);
};

#endif /* * SPAN_H */
