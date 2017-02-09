#pragma once
#include <iostream>
#include <assert.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class String {
	char * charArray;

	int strSize;
	int memSize;

	void copyMem(const char* cstr, int length);
	void append(const char * cstr, int length);
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

	int size() const;
	void reserv(size_t i);
	int capacity() const;
	void shrink_to_fit();
	void push_back(char c);
	void resize(size_t n);

	void printMem() const;

	String& operator+=(const String& rhs);
	String& operator+=(char* cstr);
	String operator+(const String& lhs); 			//inefective?

	friend void swap(String & rhs, String & lhs);
};

std::ostream& operator<<(std::ostream& cout, String & obj);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
