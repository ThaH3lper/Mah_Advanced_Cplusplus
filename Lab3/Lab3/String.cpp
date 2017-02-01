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
	strSize = 0;
	memSize = 1;
}

String::~String()
{
	delete[] charArray;
}

String::String(const String & rhs)
{
	copyMem(rhs.data(), rhs.size());
	strSize = rhs.size();
	memSize = rhs.capacity();
}

String::String(const char * cstr)
{
	strSize = strlen(cstr);
	memSize = strSize + 1;
	copyMem(cstr, strSize);

}

String & String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;
	delete[] charArray;
	strSize = rhs.size();
	memSize = rhs.capacity();
	copyMem(rhs.data(), rhs.size());
	return *this;
}

String & String::operator=(const char * cstr)
{
	delete[] charArray;
	strSize = strlen(cstr);
	memSize = strSize + 1;
	copyMem(cstr, strlen(cstr));
	return *this;
}

String & String::operator=(char ch)
{
	delete[] charArray;
	charArray = new char[2];
	charArray[0] = ch;
	charArray[1] = '\0';
	strSize = 1;
	memSize = 2;
	return *this;
}

std::ostream & operator<<(std::ostream & cout, String & obj)
{
	std::cout << obj.data() << std::endl;
	std::cout << "|";
	for (size_t i = 0; i < obj.capacity(); i++)
	{
		std::cout << obj[i] << "|";
	}
	return cout;
}

/*indexerar med range check “Bounds checking is
performed, exception of type std::out_of_range will be
thrown on invalid access.”*/
char & String::at(int i)			
{
	if (i >= strSize)
	{
		//call shit here
	}
	char * pointer = charArray;
	pointer += i;
	return *pointer;
}

char & String::operator[](size_t i) { return charArray[i]; }

const char * String::data() const { return charArray;}

int String::size() const { 
	return strSize; 
}

int String::capacity() const { return memSize; }

void String::resize(int n)
{
	if (memSize == n)
		return;

	char * temp = new char[n + 1];
	if (n > memSize)
	{
		memcpy(temp, charArray, memSize);
		memset(temp + memSize, char(), n - strSize);
	}
	else
	{
		memcpy(temp, charArray, n + 1);
		temp[n] = '\0';
		strSize = n;
	}
	memSize = n + 1;
	delete[] charArray;
	charArray = temp;
}