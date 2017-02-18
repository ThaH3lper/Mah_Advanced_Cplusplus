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

	BaseIterator(ValueType * value);
	BaseIterator<IteratorType, ValueType>(BaseIterator<IteratorType, ValueType>&& rhs);
	BaseIterator<IteratorType, ValueType>& operator=(const ValueType* value);

	ValueType& operator[](size_t i);

	bool operator!=(const BaseIterator<IteratorType, ValueType> & lhs);
	bool operator==(const BaseIterator<IteratorType, ValueType> & lhs);

	BaseIterator<IteratorType, ValueType>& operator++();		//Prefix ++i
	BaseIterator<IteratorType, ValueType> operator++(int);		//Postfix i++
	BaseIterator<IteratorType, ValueType>& operator--();		//Prefix --i
	ValueType& operator*();
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
