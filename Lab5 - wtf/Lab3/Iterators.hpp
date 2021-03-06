#pragma once

#include "Iterators.h"

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator() 
{
	ptr = nullptr;
}

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator(ValueType * value) 
{
	ptr = value;
}

template<class IteratorType, class ValueType, bool Reverse>
BaseIterator<IteratorType, ValueType, Reverse>::BaseIterator(IteratorType && value) 
{
	if (value == this)
		return *this;
	ptr = nullptr;
	std::swap(ptr, value.ptr);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType & BaseIterator<IteratorType, ValueType, Reverse>::operator=(const IteratorType & value) 
{
	if (value == this)
		return *this;
	ptr = value.ptr;
	return *this;
}

template<class IteratorType, class ValueType, bool Reverse>
ValueType & BaseIterator<IteratorType, ValueType, Reverse>::operator[](size_t i) 
{
	int index = (int) i;
	return *(ptr + ((Reverse) ? -index : index));
}

template<class IteratorType, class ValueType, bool Reverse>
int BaseIterator<IteratorType, ValueType, Reverse>::operator-(const IteratorType & lhs){
	return ptr - lhs.ptr;
}

template<class IteratorType, class ValueType, bool Reverse>
ValueType & BaseIterator<IteratorType, ValueType, Reverse>::operator*()
{
	return *ptr;
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator++()
{
	if (Reverse)
		--ptr;
	else
		++ptr;
	return *dynamic_cast<IteratorType*>(this);
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
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator--()
{
	if (Reverse)
		++ptr;
	else
		--ptr;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator+(int i)
{
	return IteratorType((Reverse) ? ptr - i : ptr + i);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator-(int i)
{
	return IteratorType((Reverse) ? ptr + i : ptr - i);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator+=(int i)
{
	ptr += (Reverse) ? -i : i;
	return *dynamic_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType, bool Reverse>
IteratorType BaseIterator<IteratorType, ValueType, Reverse>::operator-=(int i)
{
	ptr -= (Reverse) ? -i : i;
	return *dynamic_cast<IteratorType*>(this);
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
		return (ptr > lhs.ptr);
	return (ptr < lhs.ptr);
}

//ITERATOR
template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator() : BaseIterator()
{

}

template<class ValueType, bool Reverse>
Iterator<ValueType, Reverse>::Iterator(ValueType * value) : BaseIterator(value)
{
}

