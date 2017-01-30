#include <iostream>
#include "List.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

void PrintCheck(List<char> & list)
{
	list.Check();
	std::cout << list << std::endl;
}

void charTest()
{
	List<char> list;
	PrintCheck(list);

	list.DeleteBefore();
	PrintCheck(list);

	list.InsertLast('H');
	list.InsertLast('E');
	list.InsertLast('J');
	PrintCheck(list);

	list.InsertFirst('X');
	list.InsertFirst('Y');
	PrintCheck(list);

	Node<char> * charE = list.Find('E');
	delete charE->DeleteBefore();
	PrintCheck(list);

	delete charE->DeleteAfter();
	PrintCheck(list);

	delete charE->Next()->DeleteAfter();
	PrintCheck(list);

	delete charE->Prev()->DeleteBefore();
	PrintCheck(list);

	list.InsertFirst('F');
	list.InsertFirst('F');

	list.InsertLast('L');
	list.InsertLast('L');
	PrintCheck(list);

	delete list.PopFirst();
	delete list.PopLast();
	PrintCheck(list);

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	charTest();

	std::cin.get();
	return 0;
}