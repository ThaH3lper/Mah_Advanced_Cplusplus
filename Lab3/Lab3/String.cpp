#include "String.h"

void String::copyMem(const char * cstr, int length)
{
	int lengthWithTerminator = length + 1;
	charArray = new char[lengthWithTerminator];
	memcpy(charArray, cstr, lengthWithTerminator);					/*Memcpy need lengthcheck. if 2 long, fix*/
}

String::String()
{
	charArray = new char();
}

String::~String()
{
	delete[] charArray;
}

String::String(const String & rhs)
{
	copyMem(rhs.data(), rhs.size());
}

String::String(const char * cstr)
{
	copyMem(cstr, strlen(cstr));
}

String & String::operator=(const String & rhs)
{
	delete[] charArray;
	copyMem(rhs.data(), rhs.size());
	return *this;
}

String & String::operator=(const char * cstr)
{
	delete[] charArray;
	copyMem(cstr, strlen(cstr));
	return *this;
}

String & String::operator=(char ch)
{
	delete[] charArray;
	charArray = (char*)malloc(2);
	charArray[0] = ch;
	charArray[1] = '\0';
	return *this;
}

std::ostream & operator<<(std::ostream & cout, String & obj)
{
	std::cout << obj.data();
	return cout;
}

/*indexerar med range check “Bounds checking is
performed, exception of type std::out_of_range will be
thrown on invalid access.”*/
char & String::at(int i)			
{
	char * pointer = charArray;
	pointer += i;
	return *pointer;
}

char & String::operator[](int i)
{
	return charArray[i];
}

const char * String::data() const
{
	return charArray;
}

int String::size() const
{
	return strlen(charArray);
}

void String::resize(int n)
{
	int currentSize = size();
	if (currentSize == n)
		return;

	char * temp = (char*) malloc(n + 1);
	if (n > currentSize)
	{
		memcpy(temp, charArray, currentSize);
		memset(temp + currentSize, char(), n - currentSize + 1);
	}
	else
	{
		memcpy(temp, charArray, n + 1);
		temp[n] = '\0';
	}
	delete[] charArray;
	charArray = temp;
}
