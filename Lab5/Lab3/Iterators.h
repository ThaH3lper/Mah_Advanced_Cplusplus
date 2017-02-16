#pragma once
#include <algorithm>

/*
- (it+i), (it-it) och <
- default constructor, copy constructor! och tilldelning (=)! en till?
- iteratorn ska innehålla alla typedef (använd std::iterator)
*/
template<class IteratorType, class ValueType>
class BaseIterator : std::iterator<std::random_access_iterator_tag, ValueType>
{
	pointer ptr; //use typedefs?
public:

	BaseIterator(ValueType* value) {
		ptr = value;
		std::cout << "CREATE" << std::endl;
	}

	BaseIterator(BaseIterator&& rhs) {
		ptr = nullptr;
		std::swap(ptr, rhs.ptr);
	}

	BaseIterator& operator=(const ValueType* value) {
		ptr = value;
	}

	ValueType& operator[](size_t i) {
		return *(ptr + i);
	}

	bool operator!=(const BaseIterator & lhs) {
		return (*ptr != *lhs.ptr);
	}

	bool operator==(const BaseIterator & lhs) {
		return (*ptr == *lhs.ptr);
	}

	BaseIterator& operator++() {		//Prefix ++i
		++ptr;
		return *this;
	}

	BaseIterator operator++(int) {		//Postfix i++
		BaseIterator temp(ptr);
		++ptr;
		return temp;
	}

	BaseIterator<IteratorType, ValueType>& operator--() {		//Prefix --i
		--ptr;
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

