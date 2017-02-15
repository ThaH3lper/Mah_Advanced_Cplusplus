#include "String.h"

void String::makeMemoryAndCopy(const char * ptr, size_t length)
{
	int lengthWithTerminator = length + 1;
	charArray = new char[lengthWithTerminator];
	memcpy(charArray, ptr, lengthWithTerminator);
}

String::String(size_t n)
{
	charArray = nullptr;
	strSize = 0;
	memSize = 0;
	reserv(n);
	assert(invariant());
}

String::String()
{
	charArray = new char();
	strSize = 0;
	memSize = 0;
	assert(invariant());
}

String::~String()
{
	delete[] charArray;
}

String::String(const String & rhs)
{
	makeMemoryAndCopy(rhs.data(), rhs.capacity());
	strSize = rhs.size();
	memSize = rhs.capacity();
}

String::String(String && rhs)
{
	charArray = nullptr;
	swap(*this, rhs);
	assert(invariant());
}

String::String(const char * cstr)
{
	if (!cstr) {
		String();
		return;
	}
	makeMemoryAndCopy(cstr, strlen(cstr));
	strSize = strlen(cstr);
	memSize = strSize;
	assert(invariant());
}

String & String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;

	if (rhs.size() <= memSize)
	{
		memcpy(charArray, rhs.data(), rhs.size());
		strSize = rhs.size();
		memSize = rhs.capacity();
		charArray[strSize] = '\0';
	}
	else
	{
		char * tempPtr = charArray;
		makeMemoryAndCopy(rhs.data(), rhs.capacity());
		strSize = rhs.size();
		memSize = rhs.capacity();
		delete[] tempPtr;
	}
	assert(invariant());
	return *this;
}

String & String::operator=(String && rhs)
{
	if (this == &rhs)
		return *this;

	swap(*this, rhs);
	delete[] rhs.charArray;
	rhs.charArray = nullptr;

	assert(invariant());
	return *this;
}

String & String::operator=(const char * cstr)
{
	if (!cstr) {
		String();
		return *this;
	}
	int newSize = strlen(cstr);
	if (newSize + 1 <= memSize)
	{
		memcpy(charArray, cstr, newSize + 1);		
	}
	else
	{
		char * temp = charArray;
		makeMemoryAndCopy(cstr, newSize);
		delete[] temp;
		memSize = newSize;
	}
	strSize = newSize;
	assert(invariant());
	return *this;
}

String & String::operator=(char ch)
{
	if (memSize < 2)
	{
		char* temp = new char[2];
		delete[] charArray;
		charArray = temp;
	}
	charArray[0] = ch;
	charArray[1] = '\0';
	strSize = 1;
	memSize = 1;

	assert(invariant());
	return *this;
}

char & String::at(size_t i)
{
	if (i >= strSize)
		throw std::out_of_range("Index out of range!");

	return *(charArray+i);
}

const char & String::at(size_t i) const
{
	if (i >= strSize)
		throw std::out_of_range("Index out of range!");

	return *(charArray + i);
}

char & String::operator[](size_t i) {
	return charArray[i];
}

const char & String::operator[](size_t i) const {
	return charArray[i];
}

const char * String::data() const { return charArray; }

size_t String::size() const {
	return strSize;
}

void String::reserv(size_t i)								//can only expand memory.
{
	if (i <= memSize)
		return;
	resizeMem(i);
	assert(invariant());
}

size_t String::capacity() const { return memSize; }

void String::shrink_to_fit()
{
	resizeMem(strSize);
}


void String::resizeMem(size_t n)							//resize the memory up or down.
{
	if (memSize == n)
		return;

	char * temp = new char[n + 1];
	if (n > memSize)
	{
		if (charArray)
			memcpy(temp, charArray, memSize);
		memset(temp + strSize, char(), 1);
	}
	else
	{
		memcpy(temp, charArray, n + 1);
		temp[n] = '\0';
		strSize = n;
	}
	memSize = n;
	if (charArray)
		delete[] charArray;
	charArray = temp;
	assert(invariant());
}

void String::printMem() const
{
	std::cout << "|";
	for (size_t i = 0; i < memSize; i++)
	{
		if (charArray[i] == '\0')
			std::cout << "/0" << "|";
		else
			std::cout << charArray[i] << "|";
	}
}

void String::append(const char * cstr, size_t length)
{
	size_t requiredSize = strSize + length;
	if (memSize < requiredSize)
		reserv(requiredSize * 2);

	memcpy(charArray + strSize, cstr, length);
	strSize += length;
	memset(charArray + strSize, char(), 1);
	assert(invariant());
}

bool String::invariant()
{
	return (charArray == nullptr || (charArray[strSize] == '\0' && memSize >= strSize));
}

/*
	Additions operators and append
*/

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

String String::operator+(const String & lhs)
{
	String temp = String(lhs.size() + strSize);
	temp += *this;
	temp += lhs;
	return temp;
}

void String::push_back(char c)
{
	String temp = String();
	temp = c;
	*this += temp;
}
void String::resize(size_t n)
{
	if (n == strSize)
		return;
	if (n > memSize)
		reserv(n);

	memset(charArray + strSize, char(), n - strSize + 1);
}
/*
	Swap
*/
void swap(String & rhs, String & lhs)
{
	std::swap(lhs.memSize, rhs.memSize);
	std::swap(lhs.strSize, rhs.strSize);
	std::swap(lhs.charArray, rhs.charArray);
}
/*
	Global methods
*/
std::ostream & operator<<(std::ostream & cout, String & obj)
{
	for (size_t i = 0; i < obj.size() + 1; i++)
		std::cout << obj[i];
	return cout;
}

bool operator==(const String& lhs, const String& rhs)
{
	if (rhs.size() != lhs.size())
		return false;

	for (size_t i = 0; i < rhs.size() + 1; i++)
	{
		if (*lhs.data() != *rhs.data())
			return false;
	}
	return true;
}

bool operator!=(const String & lhs, const String & rhs)
{
	return !(lhs == rhs);
}
