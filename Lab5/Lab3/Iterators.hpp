#pragma once

#include "Iterators.h"

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator()
{
	ptr = nullptr;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(ValueType * value)
{
	ptr = value;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(IteratorType && value)
{
	if (value.ptr == ptr)
		return;
	ptr = nullptr;
	std::swap(ptr, value.ptr);
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(const IteratorType & value)
{
	if (value.ptr == ptr)
		return;
	ptr = value.ptr;
}

template<class IteratorType, class ValueType>
IteratorType & BaseIterator<IteratorType, ValueType>::operator=(const IteratorType & value)
{
	if (value.ptr == ptr)
		return *this;
	ptr = value.ptr;
	return *dynamic_cast<IteratorType*>(this);;
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator[](size_t i)
{
	return ptr[index];
	//int index = (int) i;
	//return ptr[(Reverse) ? -index : index];
}

template<class IteratorType, class ValueType>
ptrdiff_t BaseIterator<IteratorType, ValueType>::operator-(const IteratorType & rhs){
	return ptr - rhs.ptr;
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator*()
{
	return *ptr;
}

template<class IteratorType, class ValueType>
IteratorType & BaseIterator<IteratorType, ValueType>::operator++()
{
	//if (Reverse)
	//	--ptr;
	//else
		++ptr;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator++(int)
{
	IteratorType temp(ptr);
	//if (Reverse)
	//	--ptr;
	//else
		++ptr;
	return temp;
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator--()
{
	//if (Reverse)
	//	++ptr;
	//else
		--ptr;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator+(int i)
{
	//return BaseIterator((Reverse) ? ptr - i : ptr + i);
	return IteratorType(ptr + i);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator-(int i)
{
	return IteratorType(ptr - i);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator+=(int i)
{
	//ptr += (Reverse) ? -i : i;
	ptr += i;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator-=(int i)
{
	ptr -= (Reverse) ? -i : i;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator!=(const IteratorType & rhs)
{
	return (ptr != rhs.ptr);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator==(const IteratorType & rhs)
{
	return (ptr == rhs.ptr);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator<(const IteratorType & rhs)
{
	//if (Reverse)
	//	return (ptr > rhs.ptr);
	return (ptr < rhs.ptr);
}

template<class IteratorType, class ValueType>
bool operator==(const BaseIterator<IteratorType, ValueType> & lhs, const BaseIterator<IteratorType, ValueType> & rhs)
{
	return (lhs.ptr == lhs.ptr);
}

