#pragma once
#include <algorithm>

template<class IteratorType, class ValueType>
class BaseIterator : public std::iterator <std::random_access_iterator_tag, ValueType> {

protected:
	ValueType * ptr;

public:
	BaseIterator();
	BaseIterator(ValueType * value);
	BaseIterator(IteratorType&& value);
	BaseIterator(const IteratorType& value);

	IteratorType& operator=(const IteratorType & value);

	ValueType& operator[](int i);
	ptrdiff_t operator-(const BaseIterator & rhs);
	ValueType& operator*();

	IteratorType & operator++();		//Prefix ++i
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
class Iterator : public BaseIterator<Iterator<ValueType>, ValueType> {
public:
	using BaseIterator::BaseIterator;
};

template<class ValueType>
class ReverseIterator : public BaseIterator<ReverseIterator<ValueType>, ValueType> {
public:
	using BaseIterator::BaseIterator;
	
	ptrdiff_t operator-(const ReverseIterator & rhs);

	ValueType& operator[](int i);

	ReverseIterator & operator++();			//Prefix ++i
	ReverseIterator operator++(int);		//Postfix i++

	ReverseIterator operator--();			//Prefix --i add &

	ReverseIterator operator+(int i);
	ReverseIterator operator-(int i);

	ReverseIterator operator+=(int i);
	ReverseIterator operator-=(int i);

	bool operator<(const ReverseIterator & rhs);
};
