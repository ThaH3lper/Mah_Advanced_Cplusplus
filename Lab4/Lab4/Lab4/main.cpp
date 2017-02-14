#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <forward_list>

template<class Iterator>
void print(Iterator begin, Iterator end)
{
	std::cout << "|";
	for (auto i = begin; i != end; i++)
		std::cout << *i  << "|";
	std::cout << std::endl;
}

void upg1()
{
	/* Upg 1a */
	std::cout << "Upg 1a" << std::endl;

	std::vector<int> a(10);
	std::iota(a.begin(), a.end(), 0);
	std::random_shuffle(a.begin(), a.end());				//Create, add 0-9 and shuffel

	print(a.begin(), a.end());								//Print 

	std::sort(a.begin(), a.end());							//Sort

	print(a.begin(), a.end());								//Print

	/* Upg 1b */
	std::cout << std::endl << "Upg 1b" << std::endl;

	int b[10];
	std::iota(std::begin(b), std::end(b), 0);
	std::random_shuffle(std::begin(b), std::end(b));		//Create, add 0-9 and shuffel

	print(std::begin(b), std::end(b));						//Print

	std::sort(std::begin(b), std::end(b));					//Sort

	print(std::begin(b), std::end(b));						//Print

	/* Upg 1c */
	std::cout << std::endl << "Upg 1c" << std::endl;

	std::vector<int> c(10);
	std::iota(c.begin(), c.end(), 0);
	std::random_shuffle(c.begin(), c.end());				//Create, add 0-9 and shuffel

	print(c.begin(), c.end());								//Print

	std::sort(c.rbegin(), c.rend());						//Sort backwards

	print(c.begin(), c.end());								//Print

	/* Upg 1d */
	std::cout << std::endl << "Upg 1d" << std::endl;

	int d[10];
	std::iota(std::begin(d), std::end(d), 0);
	std::random_shuffle(std::begin(d), std::end(d));								//Create, add 0-9 and shuffel

	print(std::begin(d), std::end(d));												//Print

	std::sort(std::begin(d), std::end(d), [](int a, int b) { return a > b; });		//Sort backwards

	print(std::begin(d), std::end(d));												//Print

}

void upg2()
{
	std::cout << std::endl << "Upg 2" << std::endl;

	std::vector<int> list(25);
	std::iota(list.begin(), list.end(), 0);														//Create list 0-24

	print(list.begin(), list.end());															//Print

	auto listEnd = std::remove_if(list.begin(), list.end(), [](int i) {return i % 2 == 0; });	//Move all even numbers to the end of the list.
	list.erase(listEnd, list.end());															//remove the even numbers from the end.

	print(list.begin(), list.end());															//Print
}

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator moveEnd = end;
	for (auto it = begin; it != end; it++)		//Bubbel sort O(n^2)
	{
		ForwardIterator before = begin;
		for (auto i = begin; i != moveEnd; i++)
		{
			if (i == begin)
				continue;
			if (*i < *before)
				std::swap(*before, *i);
			before = i;
		}
		moveEnd = before;
	}
}

void upg3()
{
	std::cout << std::endl << "Upg 3" << std::endl;

	std::forward_list<int> list{9, 2, 7, 3, 4, 1, 6, 5, 8, 0};		//Create a forward list that needs to be sorted

	print(list.begin(), list.end());								//Print

	ForwardSort(list.begin(), list.end());							//Sort the list

	print(list.begin(), list.end());								//Print
}

int main()
{
	upg1();
	upg2();
	upg3();

	std::cin.get();
	return 0;
}