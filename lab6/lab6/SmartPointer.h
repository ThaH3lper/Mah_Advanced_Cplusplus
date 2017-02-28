#pragma once
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template<class T>
class WeakPointer;

class Counter
{
private:
	int count = 0;
	int weakCount = 0;
public:
	void addRef() { ++count; }
	int removeRef() { return --count;}
	int getCount() const { return count; }

	void addWeakRef() { ++weakCount; }
	int removeWeakRef() { return --weakCount; }
	int getWeakCount() const { return weakCount; }
};

template<class T>
class SharedPointer
{
public:
	T* ptr;
	Counter* counter;

//public:
	SharedPointer(T* newPtr = nullptr);
	SharedPointer(const SharedPointer & rhs);
	SharedPointer(SharedPointer && rhs);
	SharedPointer(WeakPointer<T> & weakPtr);
	~SharedPointer();

	SharedPointer& operator=(const SharedPointer& rhs);
	SharedPointer& operator=(SharedPointer&& rhs);

	bool operator==(const SharedPointer & rhs);
	bool operator<(const SharedPointer & rhs);

	bool operator==(const T* & rhs);
	bool operator<(const T* & rhs);

	T& operator*();
	T* operator->();
	operator bool() const;

	void reset(T* newPtr = nullptr);
	T* get();
	bool unique();
};

template<class T>
class WeakPointer
{
public:
	T* ptr;
	Counter* counter;

//public:
	WeakPointer();
	WeakPointer(const SharedPointer<T> & rhs);
	WeakPointer(const WeakPointer & rhs);
	~WeakPointer();

	WeakPointer& operator=(const SharedPointer<T>& rhs);
	WeakPointer& operator=(const WeakPointer& rhs);

	bool expired();
	SharedPointer<T> lock();
};
