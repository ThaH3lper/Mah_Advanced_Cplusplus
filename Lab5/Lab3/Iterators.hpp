#pragma once

#include "Iterators.h"

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator()
{
	ptr = nullptr;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator(ValueType * value)
{
	ptr = value;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator(Iterator && value)
{
	if (value.ptr == ptr)
		return;
	ptr = nullptr;
	std::swap(ptr, value.ptr);
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator(const Iterator & value)
{
	if (value.ptr == ptr)
		return;
	ptr = value.ptr;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> & Iterator<ValueType, Reverse>::operator=(const Iterator & value)
{
	if (value.ptr == ptr)
		return *this;
	ptr = value.ptr;
	return *this;
}

template<class ValueType, bool Reverse>
ValueType & Iterator<ValueType, Reverse>::operator[](size_t i) 
{
	int index = (int) i;
	return *(ptr + ((Reverse) ? -index : index));
}

template<class ValueType, bool Reverse>
 Iterator<ValueType, Reverse>::operator-(const Iterator & rhs){
	return ptr - rhs.ptr;
}

template<class ValueType, bool Reverse>
ValueType & Iterator<ValueType, Reverse>::operator*()
{
	return *ptr;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator++()
{
	if (Reverse)
		--ptr;
	else
		++ptr;
	return *this;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator++(int)
{
	Iterator temp(ptr);
	if (Reverse)
		--ptr;
	else
		++ptr;
	return temp;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator--()
{
	if (Reverse)
		++ptr;
	else
		--ptr;
	return *this;
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator+(int i)
{
	return Iterator((Reverse) ? ptr - i : ptr + i);
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator-(int i)
{
	return Iterator((Reverse) ? ptr + i : ptr - i);
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator+=(int i)
{
	ptr += (Reverse) ? -i : i;
	return *dynamic_cast<Iterator*>(this);
}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse> Iterator<ValueType, Reverse>::operator-=(int i)
{
	ptr -= (Reverse) ? -i : i;
	return *dynamic_cast<Iterator*>(this);
}

template<class ValueType, bool Reverse>
bool Iterator<ValueType, Reverse>::operator!=(const Iterator & rhs)
{
	return (ptr != rhs.ptr);
}

template<class ValueType, bool Reverse>
bool Iterator<ValueType, Reverse>::operator==(const Iterator & rhs)
{
	return (ptr == rhs.ptr);
}

template<class ValueType, bool Reverse>
bool Iterator<ValueType, Reverse>::operator<(const Iterator & rhs)
{
	if (Reverse)
		return (ptr > rhs.ptr);
	return (ptr < rhs.ptr);
}

template<class ValueType, bool Reverse>
bool operator==(const Iterator<ValueType, Reverse> & lhs, const Iterator<ValueType, Reverse> & rhs)
{
	return (lhs.ptr == lhs.ptr);
}

