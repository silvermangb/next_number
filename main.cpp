/*
 * main.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: Greg Silverman
 */

/**/

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

template<typename T>
std::ostream&
operator<<
   (std::ostream& p_ostream,const std::vector<T> & p_v)
{
	for(auto i : p_v)
	{
		p_ostream << i << ",";
	}
	p_ostream << std::endl;
	return p_ostream;
}

template<typename T>
std::ostream&
operator<<
   (std::ostream& p_ostream,const std::map<T,T> & p_v)
{
	for(auto i : p_v)
	{
		p_ostream << "(" << i.first << "," << i.second << "),";
	}
	p_ostream << std::endl;
	return p_ostream;
}

int
incrementer
	(std::vector<int>& p_n)
{
	bool duplicates = false;
	std::vector<int> counts(4,0);
	const int N = p_n.size();
	int carry = 0;
	int rc = 0;
	std::vector<int>::reverse_iterator it = p_n.rbegin();
	++*it;
	if(*it==N)
	{
		*it = 0;
		carry = 1;
	}
	counts[*it] = 1;
	rc += *it;
	for(++it;it!=p_n.rend();++it)
	{
		*it += carry;
		const int tmp = *it;
		rc += *it;
		carry = 0;
		if(*it==N)
		{
			*it = 0;
			carry = 1;
			rc -= tmp;
		}
		if(counts[*it]==1)
		{
			duplicates = true;
		}
		else
		{
			counts[*it] = 1;
		}
	}
	if(duplicates)
	{
		rc = 0;
	}
	return rc;
}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		std::cout << "usage: " << argv[0] << "<integer>\n";
		exit(0);
	}
	std::cout << std::boolalpha;
    std::vector<int> number;

    const int N = atoi(argv[1]);
    const int SUMN = (N-1)*N/2;
    for(int i=0;i<N;++i)
    {
    	number.push_back(i);
    }
    std::vector<int> largest_number = number;
    std::reverse(largest_number.begin(),largest_number.end());
    int count = 0;
    while(number!=largest_number)
    {
    	int sum = incrementer(number);
    	if(sum==SUMN)
    	{
    		++count;
    		std::cout << "p: " << number << std::endl;
    	}

    }
    ++count;
    std::cout << count << std::endl;
    return 0;
}


