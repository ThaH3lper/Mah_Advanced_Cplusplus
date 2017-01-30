#pragma once
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class String {
	char * charArray;

	void copyMem(const char* cstr, int length);

public:
	String();
	~String();

	String(const String& rhs);
	String(String&& rhs);		//VG
	String(const char* cstr);

	String& operator=(const String& rhs);
	String& operator=(String&& rhs); 		//VG
	String& operator=(const char* cstr);
	String& operator=(char ch);

	char& at(int i);
	char& operator[](int i);
	const char* data() const;

	int size() const;
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
