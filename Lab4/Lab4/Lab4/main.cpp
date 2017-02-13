#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

void printVector(std::vector<int> list)
{
	std::cout << "|";
	for (std::vector<int>::iterator i = list.begin(); i != list.end(); i++)
		std::cout << *i  << "|";
	std::cout << std::endl;
}

void printArray(int list[], int size)
{
	std::cout << "|";
	for (int i = 0; i < size; i++)
		std::cout << list[i] << "|";
	std::cout << std::endl;
}

void upg1()
{
	/* Upg 1a */
	std::cout << "Upg 1a" << std::endl;

	std::vector<int> a(10);
	std::iota(a.begin(), a.end(), 0);
	std::random_shuffle(a.begin(), a.end());

	printVector(a);

	std::sort(a.begin(), a.end());

	printVector(a);

	/* Upg 1b */
	std::cout << std::endl << "Upg 1b" << std::endl;

	int b[10];
	std::iota(std::begin(b), std::end(b), 0);
	std::random_shuffle(std::begin(b), std::end(b));

	printArray(b, 10);

	std::sort(std::begin(b), std::end(b));

	printArray(b, 10);

	/* Upg 1c */
	std::cout << std::endl << "Upg 1c" << std::endl;

	std::vector<int> c(10);
	std::iota(c.begin(), c.end(), 0);
	std::random_shuffle(c.begin(), c.end());

	printVector(c);

	std::sort(c.rbegin(), c.rend());

	printVector(c);

	/* Upg 1d */
	std::cout << std::endl << "Upg 1d" << std::endl;

	int d[10];
	std::iota(std::begin(d), std::end(d), 0);
	std::random_shuffle(std::begin(d), std::end(d));

	printArray(d, 10);

	std::sort(std::begin(d), std::end(d), [](int a, int b) { return a > b; });

	printArray(d, 10);

}
int main()
{

	upg1();

	std::cin.get();
	return 0;
}