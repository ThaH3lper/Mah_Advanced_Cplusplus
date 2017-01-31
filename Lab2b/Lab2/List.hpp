#pragma once
#include "List.h"

template<class T>
List<T>::List()
{
	next = this;
	prev = this;
}

template<class T>
List<T>::~List()
{
	Node<T>* nextInList = Next();
	while (nextInList != nullptr)
	{
		Node<T>* deleteNode = nextInList;
		nextInList = nextInList->Next();
		delete deleteNode;
	}
}

template<class T>
Node<T> * List<T>::InsertFirst(const T itemInsert)
{
	Node<T> * item = new Node<T>(itemInsert);
	this->InsertAfter(item);
	return item;
}

template<class T>
Node<T> * List<T>::InsertLast(const T itemInsert)
{
	Node<T> * item = new Node<T>(itemInsert);
	this->InsertBefore(item);
	return item;
}

template<class T>
Node<T> * List<T>::PopFirst()
{
	return this->DeleteAfter();
}

template<class T>
Node<T> * List<T>::PopLast()
{
	return this->DeleteBefore();
}

template<class T>
void List<T>::Check()
{
	const Link<T> *node = this, *nextNode = next;
	do {
		assert(node->next == nextNode && nextNode->prev == node);
		node = nextNode;
		nextNode = nextNode->next;
	} while (node != this);
}

template<class T>
std::ostream & List<T>::Print(std::ostream & cout)
{
	Node<T>* nextInList = Next();
	std::cout << "LIST -> ";
	while (nextInList != nullptr)
	{
		nextInList->Print(cout);
		nextInList = nextInList->Next();
	}

	std::cout << "LIST";

	return cout;
}

template<class T>
Link<T>::Link()
{
	next = this;
	prev = this;
}

template<class T>
Node<T> * Link<T>::Next()
{
	return dynamic_cast<Node<T>*>(next);
}

template<class T>
const Node<T> * Link<T>::Next() const
{
	return dynamic_cast<Node<T>*>(next);
}

template<class T>
Node<T> * Link<T>::Prev()
{
	return dynamic_cast<Node<T>*>(prev);
}

template<class T>
const Node<T> * Link<T>::Prev() const
{
	return dynamic_cast<Node<T>*>(prev);
}

template<class T>
Node<T> * Link<T>::InsertAfter(Node<T> * TToInsert)
{
	Link<T> * behind = this;
	Link<T> * after = behind->next;

	TToInsert->next = after;
	behind->next = TToInsert;

	TToInsert->prev = behind;
	after->prev = TToInsert;

	return TToInsert;
}

template<class T>
Node<T> * Link<T>::InsertBefore(Node<T> * TToInsert)
{
	Link<T> * after = this;
	Link<T> * behind = after->prev;

	TToInsert->next = after;
	behind->next = TToInsert;

	TToInsert->prev = behind;
	after->prev = TToInsert;

	return TToInsert;
}

template<class T>
Node<T> * Link<T>::DeleteAfter()
{
	if (this == nullptr)
		return nullptr;
		
	if (!dynamic_cast<Node<T>*>(this->next))
		return nullptr;

	Link<T> * after = this->next->next;
	Link<T> * remove = this->next;
	Link<T> * behind = this;

	after->prev = behind;
	behind->next = after;

	remove->prev = nullptr;
	remove->next = nullptr;

	return dynamic_cast<Node<T>*>(remove);
}
template<class T>
Node<T> * Link<T>::DeleteBefore()
{
	if (this == nullptr)
		return nullptr;

	if (!dynamic_cast<Node<T>*>(this->prev))
		return nullptr;

	Link<T> * behind = this->prev->prev;
	Link<T> * remove = this->prev;
	Link<T> * after = this;

	after->prev = behind;
	behind->next = after;

	remove->prev = nullptr;
	remove->next = nullptr;

	return dynamic_cast<Node<T>*>(remove);
}
template<class T>
Node<T> * Link<T>::Find(Node<T> * searchFor)
{
	Node<T> * nextInList = Next();
	while (nextInList != nullptr)
	{
		if ((*nextInList->data) == (*searchFor->data))
			return nextInList;
		nextInList = nextInList->Next();
	}
	return nullptr;
}

template<class T>
const Node<T> * Link<T>::Find(Node<T> * searchFor) const
{
	const Node<T> * nextInList = Next();
	while (nextInList != nullptr)
	{
		if ((*nextInList->data) == (*searchFor->data))
			return nextInList;
		nextInList = nextInList->Next();
	}
	return nullptr;
}

template<class T>
Node<T>* Link<T>::Find(const T searchFor)
{
	Node<T> * search = new Node<T>(searchFor);
	Node<T> * found = Find(search);
	delete search;
	return found;
}

template<class T>
const Node<T>* Link<T>::Find(const T searchFor) const
{
	Node<T> * search = new Node<T>(searchFor);
	const Node<T> * found = Find(search);
	delete search;
	return found;
}

template<class T>
Node<T>::Node(const T data)
{
	this->data = new T(data);
}

template<class T>
Node<T>::~Node()
{
	delete data;
}

template<class T>
std::ostream & Node<T>::Print(std::ostream & cout)
{
	cout << *(data) << " > ";
	return cout;
}

