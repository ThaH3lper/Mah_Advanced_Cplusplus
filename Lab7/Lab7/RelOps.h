
template <typename T, typename R> bool operator!=(const T& lhs,const R& rhs) { return !(lhs==rhs); }
template <typename T, typename R> bool operator>(const T& lhs,const R& rhs) { return (rhs<lhs); }
template <typename T, typename R> bool operator>=(const T& lhs,const R& rhs) { return !(lhs<rhs); }
template <typename T, typename R> bool operator<=(const T& lhs,const R& rhs) { return !(rhs<lhs); }

template<typename Ta> bool operator==(const Rational<Ta>& lhs, const Rational<Ta>& rhs)					//Rational<a> --- Rational<a>
{ return (lhs.P == rhs.P && lhs.Q == rhs.Q); } 

template<typename Ta, typename Tb> bool operator==(const Rational<Ta>& lhs, const Rational<Tb>& rhs)	//Rational<a> --- Rational<b>
{ return (lhs.P / (float)lhs.Q == rhs.P / (float)rhs.Q);}

template<typename Ta, typename Tb> bool operator==(const Rational<Ta>& lhs, const Tb& rhs)				//Rational<a> --- int
{ return (lhs.P / (float)lhs.Q == (float)rhs); }

template<typename Ta, typename Tb> bool operator==(const Ta& lhs, const Rational<Tb>& rhs)				//int --- Rational<b>
{ return (rhs.P / (float)rhs.Q == (float)lhs); }

template<typename Ta, typename Tb> bool operator<(const Rational<Ta>& lhs, const Rational<Tb>& rhs) 
{ return (lhs.P / (float)lhs.Q < rhs.P / (float)rhs.Q); }
