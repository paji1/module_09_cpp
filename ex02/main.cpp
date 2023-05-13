/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:02:01 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/05/12 16:18:17 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"



int main(int ac , char **av)
{
	if (ac < 2)
		return std::cerr << "Error: ARGS" << std::endl, 1;
	
	try
	{
		PmergeMe sort(av + 1, ac -1);	
	}
	catch(const char  *e)
	{
		std::cerr << e << '\n';
	}
	
	
	return 0;
}
