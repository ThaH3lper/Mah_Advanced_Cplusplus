#include <iostream>
#include "List.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


void PrintCheck(List<Node<char>> & list)
{
	list.Check();
	std::cout << list << std::endl;
}

void charTest()
{
	List<Node<char>> list;
	PrintCheck(list);

	list.DeleteBefore();
	PrintCheck(list);

	list.InsertLast(new Node<char>('H'));
	list.InsertLast(new Node<char>('E'));
	list.InsertLast(new Node<char>('J'));
	PrintCheck(list);

	list.InsertFirst(new Node<char>('X'));
	list.InsertFirst(new Node<char>('Y'));
	PrintCheck(list);

	Node<char> * search = new Node<char>('E');
	Node<char> * charE = list.Find(search);
	delete search;

	delete charE->DeleteBefore();
	PrintCheck(list);

	delete charE->DeleteAfter();
	PrintCheck(list);

	delete charE->Next()->DeleteAfter();
	PrintCheck(list);

	delete charE->Prev()->DeleteBefore();
	PrintCheck(list);

	list.InsertLast(new Node<char>('L'));
	list.InsertLast(new Node<char>('L'));

	list.InsertFirst(new Node<char>('B'));
	list.InsertFirst(new Node<char>('B'));
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