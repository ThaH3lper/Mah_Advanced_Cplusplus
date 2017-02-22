#pragma once
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class Counter
{
private:
	int count;
public:
	void addRef() { 
		++count; 
		std::cout << "Added: " << count << std::endl;
	}
	int removeRef() { 
		std::cout << "Remove: " << (count - 1) << std::endl;
		return --count;
	}
};

template<class T>
class SharedPointer
{
private:
	T* ptr;
	Counter* counter;
public:

	SharedPointer(T* newPtr = nullptr);
	SharedPointer(const SharedPointer & rhs);
	SharedPointer(const SharedPointer && rhs);
	//SharedPointer(WeakPointer weakPtr);
	~SharedPointer();

	SharedPointer& operator=(const SharedPointer& rhs);
	SharedPointer& operator=(const SharedPointer&& rhs);

	bool operator==(const SharedPointer & rhs);
	bool operator<(const SharedPointer & rhs);

	bool operator==(const T* & rhs);
	bool operator<(const T* & rhs);

	T& operator*();
	T* operator->();
	bool operator();

	void reset(T* newPtr = nullptr);
	T* get();
	void unique(); //??
};
