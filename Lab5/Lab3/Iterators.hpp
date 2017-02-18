#pragma once

#include "Iterators.h"

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(ValueType * value)
{
	ptr = value;
	std::cout << "CREATE" << std::endl;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(BaseIterator && rhs)
{
	ptr = nullptr;
	std::swap(ptr, rhs.ptr);
}

template<class IteratorType, class ValueType>
inline BaseIterator<IteratorType, ValueType> & BaseIterator<IteratorType, ValueType>::operator=(const ValueType * value)
{
	ptr = value;
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator[](size_t i)
{
	return *(ptr + i);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator!=(const BaseIterator<IteratorType, ValueType> & lhs)
{
	return (*ptr != *lhs.ptr);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator==(const BaseIterator & lhs)
{
	return (*ptr == *lhs.ptr);
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType> & BaseIterator<IteratorType, ValueType>::operator++()
{
	++ptr;
	return *this;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType> BaseIterator<IteratorType, ValueType>::operator++(int)
{
	BaseIterator temp(ptr);
	++ptr;
	return temp;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>& BaseIterator<IteratorType, ValueType>::operator--()
{
	--ptr;
	return *this;
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator*()
{
	return *ptr;
}
