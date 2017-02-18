#pragma once

#include "Iterators.h"

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator()
{
	ptr = nullptr;
	std::cout << "BaseIterator()" << std::endl;
}

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator(ValueType * value)
{
	ptr = value;
}

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator(IteratorType && rhs)
{
	ptr = nullptr;
	std::swap(ptr, rhs.ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType & BaseIterator<IteratorType, ValueType, Reverse>::operator=(const IteratorType & value)
{
	ptr = value.ptr;
	return *this;
}

template<class IteratorType, class ValueType, bool Reverse>
ValueType & BaseIterator<IteratorType, ValueType, Reverse>::operator[](size_t i)
{
	return *(ptr + i);
}

template<class IteratorType, class ValueType, bool Reverse>
bool BaseIterator<IteratorType, ValueType, Reverse>::operator!=(const IteratorType & lhs)
{
	return (ptr != lhs.ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
bool BaseIterator<IteratorType, ValueType, Reverse>::operator==(const IteratorType & lhs)
{
	return (ptr == lhs.ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
bool BaseIterator<IteratorType, ValueType, Reverse>::operator<(const IteratorType & lhs)
{
	if (Reverse)
		return (ptr > lhs.ptr);;
	return (ptr < lhs.ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType & BaseIterator<IteratorType, ValueType, Reverse>::operator++()
{
	if (Reverse)
		--ptr;
	else
		++ptr;
	return IteratorType(ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator++(int)
{
	IteratorType temp(ptr);
	if (Reverse)
		--ptr;
	else
		++ptr;
	return temp;
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType& BaseIterator<IteratorType, ValueType, Reverse>::operator--()
{
	--ptr;
	return *this;
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator+(int lhs)
{
	return IteratorType(ptr + lhs);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator-(int lhs)
{
	return IteratorType(ptr - lhs); 
}

template<class IteratorType, class ValueType, bool Reverse>
int BaseIterator<IteratorType, ValueType, Reverse>::operator-(const IteratorType & lhs)
{
	return ptr - lhs.ptr;
}

template<class IteratorType, class ValueType, bool Reverse>
ValueType & BaseIterator<IteratorType, ValueType, Reverse>::operator*()
{
	return *ptr;
}

//ITERATOR
template<class ValueType>
Iterator<ValueType>::Iterator() : BaseIterator()
{

}

template<class ValueType>
Iterator<ValueType>::Iterator(ValueType * value) : BaseIterator(value)
{
}

//Reverse
template<class ValueType>
ReverseIterator<ValueType>::ReverseIterator() : BaseIterator()
{
}

template<class ValueType>
ReverseIterator<ValueType>::ReverseIterator(ValueType * value) : BaseIterator(value)
{
}

