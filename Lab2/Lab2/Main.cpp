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
	Node<float> * temp2 = myList.Find(2.f);
	Node<float> * temp3 = temp2->Find(1.f);
	Node<float> * temp5 = temp3->DeleteAfter();   //ta bort andra 2:an
	myList.Check();
	assert(*temp5->data == 2);
	delete temp5;
	std::cout << myList << std::endl;

	Node<float> * tmpx = myList.Find(5.f);
	delete tmpx->DeleteAfter();
	myList.Check();
	std::cout << myList << std::endl;
	tmpx = myList.Find(3.f);
	tmpx = tmpx->Find(3.f);

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

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<Node<int>> list;

	list.InsertFirst(new Node<int>(1));
	list.InsertFirst(new Node<int>(2));
	list.InsertFirst(new Node<int>(3));

	const List<Node<int>> & clist = list;
	const Node<int> * a = clist.Find(1);
	

	//TestDLL();
	//charTest();

	std::cin.get();
	return 0;
}