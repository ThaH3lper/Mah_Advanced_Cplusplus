#pragma once
#include <iostream>
#include <assert.h>
#include <memory>
#include "Iterators.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template<class ValueType>
class Iterator;

template<class ValueType>
class ReverseIterator;

class String {
	char * charArray;

	size_t strSize;
	size_t memSize;

	void makeMemoryAndCopy(const char* cstr, size_t length);
	void append(const char * cstr, size_t length);
	void resizeMem(size_t n);		//Can the memory smaller or greater.
	bool invariant();

public:
	typedef Iterator<char> iterator;
	typedef ReverseIterator<char> reverse_iterator;
	typedef Iterator<const char> const_iterator;
	typedef ReverseIterator<const char> const_reverse_iterator;

	String();
	~String();

	explicit String(size_t n);
	String(const String& rhs);
	String(String&& rhs);
	String(const char* cstr);

	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	String& operator=(const char* cstr);
	String& operator=(char ch);

	char& at(size_t i);
	const char& at(size_t i) const;

	char& operator[](size_t i);
	const char& operator[](size_t i) const;

	const char* data() const;

	size_t size() const;
	void reserv(size_t i);			//Can only make the memory size greater.
	size_t capacity() const;
	void shrink_to_fit();
	void push_back(char c);
	void resize(size_t n);

	void printMem() const;			//Only printes the memory

	String& operator+=(const String& rhs);
	String& operator+=(char* cstr);
	String operator+(const String& lhs);

	iterator begin();
	iterator end();	

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_iterator cbegin() const;
	const_iterator cend() const;

	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;

	friend void swap(String & rhs, String & lhs);
};

std::ostream& operator<<(std::ostream& cout, String & obj);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
