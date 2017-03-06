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

	Rational(Rational & rhs);

	template<typename Tint>
	Rational(Rational<auto> & rhs);

	friend std::ostream& operator<< (std::ostream & cout, Rational<Tint> R) { 
		return cout << R.P << "/" << R.Q; 
	}

};

template<typename Tint>
bool operator==(const Rational<Tint>& lhs, const Rational<Tint>& rhs) {
	return (lhs.P == rhs.P && lhs.Q == rhs.Q);
}

template<typename Tint>
bool operator<(const Rational<Tint>& lhs, const Rational<Tint>& rhs) {
	return (lhs.P/ lhs.Q < rhs.P / rhs.Q);
}

//*CODE
template<typename Tint>
Rational<Tint>::Rational(Rational & rhs) : P(rhs.P), Q(rhs.Q) {};
template<typename Tint>
Rational<Tint>::Rational(Rational<auto> & rhs) : P(rhs.P), Q(rhs.Q) {};



