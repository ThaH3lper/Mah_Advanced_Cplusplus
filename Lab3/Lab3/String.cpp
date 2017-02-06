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
	memSize = 0;
}

String::~String()
{
	delete[] charArray;
}

String::String(const String & rhs)
{
	copyMem(rhs.data(), rhs.capacity());
	strSize = rhs.size();
	memSize = rhs.capacity();
}

String::String(const char * cstr)
{
	if (!cstr){
		String();
		return;
	}
	strSize = strlen(cstr);
	memSize = strSize;
	copyMem(cstr, strSize);

}

String & String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;
	delete[] charArray;
	strSize = rhs.size();
	memSize = rhs.capacity();
	copyMem(rhs.data(), rhs.capacity());
	return *this;
}

String & String::operator=(const char * cstr)
{
	if (!cstr) {
		String();
		return *this;
	}
	delete[] charArray;
	strSize = strlen(cstr);
	memSize = strSize;
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
	memSize = 1;
	return *this;
}

std::ostream & operator<<(std::ostream & cout, String & obj)
{
	std::cout << obj.data() << std::endl;
	std::cout << "|";
	for (size_t i = 0; i < obj.capacity() + 1; i++)
	{
		if(obj[i] == '\0')
			std::cout << "/0" << "|";
		else
			std::cout << obj[i] << "|";
	}
	return cout;
}

/*indexerar med range check “Bounds checking is
performed, exception of type std::out_of_range will be
thrown on invalid access.”*/
char & String::at(int i)			
{
	if (i >= strSize || i < 0)
	{
		//call shit here
	}
	char * pointer = charArray;
	pointer += i;
	return *pointer;
}


char & String::operator[](size_t i) { 
	return charArray[i]; 
}

const char * String::data() const { return charArray;}

int String::size() const { 
	return strSize; 
}

void String::reserv(int i)
{
	if (i <= memSize)
		return;
	resize(i);
}

int String::capacity() const { return memSize; }

void String::shrink_to_fit()
{
	resize(strSize);
}

void String::resize(int n)
{
	if (n < 0)
		n = 0;
	if (memSize == n)
		return;

	char * temp = new char[n + 1];
	if (n > memSize)
	{
		memcpy(temp, charArray, memSize);
		memset(temp + memSize, char(), n - strSize + 1);
		std::cout << "[COPY] " << strSize << std::endl;
	}
	else
	{
		memcpy(temp, charArray, n + 1);
		temp[n] = '\0';
		strSize = n;
	}
	memSize = n;
	delete[] charArray;
	charArray = temp;
}

void String::append(const char * cstr, int length)
{
	int requiredSize = strSize + length;
	if (memSize < requiredSize)
		reserv(requiredSize * 2);

	memcpy(charArray + strSize, cstr, length);
	strSize += length;
}

String & String::operator+=(const String & rhs)
{
	append(rhs.data(), rhs.size());
	return *this;
}

String & String::operator+=(char * cstr)
{
	append(cstr, strlen(cstr));
	return *this;
}

String & String::operator+(const String & rhs)
{
	String * returnStr = new String(*this);
	std::cout << *returnStr << std::endl;
	*returnStr += rhs;
	std::cout << *returnStr << std::endl;
	return *returnStr;
}

String & String::operator+(char * cstr)
{
	return *this;
}

void String::push_back(char c)
{

}

bool operator==(const String& lhs, const String& rhs)
{
	if (rhs.capacity() != lhs.capacity())
		return false;

	if (rhs.size() != lhs.size())
		return false;

	for (size_t i = 0; i < rhs.size() + 1; i++)
	{
		if (*lhs.data() != *rhs.data())
			return false;
	}
	return true;


}