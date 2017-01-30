#pragma once
#include <iostream>
#include <assert.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template <class T>
class List;

template <class T>
class Link {
	Link* next; Link* prev;
	friend class List<T>;

public:
	Link();
	virtual ~Link() = default;
	T & Link::operator= (const T &) = delete;
	Link(const Link<T> &lhs) = delete;

	T * Next();
	const T * Next() const;

	T * Prev();
	const T * Prev() const;

	T * InsertAfter(T * TToInsert);
	T * InsertBefore(T * TToInsert);
	T * DeleteAfter();
	T * DeleteBefore();

	T * Find(T * searchFor);
	const T * Find(T * searchFor) const;

	virtual std::ostream& Print(std::ostream& cout) { return cout; }
};

template<class T>
class Node : public Link<Node<T>>
{
public:
	T * data;

	Node() = delete;
	Node(const T data);
	~Node();

	std::ostream& Print(std::ostream& cout);
};


template <class T>
class List :public Link<T> {
#define first this->next
#define last this->prev
public:
	List();
	~List();
	T & List::operator= (const T &) = delete;
	List(const List<T> &lhs) = delete;

	T * First();
	const T * First() const;

	T * Last();
	const T * Last() const;

	T * InsertFirst(T * item);
	T * InsertLast(T * item);
	T * PopFirst();
	T * PopLast();

	friend std::ostream& operator<<(std::ostream& cout, List& list) {
		return list.Print(cout);
	}
	void Check();
private:
	std::ostream& Print(std::ostream& cout);
};