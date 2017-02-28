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
SharedPointer<T>::SharedPointer(const SharedPointer<T> & rhs)
{
	ptr = rhs.ptr;
	counter = rhs.counter;
	counter->addRef();
}

template<class T>
SharedPointer<T>::SharedPointer(SharedPointer<T> && rhs)
{
	if (rhs.ptr == ptr)
		return;

	ptr = nullptr;
	counter = new Counter();
	counter->addRef();

	std::swap(ptr, rhs.ptr);
	std::swap(counter, rhs.counter);
}

template<class T>
SharedPointer<T>::SharedPointer(const WeakPointer<T> & weakPtr)
{
	ptr = weakPtr.ptr;
	counter = weakPtr.counter;
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
SharedPointer<T> & SharedPointer<T>::operator=(const SharedPointer && rhs)
{
	if (rhs.ptr == ptr)
		return *this;

	std::swap(ptr, rhs.ptr);
	std::swap(counter, rhs.counter);

	if (rhs->counter->removeRef() == 0) {
		delete ptr;
		delete counter;
	}

	return *this;
}

template<class T>
bool SharedPointer<T>::operator==(const SharedPointer & rhs)
{
	return (ptr == rhs.ptr);
}

template<class T>
bool SharedPointer<T>::operator<(const SharedPointer & rhs)
{
	return (ptr < rhs.ptr);
}

template<class T>
bool SharedPointer<T>::operator==(const T *& rhs)
{
	return (ptr == rhs);
}

template<class T>
bool SharedPointer<T>::operator<(const T *& rhs)
{
	return (ptr < rhs);
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

template<class T>
SharedPointer<T>::operator bool() const
{
	return (ptr != nullptr);
}

template<class T>
void SharedPointer<T>::reset(T * newPtr = nullptr)
{
	if (counter->removeRef() == 0)
	{
		delete ptr;
		delete counter;
	}
	
	ptr = newPtr;
	counter = new Counter();
	counter->addRef();
}

template<class T>
T * SharedPointer<T>::get()
{
	return ptr;
}

template<class T>
bool SharedPointer<T>::unique()
{
	return (counter->getCount() == 1);
}

/***************
* Weak pointer *
****************/

template<class T>
WeakPointer<T>::WeakPointer()
{
	ptr = nullptr;
	counter = new Counter();
	counter->addWeakRef();
}

template<class T>
WeakPointer<T>::WeakPointer(const SharedPointer<T> & rhs)
{
	ptr = rhs.ptr;
	counter = rhs.counter;
	counter->addWeakRef();
}

template<class T>
WeakPointer<T>::WeakPointer(const WeakPointer & rhs)
{
	if (rhs.counter->getCount() == 0)
		throw("std::bad_weak_ptr");

	ptr = rhs.ptr;
	counter = rhs.counter;
	counter->addWeakRef();
}

template<class T>
WeakPointer<T>::~WeakPointer()
{
	if(counter->removeWeakRef() == 0 && counter->getCount() == 0)
	{
		delete counter;
	}
}

template<class T>
WeakPointer<T> & WeakPointer<T>::operator=(const SharedPointer<T> & rhs)
{
	return (ptr == rhs.ptr);
}

template<class T>
WeakPointer<T> & WeakPointer<T>::operator=(const WeakPointer & rhs)
{
	return (ptr == rhs.ptr);
}

template<class T>
bool WeakPointer<T>::expired() const
{
	if (counter->getCount() == 0)
	{
		if (counter->removeWeakRef() == 0)
		{
			delete counter;
		}
		ptr = nullptr;
		counter = nullptr;
		return true;
	}
	return false;
}

template<class T>
SharedPointer<T> WeakPointer<T>::lock()
{
	return (expired() ? SharedPointer<T>() : SharedPointer<T>(ptr));
}
