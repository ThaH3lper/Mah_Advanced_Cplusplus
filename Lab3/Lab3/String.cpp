#include "String.h"

String::String()
{
	charArray = "";
}

String::~String()
{
}

String::String(const char * cstr)
{
	std::cout << sizeof(cstr)/sizeof(char) << std::endl;
	std::cout << strlen(cstr) << std::endl;
	charArray = new char[sizeof(cstr) - 1];
	memcpy(charArray, cstr, strlen(cstr) + 1);
	std::cout << sizeof(charArray) / sizeof(char) << std::endl;
}

std::ostream & operator<<(std::ostream & cout, String & obj)
{
	std::cout << obj.data();
	return cout;
}

const char * String::data() const
{
	return charArray;
}
