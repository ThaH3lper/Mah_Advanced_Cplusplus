#pragma once

#include "SmartPointer.h"

template<class T>
SharedPointer<T>::SharedPointer(T * newPtr)
{
	ptr = newPtr;
	counter = new Counter();
	counter->addRef();
}

template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer & rhs)
{
	ptr = rhs.ptr;
	counter = rhs.counter;
	counter->addRef();
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
	if (counter->removeRef() == 0)
	{
		delete ptr;
		delete counter;
	}
}

template<class T>
SharedPointer<T> & SharedPointer<T>::operator=(const SharedPointer & rhs)
{
	if (rhs.ptr == ptr)
		return *this;

	if (counter->removeRef() == 0) {
		delete ptr;
		delete counter;
	}

	ptr = rhs.ptr;
	counter = rhs.counter;
	counter->addRef();
	return *this;
}

template<class T>
T & SharedPointer<T>::operator*()
{
	return *ptr;
}

template<class T>
T* SharedPointer<T>::operator->()
{
	return ptr;
}
