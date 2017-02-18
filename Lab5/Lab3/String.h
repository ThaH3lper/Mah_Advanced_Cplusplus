#pragma once
#include <iostream>
#include <assert.h>
#include <memory>
#include "Iterators.hpp"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class String {
	char * charArray;

	size_t strSize;
	size_t memSize;

	void makeMemoryAndCopy(const char* cstr, size_t length);
	void append(const char * cstr, size_t length);
	void resizeMem(size_t n);		//Can the memory smaller or greater.
	bool invariant();

public:
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

	BaseIterator<Iterator, char> begin();	//?Reference works
	BaseIterator<Iterator, char> end();		//?Reference not working

	friend void swap(String & rhs, String & lhs);
};

std::ostream& operator<<(std::ostream& cout, String & obj);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
