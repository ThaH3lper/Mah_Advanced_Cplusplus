#pragma once
#include <algorithm>

/*
- *it, --it, ++it, it++, (it+i), (it-it), it[i], ==, != och <
- default constructor, copy constructor och tilldelning (=)
- iteratorn ska innehålla alla typedef (använd std::iterator)
*/
template<class IteratorType, class ValueType>
class BaseIterator : std::iterator<std::random_access_iterator_tag, ValueType>
{
	ValueType * ptr;

public:
	BaseIterator<IteratorType, ValueType>(ValueType* value) {
		ptr = value;
	}
	BaseIterator<IteratorType, ValueType>& operator=(const ValueType* value) {
		ptr = value;
	}

	bool operator!=(const BaseIterator<IteratorType, ValueType> & lhs) {
		return (*ptr != *lhs.ptr);
	}

	BaseIterator<IteratorType, ValueType> operator++() {
		ptr += 1;
		return *this;
	}

	ValueType& operator*() {
		return *ptr;
	}

};

class Iterator
{

};

class ConstIterator
{

};

class ReverseIterator
{

};

class ConstReverseIterator
{

};

