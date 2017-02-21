#pragma once
#include <algorithm>

template<class IteratorType, class ValueType, bool Reverse>
class BaseIterator : std::iterator<std::random_access_iterator_tag, ValueType>
{
	ValueType * ptr;

public:
	BaseIterator();
	BaseIterator(ValueType * value);
	BaseIterator(IteratorType&& rhs);

	IteratorType& operator=(const IteratorType & value);

	ValueType& operator[](size_t i);
	int operator-(const IteratorType & lhs);
	virtual ValueType& operator*();

	IteratorType operator++();			//Prefix ++i
	IteratorType operator++(int);		//Postfix i++

	IteratorType operator--();			//Prefix --i

	IteratorType operator+(int i);
	IteratorType operator-(int i);

	IteratorType operator+=(int i);
	IteratorType operator-=(int i);

	bool operator!=(const IteratorType & lhs);
	bool operator==(const IteratorType & lhs);
	bool operator<(const IteratorType & lhs);
};

template<class ValueType, bool Reverse>
class Iterator : public BaseIterator<Iterator<ValueType, Reverse>, ValueType, Reverse>
{
public:
	Iterator();
	Iterator(ValueType * value);
};


