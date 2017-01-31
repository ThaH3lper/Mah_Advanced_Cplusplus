#include <iostream>
#include "List.hpp"
#include <assert.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

//Olle test
template Link<Node<float>>;    //Detta tvingar fram att allting i Link kompileras
template List<Node<float>>;    //Detta tvingar fram att allting i List kompileras


void TestDLL() {
	List<Node<float>> myList;
	myList.Check();
	myList.InsertFirst(new Node<float>(5));
	myList.Check();
	myList.InsertFirst(new Node<float>(4));
	myList.Check();
	Node<float> * node3 = myList.InsertFirst(new Node<float>(3));
	myList.InsertFirst(new Node<float>(2));
	myList.InsertFirst(new Node<float>(1));
	myList.InsertFirst(new Node<float>(5));
	myList.InsertFirst(new Node<float>(4));
	myList.InsertFirst(new Node<float>(3));
	myList.InsertFirst(new Node<float>(2));
	myList.InsertFirst(new Node<float>(1));
	myList.Check();
	std::cout << myList << std::endl;
	node3->Next();
	Node<float>* search = new Node<float>(2);
	Node<float> * temp2 = myList.Find(search);
	delete search;
	search = new Node<float>(1);
	Node<float> * temp3 = temp2->Find(search);
	delete search;
	Node<float> * temp5 = temp3->DeleteAfter();   //ta bort andra 2:an
	myList.Check();
	assert(*temp5->data == 2);
	delete temp5;
	std::cout << myList << std::endl;

	search = new Node<float>(5);
	Node<float> * tmpx = myList.Find(search);
	delete search;
	delete tmpx->DeleteAfter();
	myList.Check();
	std::cout << myList << std::endl;
	search = new Node<float>(3);
	tmpx = myList.Find(search);
	delete search;
	search = new Node<float>(3);
	tmpx = tmpx->Find(search);
	delete search;

	tmpx->InsertBefore(new Node<float>(2))->InsertBefore(new Node<float>(1));
	std::cout << myList << std::endl;
	myList.Check();
	
	Node<float> * obj = myList.PopFirst();
	assert(*obj->data == 1);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 2);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 3);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 4);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 5);
	delete obj;

	obj = myList.PopFirst();
	myList.Check();
	assert(*obj->data == 1);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 2);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 3);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 4);
	delete obj;

	obj = myList.PopFirst();
	assert(*obj->data == 5);
	delete obj;

	assert(myList.PopFirst() == nullptr);
	assert(myList.PopFirst() == nullptr);
	std::cout << myList << std::endl << "end";
	myList.Check();
	std::cin.get();
}


//My test
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

	TestDLL();
	//charTest();

	std::cin.get();
	return 0;
}