#pragma once
#include <algorithm>

template<class IteratorType, class ValueType>
class BaseIterator;

template<class IteratorType, class ValueType>
class BaseIterator : public std::iterator <std::random_access_iterator_tag, ValueType>
{
protected:
	ValueType * ptr;
public:
	BaseIterator();
	BaseIterator(ValueType * value);
	BaseIterator(IteratorType&& value);
	BaseIterator(const IteratorType& value);

	IteratorType& operator=(const IteratorType & value);

	ValueType& operator[](size_t i);
	ptrdiff_t operator-(const IteratorType & rhs);
	virtual ValueType& operator*();

	IteratorType & operator++();			//Prefix ++i
	IteratorType operator++(int);		//Postfix i++

	IteratorType operator--();			//Prefix --i add &

	IteratorType operator+(int i);
	IteratorType operator-(int i);

	IteratorType operator+=(int i);
	IteratorType operator-=(int i);

	bool operator!=(const IteratorType & rhs);
	bool operator==(const IteratorType & rhs);
	bool operator<(const IteratorType & rhs);
};

template<class IteratorType, class ValueType>
bool operator==(const BaseIterator<IteratorType, ValueType> & lhs, const BaseIterator<IteratorType, ValueType> & rhs);

template<class ValueType>
class Iterator : public BaseIterator<Iterator<ValueType>, ValueType>
{
public:
	Iterator() : BaseIterator() {}
	Iterator(ValueType * value) : BaseIterator(value) {}
	Iterator(Iterator&& value) : BaseIterator(value) {}
	Iterator(const Iterator& value) : BaseIterator(value) {}

	Iterator& operator=(const Iterator & value)
	{
		if (value.ptr == ptr)
			return *this;
		ptr = value.ptr;
		return *this;
	}
};

template<class ValueType>
class ReverseIterator : BaseIterator<Iterator<ValueType>, ValueType>
{

};



