#pragma once
#include <iostream>

template<class T>
class WeakPointer;

class Counter {
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
class SharedPointer {
	friend WeakPointer<T>;

private:
	T* ptr;
	Counter* counter;

public:
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

	bool Invariant();

	T& operator*();
	T* operator->();
	operator bool() const;

	void reset(T* newPtr = nullptr);
	T* get();
	bool unique();
	void clear(SharedPointer & pointer);
};

template<class T>
class WeakPointer {
	friend SharedPointer<T>;

private:
	T* ptr;
	Counter* counter;

public:
	WeakPointer();
	WeakPointer(const SharedPointer<T> & rhs);
	WeakPointer(const WeakPointer & rhs);
	~WeakPointer();

	WeakPointer& operator=(const SharedPointer<T>& rhs);
	WeakPointer& operator=(const WeakPointer& rhs);

	bool Invariant();

	bool expired();
	SharedPointer<T> lock();
};
