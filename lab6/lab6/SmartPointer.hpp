#pragma once

#include "SmartPointer.h"

template<class T>
SharedPointer<T>::SharedPointer(T * newPtr)
{
	ptr = newPtr;
	if (newPtr)
	{
		counter = new Counter();
		counter->addRef();
	}
	else
		counter = nullptr;
}

template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> & rhs)
{
	ptr = rhs.ptr;
	if (counter)
		clear(*this);
	if (rhs.counter)
	{
		counter = rhs.counter;
		counter->addRef();
	}
	else
		counter = nullptr;

}

template<class T>
SharedPointer<T>::SharedPointer(SharedPointer<T> && rhs)
{
	if (rhs.ptr == ptr && rhs.counter == counter)
		return;

	ptr = nullptr;
	counter = nullptr;

	std::swap(ptr, rhs.ptr);
	std::swap(counter, rhs.counter);
}

template<class T>
SharedPointer<T>::SharedPointer(WeakPointer<T> & weakPtr)
{
	if (weakPtr.counter == nullptr)
		throw("std::bad_weak_ptr");

	ptr = weakPtr.ptr;
	counter = weakPtr.counter;
	counter->addRef();
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
	if (counter == nullptr)
		return;
	clear(*this);
}

template<class T>
SharedPointer<T> & SharedPointer<T>::operator=(const SharedPointer & rhs)
{
	if (rhs.ptr == ptr && counter == rhs.counter)
		return *this;

	clear(*this);

	ptr = rhs.ptr;
	if (rhs.counter)
	{
		counter = rhs.counter;
		counter->addRef();
	}
	else
		counter = nullptr;
	return *this;
}

template<class T>
SharedPointer<T> & SharedPointer<T>::operator=(SharedPointer && rhs)
{
	if (rhs.ptr == ptr && counter == rhs.counter)
		return *this;

	std::swap(ptr, rhs.ptr);
	std::swap(counter, rhs.counter);

	clear(rhs);

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
bool SharedPointer<T>::Invariant()
{
	return ((counter == nullptr) && (ptr == nullptr))
		|| counter != nullptr && ptr != nullptr;
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
	clear(*this);
	
	ptr = newPtr;
	if (ptr)
	{
		counter = new Counter();
		counter->addRef();
	}
}

template<class T>
T * SharedPointer<T>::get()
{
	return ptr;
}

template<class T>
bool SharedPointer<T>::unique()
{
	if (!counter)
		return false;
	return (counter->getCount() == 1);
}

template<class T>
void SharedPointer<T>::clear(SharedPointer & pointer)
{
	if (!pointer.counter)
		return;
	if (pointer.counter->removeRef() == 0)
	{
		delete pointer.ptr;
		if (pointer.counter->getWeakCount() == 0)
		{
			delete pointer.counter;
		}
		pointer.counter = nullptr;
	}
}

/***************
* Weak pointer *
****************/

template<class T>
WeakPointer<T>::WeakPointer()
{
	ptr = nullptr;
	counter = nullptr;
}

template<class T>
WeakPointer<T>::WeakPointer(const SharedPointer<T> & rhs)
{
	ptr = rhs.ptr;
	if (rhs.counter) {
		counter = rhs.counter;
		counter->addWeakRef();
	}
	else
		counter = nullptr;
}

template<class T>
WeakPointer<T>::WeakPointer(const WeakPointer & rhs)
{
	ptr = rhs.ptr;
	if (rhs.counter)
	{
		counter = rhs.counter;
		counter->addWeakRef();
	}
	else
		counter = nullptr;
}

template<class T>
WeakPointer<T>::~WeakPointer()
{
	if (counter == nullptr)
		return;
	if(counter->removeWeakRef() == 0 && counter->getCount() == 0)
	{
		delete counter;
		counter = nullptr;
	}
}

template<class T>
WeakPointer<T> & WeakPointer<T>::operator=(const SharedPointer<T> & rhs)
{
	if (rhs.ptr == ptr && counter == rhs.counter)
		return *this;

	if (counter != nullptr)
	{
		if (counter->removeWeakRef() == 0 && counter->getCount() == 0)
		{
			delete counter;
			counter = nullptr;
		}
	}

	ptr = rhs.ptr;
	if (rhs.counter)
	{
		counter = rhs.counter;
		counter->addWeakRef();
	}
	else
		counter = nullptr;

	return *this;
}

template<class T>
WeakPointer<T> & WeakPointer<T>::operator=(const WeakPointer & rhs)
{
	if (rhs.ptr == ptr && counter == rhs.counter)
		return *this;

	if (counter->removeWeakRef() == 0 && counter->getCount() == 0)
	{
		delete counter;
		counter = nullptr;
	}

	ptr = rhs.ptr;
	if (rhs.counter)
	{
		counter = rhs.counter;
		counter->addWeakRef();
	}
	else
		counter = nullptr;

	return *this;
}

template<class T>
bool WeakPointer<T>::Invariant()
{
	return ((counter == nullptr) && (ptr == nullptr))
		|| counter != nullptr;
}

template<class T>
bool WeakPointer<T>::expired()
{
	if (counter == nullptr)
		return true;
	if (counter->getCount() == 0)
	{
		if (counter->removeWeakRef() == 0)
		{
			delete counter;
			counter = nullptr;
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
    return (expired() ? SharedPointer<T>() : SharedPointer<T>(*this));
}
