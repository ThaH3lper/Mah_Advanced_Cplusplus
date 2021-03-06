#include "String.h"

void String::copyMem(const char * cstr, int length)
{
	int lengthWithTerminator = length + 1;
	std::unique_ptr<char> temp(new char[lengthWithTerminator]);	//exception safty
	charArray = temp.get();
	memcpy(charArray, cstr, lengthWithTerminator);
	temp.release();												//release object;
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
	std::unique_ptr<char> temp(new char());
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
	copyMem(rhs.data(), rhs.capacity());
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
	if (!cstr){
		String();
		return;
	}
	strSize = strlen(cstr);
	memSize = strSize;
	copyMem(cstr, strSize);
	assert(invariant());
}

String & String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;
	delete[] charArray;
	strSize = rhs.size();
	memSize = rhs.capacity();
	copyMem(rhs.data(), rhs.capacity());
	assert(invariant());
	return *this;
}

String & String::operator=(String && rhs)
{
	if (this == &rhs)
		return *this;

	delete[] charArray;
	charArray = nullptr;
	String temp(std::move(rhs));
	swap(*this, temp);
	assert(invariant());
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
	assert(invariant());
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
	assert(invariant());
	return *this;
}

char & String::at(size_t i)
{
	if (i >= strSize)
		throw std::out_of_range("Index out of range!");

	char * pointer = charArray;
	pointer += i;
	return *pointer;
}

const char & String::at(size_t i) const
{
	if (i >= strSize)
		throw std::out_of_range("Index out of range!");

	char * pointer = charArray;
	pointer += i;
	return *pointer;
}

char & String::operator[](size_t i) { 
	return charArray[i]; 
}

const char & String::operator[](size_t i) const{
	return charArray[i];
}

const char * String::data() const { return charArray;}

int String::size() const { 
	return strSize; 
}

void String::reserv(size_t i)
{
	if (i <= memSize)
		return;
	resize(i);
	assert(invariant());
}

int String::capacity() const { return memSize; }

void String::shrink_to_fit()
{
	resize(strSize);
}

void String::resize(size_t n)
{
	if (memSize == n)
		return;

	char * temp = new char[n + 1];
	if (n > memSize)
	{
		if(charArray)
			memcpy(temp, charArray, memSize);
		memset(temp + memSize, char(), n - strSize + 1);
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
	for (size_t i = 0; i < memSize + 1; i++)
	{
		if (charArray[i] == '\0')
			std::cout << "/0" << "|";
		else
			std::cout << charArray[i] << "|";
	}
}

void String::append(const char * cstr, int length)
{
	int requiredSize = strSize + length;
	if (memSize < requiredSize)
		reserv(requiredSize * 2);

	memcpy(charArray + strSize, cstr, length);
	strSize += length;
	assert(invariant());
}

bool String::invariant()
{
	return (charArray == nullptr || (charArray[memSize] == '\0' && memSize >= strSize));
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
