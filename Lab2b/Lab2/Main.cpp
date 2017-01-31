#include <iostream>
#include "List.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

//olleTest
template Link<float>;    //Detta tvingar fram att allting i Link kompileras
template List<float>;    //Detta tvingar fram att allting i List kompileras


void TestDLL() {
	List<float> myList;
	myList.Check();
	myList.InsertFirst(5);
	myList.Check();
	myList.InsertFirst(4);
	myList.Check();
	Node<float> * node3 = myList.InsertFirst(3);
	myList.InsertFirst(2);
	myList.InsertFirst(1);
	myList.InsertFirst(5);
	myList.InsertFirst(4);
	myList.InsertFirst(3);
	myList.InsertFirst(2);
	myList.InsertFirst(1);
	myList.Check();
	std::cout << myList;
	node3->Next();
	Node<float> * temp2 = myList.Find(2);
	Node<float> * temp3 = temp2->Find(1);
	Node<float> * temp5 = temp3->DeleteAfter();   //ta bort andra 2:an
	myList.Check();
	assert(*temp5->data == 2);
	delete temp5;
	std::cout << myList << std::endl;

	Node<float> * tmpx = myList.Find(5);
	delete tmpx->DeleteAfter();
	myList.Check();
	std::cout << myList << std::endl;
	tmpx = myList.Find(3);
	tmpx = tmpx->Find(3);
	tmpx->InsertBefore(new Node<float>(2))->InsertBefore(new Node<float>(1));
	std::cout << myList << std::endl;
	myList.Check();

	Node<float>* obj = myList.PopFirst();
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
	myList.Check();

	std::cout << myList << std::endl;

	obj = myList.PopFirst();
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

//My Test;
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

	TestDLL();
	//charTest();

	std::cin.get();
	return 0;
}