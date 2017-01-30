#include <iostream>

#include "StringHelper.h"

#define CHAR_MAX 128

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Init
	char * inputStr = new char[CHAR_MAX];
	char * replaceStr = new char[CHAR_MAX];
	char * changeToStr = new char[CHAR_MAX];

	bool doAgain = true;
	StringHelper helper;

	while (doAgain)
	{

		//Ask user for strings
		std::cout << "Type a string: ";
		std::cin.getline(inputStr, CHAR_MAX);

		std::cout << "Replace: ";
		std::cin.getline(replaceStr, CHAR_MAX);

		std::cout << "With: ";
		std::cin.getline(changeToStr, CHAR_MAX);

		//Replacing
		char * result = helper.Replace(inputStr, replaceStr, changeToStr);
		if (result != nullptr)
		{
			std::cout << result;
			delete[] result;
		}
		else
			std::cout << inputStr;

		//again?
		std::cout << std::endl << std::endl << "Again? type yes or no (y/n) ";
		std::cin.getline(inputStr, CHAR_MAX);
		if (strcmp(inputStr, "no") == 0 || strcmp(inputStr, "n") == 0)
			doAgain = false;

	}

	//Delete all arrays on heap.
	delete[] inputStr;
	delete[] replaceStr;
	delete[] changeToStr;

	return 0;
}

