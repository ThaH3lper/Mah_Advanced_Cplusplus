#pragma once
#include <iostream>

class String {
	char * charArray;

public:
	String();
	~String();

	String(const String& rhs);
	String(String&& rhs);
	String(const char* cstr);

	String& operator=(const String& rhs);
	String& operator=(String& rhs);
	String& operator=(const char* cstr);
	String& operator=(char ch);

	char& at(int i);
	char& operator[](int i);
	const char* data() const;

	int length() const;
	void reserv(int i);
	int capacity() const;
	void shrink_to_fit();
	void push_back(char c);
	void resize(int n);

	String& operator+=(const String& rhs);
	String& operator+=(char* cstr);
	String& operator+(const String& rhs);
	String& operator+(char* cstr);

	friend bool operator==(const String& lhs, const String& rhs);

};

std::ostream& operator<<(std::ostream& cout,String & obj);
