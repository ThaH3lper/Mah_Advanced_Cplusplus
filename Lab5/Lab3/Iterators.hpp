#pragma once

#include "Iterators.h"

/***************************
* Methods for BaseIterator *
****************************/

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator() {
	ptr = nullptr;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(ValueType * value) {
	ptr = value;
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(IteratorType && value) {
	if (value.ptr == ptr)
		return;
	ptr = nullptr;
	std::swap(ptr, value.ptr);
}

template<class IteratorType, class ValueType>
BaseIterator<IteratorType, ValueType>::BaseIterator(const IteratorType & value) {
	if (value.ptr == ptr)
		return;
	ptr = value.ptr;
}

template<class IteratorType, class ValueType>
IteratorType & BaseIterator<IteratorType, ValueType>::operator=(const IteratorType & value) {
	if (value.ptr == ptr)
		return *static_cast<IteratorType*>(this);
	ptr = value.ptr;
	return *static_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator[](int i) {
	return ptr[i];
}

template<class IteratorType, class ValueType>
ptrdiff_t BaseIterator<IteratorType, ValueType>::operator-(const BaseIterator & rhs) {
	return std::abs(ptr - rhs.ptr);
}

template<class IteratorType, class ValueType>
ValueType & BaseIterator<IteratorType, ValueType>::operator*() {
	return *ptr;
}

template<class IteratorType, class ValueType>
IteratorType & BaseIterator<IteratorType, ValueType>::operator++() {
	++ptr;
	return *static_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator++(int) {
	IteratorType temp(ptr);
	++ptr;
	return temp;
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator--() {
	--ptr;
	return *static_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator+(int i) {
	return IteratorType(ptr + i);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator-(int i) {
	return IteratorType(ptr - i);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator+=(int i) {
	ptr += i;
	return *static_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
IteratorType BaseIterator<IteratorType, ValueType>::operator-=(int i) {
	ptr -= (Reverse) ? -i : i;
	return *static_cast<IteratorType*>(this);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator!=(const IteratorType & rhs) {
	return (ptr != rhs.ptr);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator==(const IteratorType & rhs) {
	return (ptr == rhs.ptr);
}

template<class IteratorType, class ValueType>
bool BaseIterator<IteratorType, ValueType>::operator<(const IteratorType & rhs) {
	return (ptr < rhs.ptr);
}

template<class IteratorType, class ValueType>
bool operator==(const BaseIterator<IteratorType, ValueType> & lhs, const BaseIterator<IteratorType, ValueType> & rhs) {
	return (lhs.ptr == lhs.ptr);
}

/******************************
* Methods for ReverseIterator *
*******************************/

template<class ValueType>
ptrdiff_t ReverseIterator<ValueType>::operator-(const ReverseIterator & rhs) {
	return rhs.ptr - ptr;
}

template<class ValueType>
ValueType & ReverseIterator<ValueType>::operator[](int i) {
	return ptr[-i];
}

template<class ValueType>
ReverseIterator<ValueType> & ReverseIterator<ValueType>::operator++() {
	--ptr;
	return *this;
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator++(int) {
	ReverseIterator<ValueType> temp(ptr);
	--ptr;
	return temp;
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator--() {
	++ptr;
	return *this;
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator+(int i) {
	return ReverseIterator(ptr - i);
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator-(int i) {
	return ReverseIterator(ptr + i);
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator+=(int i) {
	ptr -= i;
	return *this;
}

template<class ValueType>
ReverseIterator<ValueType> ReverseIterator<ValueType>::operator-=(int i) {
	ptr += i;
	return *this;
}

template<class ValueType>
bool ReverseIterator<ValueType>::operator<(const ReverseIterator<ValueType> & rhs) {
	return (ptr > rhs.ptr);
}

