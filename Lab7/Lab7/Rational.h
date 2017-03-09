#pragma once
#include <iostream>
#include <string>
#include "GCD.h"

template<typename Tint>
class Rational {
public:
	typedef Tint value;
	Tint P, Q;
	Rational() : P(0), Q(1) {};
	Rational(Tint P) :P(P), Q(1) {}
	Rational(Tint P, Tint Q) :P(P), Q(Q) {
		Reduce(this->P, this->Q);
	}

	Rational(RLL & rhs) : P(rhs.P), Q(rhs.Q) {}
	Rational(Rshort & rhs) : P(rhs.P), Q(rhs.Q) {}
	Rational(Rint & rhs) : P(rhs.P), Q(rhs.Q) {}

	friend std::ostream& operator<< (std::ostream & cout, Rational<Tint> R) { 
		return cout << R.P << "/" << R.Q; 
	}

	friend std::istream& operator>> (std::istream & cin, Rational<Tint> & R) {
		int a, b;
		scanf_s("%i/%i", &a, &b);
		R.P = a;
		R.Q = b;
		return cin;
	}

	Rational<Tint> operator-() { return Rational<Tint>(-P, Q); }

	Rational<Tint>& operator++()
	{
		P += Q;
		return *this;
	}
	Rational<Tint> operator++(int)
	{
		Rational<Tint> tmp(P, Q);
		operator++();
		return tmp;
	}

	explicit operator int() {
		return P / Q;
	}


};

template<typename Tint, typename Tx>
auto operator+=(const Rational<Tint>& lhs, const Tx& rhs) {
	return Rational<Tint>(lhs.P + rhs * lhs.Q, lhs.Q);
}

template<typename Tint, typename Tx> //Implement Selection
auto operator+(Rational<Tint>& lhs, const Rational<Tx>& rhs) {
	long long p = lhs.P * (long long)rhs.Q + rhs.P * (long long)lhs.Q;
	long long q = lhs.Q * (long long)rhs.Q;

	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<typename Tint, typename Tx>
auto operator+(Rational<Tint>& lhs, const Tx& rhs) {
	long long p = lhs.P + rhs * (long long)lhs.Q;
	long long q = lhs.Q;

	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<typename Tint, typename Tx>
auto operator+(const Tint& lhs, const Rational<Tx>& rhs) {
	long long p = rhs.P + lhs * (long long)rhs.Q;
	long long q = rhs.Q;

	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<class Ta, class Tb> struct select { typedef Ta value;};

template<> struct select<short, int> { typedef int value; };
template<> struct select<int, short> { typedef int value; };
template<> struct select<short, long long> { typedef long long value; };
template<> struct select<long long, short> { typedef long long value; };
template<> struct select<long long, int> { typedef long long value; };
template<> struct select<int, long long> { typedef long long value; };