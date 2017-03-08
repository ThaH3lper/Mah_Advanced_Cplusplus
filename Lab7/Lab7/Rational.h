#pragma once
#include <iostream>
#include "GCD.h"

template<typename Tint>
class Rational {
public:
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

	friend std::istream& operator>> (std::istream & cin, Rational<Tint> R) {

		
		cin >> R.P >> R.Q;
		//std::cout << "TEST" << std::endl;
		//R.Q = 3;
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

template<typename Tint, typename Tx>
Rational<Tint> operator+(Rational<Tint>& lhs, const Rational<Tx>& rhs) {
	long long p = lhs.P * rhs.Q + rhs.P * lhs.Q;
	long long q = lhs.Q * rhs.Q;

	return Rational<Tint>(p, q);
}

template<typename Tint, typename Tx>
Rational<Tint> operator+(Rational<Tint>& lhs, const Tx& rhs) {
	long long p = lhs.P + rhs * lhs.Q;
	long long q = lhs.Q;

	return Rational<Tint>(p, q);
}


//*CODE