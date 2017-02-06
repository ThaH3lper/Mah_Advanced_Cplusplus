#include <iostream>
#include "String.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	String a = String("Pommes");
	String y = String(" Korv !");

	String p = a + y + a + y + a + y;
	std::cout << p << std::endl;

	std::cin.get();
	return 0;
}