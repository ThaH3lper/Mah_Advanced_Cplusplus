#pragma once
#include <algorithm>

template<class ValueType, bool Reverse>
class Iterator : public std::iterator<std::random_access_iterator_tag, ValueType, int>
{
	ValueType * ptr;

public:
	Iterator();
	Iterator(ValueType * value);
	Iterator(Iterator&& value);
	Iterator(const Iterator& value);

	Iterator& operator=(const Iterator & value);

	ValueType& operator[](size_t i);
	int operator-(const Iterator & rhs);
	virtual ValueType& operator*();

	Iterator operator++();			//Prefix ++i
	Iterator operator++(int);		//Postfix i++

	Iterator operator--();			//Prefix --i

	Iterator operator+(int i);
	Iterator operator-(int i);

	Iterator operator+=(int i);
	Iterator operator-=(int i);

	bool operator!=(const Iterator & rhs);
	bool operator==(const Iterator & rhs);
	bool operator<(const Iterator & rhs);
};

template<class ValueType, bool Reverse>
bool operator==(const Iterator<ValueType, Reverse> & lhs, const Iterator<ValueType, Reverse> & rhs);



