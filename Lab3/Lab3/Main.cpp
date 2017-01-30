#include <iostream>

#include "String.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//String s = String("Pommes");
	//std::cout << s << std::endl;
	//String t = String("test");
	//std::cout << t << std::endl;

	//String x = String(s);
	//std::cout << x << std::endl;

	//std::cout << s.size() << std::endl;

	//s.at(4) = 'x';
	//std::cout << " - "<< s << std::endl;
	//std::cout << " - "<< t << std::endl;

	String a = String("Pommes");
	std::cout << a << std::endl;

	a.resize(10);
	std::cout << a << std::endl;
	std::cout << a.size() << std::endl;

	a.at(1) = 'X';
	a[4] = 'Y';

	String b = String("ost");

	a = b;

	std::cout << a << std::endl;

	a = 'X';

	std::cout << a << std::endl;





	std::cin.get();
	return 0;
}