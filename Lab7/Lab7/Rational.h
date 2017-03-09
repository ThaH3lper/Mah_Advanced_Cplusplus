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

	// Print << and >>
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

	// R++ and ++R
	Rational<Tint>& operator++(){
		P += Q;
		return *this;
	}
	Rational<Tint> operator++(int){
		Rational<Tint> tmp(P, Q);
		operator++();
		return tmp;
	}

	// R++ and ++R
	Rational<Tint> operator-() { return Rational<Tint>(-P, Q); }

	explicit operator int() {return P / Q;}
};

/*
*		GLOBAL FUNCTIONS!
*/

// "+="
template<typename Tint, typename Tx>									//Rational<a> --- int
Rational<Tint> operator+=(Rational<Tint>& lhs, const Tx& rhs) {
	lhs.P = lhs.P + rhs * (long)lhs.Q;
	return lhs;
}

template<typename Tint, typename Tx>									//Rational<a> --- Rational<b>
Rational<Tint> & operator+=(Rational<Tint>& lhs, const Rational<Tx>& rhs) {
	long long p = lhs.P * (long long)rhs.Q + rhs.P * (long long)lhs.Q;
	long long q = lhs.Q * (long long)rhs.Q;
	Reduce(p, q);
	lhs.P = p;
	lhs.Q = q;
	return lhs;
}

template<typename Tint>													//Rational<a> --- Rational<a>
Rational<Tint> & operator+=(Rational<Tint>& lhs, const Rational<Tint>& rhs) {
	long long p = lhs.P * (long long)rhs.Q + rhs.P * (long long)lhs.Q;
	long long q = lhs.Q * (long long)rhs.Q;
	Reduce(p, q);
	lhs.P = p;
	lhs.Q = q;
	return lhs;
}

// "+" Don't use += more reduce required!
template<typename Tint, typename Tx>									//Rational<a> --- int
auto operator+(const Rational<Tint>& lhs, const Tx& rhs) {
	long long p = lhs.P + rhs * (long long)lhs.Q;
	long long q = lhs.Q;
	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<typename Tint, typename Tx>									//int --- Rational<a>
auto operator+(const Tint& lhs, const Rational<Tx>& rhs) {
	long long p = rhs.P + lhs * (long long)rhs.Q;
	long long q = rhs.Q;
	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<typename Tint, typename Tx>									//Rational<a> --- Rational<b>
auto operator+(const Rational<Tint>& lhs, const Rational<Tx>& rhs) {
	long long p = lhs.P * (long long)rhs.Q + rhs.P * (long long)lhs.Q;
	long long q = lhs.Q * (long long)rhs.Q;
	Reduce(p, q);
	return Rational<select<Tint, Tx>::value>(p, q);
}

template<typename Tint>													//Rational<a> --- Rational<a>
auto operator+(const Rational<Tint>& lhs, const Rational<Tint>& rhs) {
	long long p = lhs.P * (long long)rhs.Q + rhs.P * (long long)lhs.Q;
	long long q = lhs.Q * (long long)rhs.Q;
	Reduce(p, q);
	return Rational<Tint>(p, q);
}

//Tell if Ta or Tb is largest, general
template<class Ta, class Tb> struct select { typedef Ta value;};

//Specialization
template<> struct select<short, int> { typedef int value; };
template<> struct select<int, short> { typedef int value; };
template<> struct select<short, long long> { typedef long long value; };
template<> struct select<long long, short> { typedef long long value; };
template<> struct select<long long, int> { typedef long long value; };
template<> struct select<int, long long> { typedef long long value; };