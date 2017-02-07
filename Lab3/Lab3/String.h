#pragma once
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class String {
	char * charArray;

	int strSize;
	int memSize;

	void copyMem(const char* cstr, int length);
	void append(const char * cstr, int length);

public:
	String();
	~String();

	String(const String& rhs);
	String(String&& rhs);		//Good?
	String(const char* cstr);

	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	String& operator=(const char* cstr);
	String& operator=(char ch);

	char& at(int i);//C
	char& operator[](size_t i);//C
	const char* data() const;

	int size() const;
	void reserv(int i);
	int capacity() const;
	void shrink_to_fit();
	void push_back(char c); //append?
	void resize(int n);

	String& operator+=(const String& rhs);
	String& operator+=(char* cstr);
	friend String operator+(const String& rhs, const String& lhs);	//WHAT?
	String operator+(char* cstr);									//WHAT?

	friend void swap(String & rhs, String & lhs);
	friend bool operator==(const String& lhs, const String& rhs);
};

String operator+(const String& rhs, const String& lhs);

std::ostream& operator<<(std::ostream& cout, String & obj);
void swap(String & rhs, String & lhs);
