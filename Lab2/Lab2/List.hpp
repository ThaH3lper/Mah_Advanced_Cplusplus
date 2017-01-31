#pragma once
#include "List.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template<class T>
List<T>::List()
{
	next = this;
	prev = this;
}

template<class T>
List<T>::~List()
{
	T* nextInList = Next();
	while (nextInList != nullptr)
	{
		T* deleteNode = nextInList;
		nextInList = nextInList->Next();
		delete deleteNode;
	}
}

template<class T>
T * List<T>::First()
{
	return dynamic_cast<T*>(next);
}

template<class T>
const T * List<T>::First() const
{
	return dynamic_cast<T*>(next);
}

template<class T>
T * List<T>::Last()
{
	return dynamic_cast<T*>(prev);
}

template<class T>
inline const T * List<T>::Last() const
{
	return dynamic_cast<T*>(prev);
}

template<class T>
T * List<T>::InsertFirst(T * item)
{
	this->InsertAfter(item);
	return item;
}

template<class T>
T * List<T>::InsertLast(T * item)
{
	this->InsertBefore(item);
	return item;
}

template<class T>
T * List<T>::PopFirst()
{
	return this->DeleteAfter();
}

template<class T>
T * List<T>::PopLast()
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
	T* nextInList = Next();
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
T * Link<T>::Next()
{
	return dynamic_cast<T*>(next);
}

template<class T>
const T * Link<T>::Next() const
{
	return dynamic_cast<T*>(next);
}

template<class T>
T * Link<T>::Prev()
{
	return dynamic_cast<T*>(prev);
}

template<class T>
const T * Link<T>::Prev() const
{
	return dynamic_cast<T*>(prev);
}

template<class T>
T * Link<T>::InsertAfter(T * TToInsert)
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
T * Link<T>::InsertBefore(T * TToInsert)
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
T * Link<T>::DeleteAfter()
{
	if (this == nullptr)
		return nullptr;

	if (!dynamic_cast<T*>(this->next))
		return nullptr;

	Link<T> * after = this->next->next;
	Link<T> * remove = this->next;
	Link<T> * behind = this;

	after->prev = behind;
	behind->next = after;

	remove->prev = nullptr;
	remove->next = nullptr;

	return dynamic_cast<T*>(remove);
}
template<class T>
T * Link<T>::DeleteBefore()
{
	if (this == nullptr)
		return nullptr;

	if (!dynamic_cast<T*>(this->prev))
		return nullptr;

	Link<T> * behind = this->prev->prev;
	Link<T> * remove = this->prev;
	Link<T> * after = this;

	after->prev = behind;
	behind->next = after;

	remove->prev = nullptr;
	remove->next = nullptr;

	return dynamic_cast<T*>(remove);
}
template<class T>
T * Link<T>::Find(T * searchFor)
{
	T * nextInList = Next();
	while (nextInList != nullptr)
	{
		if ((*nextInList->data) == (*searchFor->data))
			return nextInList;
		nextInList = nextInList->Next();
	}
	return nullptr;
}

template<class T>
const T * Link<T>::Find(T * searchFor) const
{
	const T * nextInList = Next();
	while (nextInList != nullptr)
	{
		if ((*nextInList->data) == (*searchFor->data))
			return nextInList;
		nextInList = nextInList->Next();
	}
	return nullptr;
}

template<class T>
Node<T>::Node(const T data)
{
	this->data = new T(data);
}

template<class T>
inline Node<T>::~Node()
{
	delete data;
}

template<class T>
std::ostream & Node<T>::Print(std::ostream & cout)
{
	cout << *(data) << " > ";
	return cout;
}

