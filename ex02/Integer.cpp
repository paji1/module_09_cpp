#include "Integer.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Integer::Integer()
{
	number = 0;
}
Integer::Integer(char *str)
{
	if (is_number(str))
	{
		number = atoi(str);
		if (number < 0)
			throw "Error";
	}
	else
		throw "Error number not integer";
}

Integer::Integer(const Integer &other)
{
	*this = other;
}



/*** -------------------------------- DESTRUCTOR --------------------------------*/
Integer::~Integer()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Integer&   Integer::operator=(Integer const & other )
{
	this->number = other.get_nember();
	return *this;
}

Integer&   Integer::operator=(int other)
{
	this->number = other;
	return *this;
}

bool   Integer::operator==(Integer const & other)
{
	return this->number == other.get_nember();
}
bool   Integer::operator!=(Integer const & other)
{
	return this->number != other.get_nember();
}
bool   Integer::operator<=(Integer const & other)
{
	return this->number <= other.get_nember();
}
bool   Integer::operator<(Integer const & other)
{
	return this->number < other.get_nember();
}
bool   Integer::operator>(Integer const & other)
{
	return this->number > other.get_nember();
}
bool   Integer::operator>=(Integer const & other)
{
	return this->number >= other.get_nember();
}
std::ostream &operator<<(std::ostream &os, const Integer &other)
{
	os << other.get_nember();
	return os;
}

/*** --------------------------------- METHODS ----------------------------------*/
bool Integer::is_number(char *str)
{
    char* p;

    strtol(str, &p, 10);
    return *p == 0;
}


int Integer::get_nember() const
{
	return number;
}

/*** --------------------------------- ACCESSOR ---------------------------------*/

/*** --------------------------------- ACEPTION ---------------------------------*/


