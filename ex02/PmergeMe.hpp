#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <set>
# include <vector>
# include <algorithm>
# include <math.h>
# include <sstream>
# include "Integer.hpp"
# include <deque>

class PmergeMe
{
private:
	
	
public:
	PmergeMe();
	PmergeMe(char **, int);
	PmergeMe(PmergeMe const &);
	~PmergeMe();
	PmergeMe&	operator=(PmergeMe const &);
	
	void merge(std::vector<Integer>&,std::vector<Integer>&, std::vector<Integer>&);
	void merge(std::deque<Integer>&,std::deque<Integer>&, std::deque<Integer>&);
	void mergesort(std::vector<Integer> &a);
	void mergesort(std::deque<Integer> &a);
	void insertion(std::vector<Integer> &a);
	void insertion(std::deque<Integer> &a);

};

#endif /* * SPAN_H */
