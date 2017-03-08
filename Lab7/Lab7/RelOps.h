
template <typename T, typename R> bool operator!=(const T& lhs,const R& rhs) { return !(lhs==rhs); }
template <typename T, typename R> bool operator>(const T& lhs,const R& rhs) { return (rhs<lhs); }
template <typename T, typename R> bool operator>=(const T& lhs,const R& rhs) { return !(lhs<rhs); }
template <typename T, typename R> bool operator<=(const T& lhs,const R& rhs) { return !(rhs<lhs); }

template<typename Ta> bool operator==(const Rational<Ta>& lhs, const Rational<Ta>& rhs) 
{ return (lhs.P == rhs.P && lhs.Q == rhs.Q); }

template<typename Ta, typename Tb> bool operator==(const Rational<Ta>& lhs, const Rational<Tb>& rhs) 
{ return (lhs.P / lhs.Q == rhs.P / rhs.Q);}

template<typename Ta, typename Tb> bool operator==(const Rational<Ta>& lhs, const Tb& rhs) 
{ return (lhs.P / lhs.Q == rhs); }

template<typename Ta, typename Tb> bool operator<(const Rational<Ta>& lhs, const Rational<Tb>& rhs) 
{ return (lhs.P / lhs.Q < rhs.P / rhs.Q); }