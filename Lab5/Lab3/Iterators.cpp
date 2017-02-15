//#include "Iterators.h"
//
//template<class IteratorType, class ValueType>
//BaseIterator<IteratorType, ValueType>::BaseIterator(const ValueType* value)
//{
//	ptr = value;
//}
//
//template<class IteratorType, class ValueType>
//BaseIterator<IteratorType, ValueType>  & BaseIterator<IteratorType, ValueType>::operator=(const ValueType* value)
//{
//	ptr = value;
//}
//
//template<class IteratorType, class ValueType>
//bool BaseIterator<IteratorType, ValueType>::operator!=(const BaseIterator<IteratorType, char> & lhs)
//{
//	return (*ptr != *lhs.ptr);
//}
//
//template<class IteratorType, class ValueType>
//BaseIterator<IteratorType, ValueType> & BaseIterator<IteratorType, ValueType>::operator++()
//{
//	ptr += 1;
//	return *this;
//}
//
//template<class IteratorType, class ValueType>
//ValueType & BaseIterator<IteratorType, ValueType>::operator*()
//{
//	return *ptr;
//}
