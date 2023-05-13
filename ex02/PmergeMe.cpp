#include "PmergeMe.hpp"
#include <ctime>

/*** ------------------------------- CONSTRUCTOR --------------------------------*/

#include <unistd.h>
PmergeMe::PmergeMe()
{
}

void print_elements(std::vector<Integer> &la)
{
	for (std::vector<Integer>::iterator it = la.begin(); it != la.end(); it++)
		std::cout <<  *it << " ";
	std::cout << std::endl;
}

void print_time(clock_t start, clock_t  end, const char *type, size_t size)
{
	std::cout 
	<< "Time to process a range of "
	<<	size
	<< " elements with std::"
	<< type
	<< " : "
	<<   1000.0 * (end - start) / CLOCKS_PER_SEC
	<< " ms"
	<< std::endl;
}


PmergeMe::PmergeMe(char **av, int num)
{

	std::vector<Integer> list_vector(av, av + num);
	std::deque<Integer>  list_deque(av, av + num);
	std::cout << "before : ", print_elements(list_vector);
	
	clock_t start, end;

	start = clock();
	mergesort(list_vector);
	end = clock();
	std::cout << "after  : ", print_elements(list_vector);
	print_time(start, end, "vector", list_vector.size());

	start = clock();
	mergesort(list_deque);
	end = clock();
	print_time(start, end, "deque",  list_vector.size());

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
PmergeMe::~PmergeMe()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
PmergeMe&   PmergeMe::operator=(PmergeMe const & other )
{
	(void)other;
	return *this;
}



/*** --------------------------------- METHODS ----------------------------------*/

void PmergeMe::merge(std::vector<Integer>& a, std::vector<Integer>&l,std::vector<Integer>&r)
{
	int i= 0, j= 0 ,k= 0;

	int nl = l.size(), nr = r.size();
	while (i < nl && j < nr)
	{
		if (l[i] <= r[j])
		{
			a[k] = l[i];
			k = k + 1;
			i++;
		}
		else
		{
			a[k] = r[j];
			k = k + 1;
			j++;
		}
	}
	while (i < nl)
	{
			a[k] = l[i];
			k = k + 1;
			i++;
	}
	while (j < nr)
	{
			a[k] = r[j];
			k = k + 1;
			j++;
	}
}

void PmergeMe::merge(std::deque<Integer>& a, std::deque<Integer>&l,std::deque<Integer>&r)
{
	int i= 0, j= 0 ,k= 0;

	int nl = l.size(), nr = r.size();
	while (i < nl && j < nr)
	{
		if (l[i] <= r[j])
		{
			a[k] = l[i];
			k = k + 1;
			i++;
		}
		else
		{
			a[k] = r[j];
			k = k + 1;
			j++;
		}
	}
	while (i < nl)
	{
			a[k] = l[i];
			k = k + 1;
			i++;
	}
	while (j < nr)
	{
			a[k] = r[j];
			k = k + 1;
			j++;
	}
}


void PmergeMe::mergesort(std::vector<Integer>& a)
{
	int n = a.size();

	if (n < 2)
		return ;
	if (n < 10)
	{
		insertion(a);
		return ;
	}
	int mid = n / 2;
	
	std::vector<Integer> left(a.begin(), a.begin() + mid);
	std::vector<Integer> right(a.begin() + mid, a.begin() + n);
	mergesort(left);
	mergesort(right);
	merge(a, left, right);
}
void PmergeMe::mergesort(std::deque<Integer>& a)
{
	int n = a.size();

	if (n < 2)
		return ;
	if (n < 10)
		insertion(a);
	int mid = n / 2;
	
	std::deque<Integer> left(a.begin(), a.begin() + mid);
	std::deque<Integer> right(a.begin() + mid, a.begin() + n);
	mergesort(left);
	mergesort(right);
	merge(a, left, right);
}

void PmergeMe::insertion(std::vector<Integer>& a)
{
	int n = a.size();
	int value;
	int hole;

	for (int i = 1; i < n ; i++)
	{
		value = a[i].get_nember();
		hole = i;
		while (hole > 0 && a[hole -1].get_nember() > value)
		{
			a[hole] = a[hole - 1];
			hole--;
		}
		a[hole] = value;
	}
}
void PmergeMe::insertion(std::deque<Integer>& a)
{
	int n = a.size();
	int value;
	int hole;

	for (int i = 1; i < n ; i++)
	{
		value = a[i].get_nember();
		hole = i;
		while (hole > 0 && a[hole -1].get_nember() > value)
		{
			a[hole] = a[hole - 1];
			hole--;
		}
		a[hole] = value;
	}
}

/*** --------------------------------- ACCESSOR ---------------------------------*/

/*** --------------------------------- ACEPTION ---------------------------------*/

