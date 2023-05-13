#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
class Integer
{
	int number;

private:
	bool is_number(char *);

public:
	Integer(char *);
	Integer();
	Integer(Integer const &);
	~Integer();
	Integer &operator=(Integer const &);
	Integer &operator=(int);
	bool operator==(Integer const &);
	bool operator!=(Integer const &);
	bool operator<=(Integer const &);
	bool operator<(Integer const &);
	bool operator>=(Integer const &);
	bool operator>(Integer const &);

	int  get_nember() const;
};
std::ostream &operator<<(std::ostream &os, const Integer &other);


#endif /* * SPAN_H */
