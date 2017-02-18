#pragma once
#include <algorithm>

/*
- default constructor, copy constructor! och tilldelning (=)! en till?
- iteratorn ska innehålla alla typedef (använd std::iterator)
*/
template<class IteratorType, class ValueType, bool Reverse>
class BaseIterator : std::iterator<std::random_access_iterator_tag, ValueType>
{
	//pointer ptr;						//use typedefs?

public:
	pointer ptr;
	BaseIterator();
	BaseIterator(ValueType * value);
	BaseIterator(IteratorType&& rhs);
	IteratorType& operator=(const IteratorType & value);

	ValueType& operator[](size_t i);

	bool operator!=(const IteratorType & lhs);
	bool operator==(const IteratorType & lhs);
	bool operator<(const IteratorType & lhs);

	IteratorType& operator++();			//Prefix ++i
	IteratorType operator++(int);		//Postfix i++
	IteratorType& operator--();			//Prefix --i

	IteratorType operator+(int lhs);
	IteratorType operator-(int lhs);
	int operator-(const IteratorType & lhs);
	ValueType& operator*();
};

template<class ValueType>
class Iterator : public BaseIterator<Iterator<ValueType>, ValueType, false>
{
public:
	Iterator();
	Iterator(ValueType * value);
};

class ConstIterator
{

};

template<class ValueType>
class ReverseIterator : public BaseIterator<ReverseIterator<ValueType>, ValueType, true>
{
public:
	ReverseIterator();
	ReverseIterator(ValueType * value);
};

class ConstReverseIterator
{

};
