#include "StringHelper.h"

char * StringHelper::Replace(const char * str, const char * searchFor, const char * changeTo)
{
	if (strlen(searchFor) == 0)
		return nullptr;
	//Count how many you find.
	int found = Count(str, searchFor);

	//str length + the additional chars that is required + 1 for the '\0'.
	int newSize = strlen(str) + found * (strlen(changeTo) - strlen(searchFor)) + 1;

	//Create new bigger or smaller array to copy to.
	char * newString = new char[newSize]();
	char * newStringPointer = newString;

	//Loop trough the string and point at each char.
	for (const char * stringPointer = str; stringPointer < str + strlen(str);)
	{
		if (Compare(stringPointer, searchFor))
		{
			//Copy to new string
			strcpy_s(newStringPointer, strlen(changeTo) + 1, changeTo);

			stringPointer += strlen(searchFor);		//Move forward what we found
			newStringPointer += strlen(changeTo);	//Move forward what we changed to
		}
		else
		{
			//simple replace char and move forward.
			*newStringPointer = *stringPointer;
			stringPointer++;
			newStringPointer++;
			
		}
	}
	return newString;
}

bool StringHelper::Compare(const char * str, const char * searchFor)
{
	const char * strPointer = str;
	for (const char * searchForPointer = searchFor; searchForPointer < searchFor + strlen(searchFor); searchForPointer++)
	{
		//loop trough what we seach for and check from str if the full word is equal.
		if (*strPointer != *searchForPointer)
			return false;

		strPointer++;
	}
	return true;
}

int StringHelper::Count(const char * str, const char * searchFor)
{
	int found = 0;
	for (const char * strPointer = str; strPointer < str + strlen(str);)
	{
		if (Compare(strPointer, searchFor))
		{
			found++;
			strPointer += strlen(searchFor);
			//if found, move forward the 'searchFor' length.
		}
		else
			strPointer++;
	}
	return found;
}
