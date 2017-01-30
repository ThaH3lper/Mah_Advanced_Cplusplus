#pragma once
#include <iostream>
#include <assert.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template <class T>
class List;

template <class T>
class Node;

template <class T>
class Link {
	Link* next; Link* prev;
	friend class List<T>;

public:
	Link();
	virtual ~Link() = default;
	Node<T> & Link::operator= (const T &) = delete;
	Link(const Link<T> &lhs) = delete;

	Node<T> * Next();
	const Node<T> * Next() const;

	Node<T> * Prev();
	const Node<T> * Prev() const;

	Node<T> * InsertAfter(Node<T> * TToInsert);
	Node<T> * InsertBefore(Node<T> * TToInsert);
	Node<T> * DeleteAfter();
	Node<T> * DeleteBefore();

	Node<T> * Find(Node<T> * searchFor);
	const Node<T> * Find(Node<T> * searchFor) const;

	Node<T> * Find(const T searchFor);
	const Node<T> * Find(const T searchFor) const;

	virtual std::ostream& Print(std::ostream& cout) { return cout; }
};

template<class T>
class Node : public Link<T>
{
public:
	T * data;

	Node() = delete;
	Node(const T data);
	~Node();

	std::ostream& Print(std::ostream& cout);
};

template<class T>
class List : public Link<T> 
{
#define first this->next
#define last this->prev
public:
	List();
	~List();
	Node<T> & List::operator= (const Node<T> &) = delete;
	List(const List<T> &lhs) = delete;

	Node<T> * InsertFirst(const T item);
	Node<T> * InsertLast(const T item);
	Node<T> * PopFirst();
	Node<T> * PopLast();

	friend std::ostream& operator<<(std::ostream& cout, List& list) {
		return list.Print(cout);
	}
	void Check();
private:
	std::ostream& Print(std::ostream& cout);
};