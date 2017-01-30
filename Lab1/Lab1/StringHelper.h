#pragma once

#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class StringHelper
{
public:
	StringHelper() = default;

	char * Replace(const char* str, const char* searchFor, const char* changeTo);

	bool Compare(const char *str, const char* searchFor);

	int Count(const char* str, const char* searchFor);
};

