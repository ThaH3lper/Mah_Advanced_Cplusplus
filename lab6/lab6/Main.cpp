#include <iostream>
#include "SmartPointer.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	std::cout << "Ayyy" << std::endl;
	SharedPointer<char> sp = SharedPointer<char>(new char('a'));
	SharedPointer<char> s1 = SharedPointer<char>();

	std::cin.get();
}