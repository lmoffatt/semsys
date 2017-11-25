#ifndef VARIABLES_H
#define VARIABLES_H
#include "units.h"
#include "iostream"
#include "Definition_system.h"
#include "SI.h"
namespace variables
{
template<class V>
auto operator+(const V& one, const V& other)->
std::remove_const_t<std::remove_reference_t<decltype(one.value, one)>>
{
  V out;
  out.value=one.value+other.value;
  return out;
};


template<
    template<class...> class V, class U1, class U2, typename std::enable_if<!std::is_same<U1,U2>::value,int>::type=0>
auto operator+(const V<U1>& one, const V<U2>& other)->
V<units::Sum<U1,U2>>
{
  V<typename units::Sum<U1,U2>> out ;
  out.value=one.value+other.value;
  return out;
};


template<class V>
auto operator-(const V& one, const V& other)->
std::remove_const_t<std::remove_reference_t<decltype(one.value, one)>>
{
  V out;
  out.value=one.value-other.value;
  return out;
};

template<
    template<class...> class V, class U1, class U2>
auto operator-(const V<U1>& one, const V<U2>& other)->
V<units::Sum<U1,U2>>
{
  V<typename units::Sum<U1,U2>> out ;
  out.value=one.value-other.value;
  return out;
};


template<class V>
auto operator*(const V& one, double other)->
std::remove_const_t<std::remove_reference_t<decltype(one.value, one)>>
{
  V out;
  out.value=one.value*other;
  return out;
};
template<class V>
auto operator*(double other,const V& one)->
std::remove_const_t<std::remove_reference_t<decltype(one.value, one)>>
{
  V out;
  out.value=one.value*other;
  return out;
};



template<template <class> class V, class U1, class U2>
V<units::Product<U1,U2>> operator*(const V<U1>& one, const V<U2>& other)
{
  V<units::Product<U1,U2>> out;
  out.value=one.value*other.value;
  return out;
};


template<template <class> class V, class U>
auto operator<<(std::ostream& os,const V<U>& one)->
decltype(one.value,os)
{
  os<<one.value<<" "<<U::abbr();
  return os;
};

template<template <class> class V, class U>
auto operator>>(std::istream& is, V<U>& one)->
decltype(one.value,is)
{
  is>>one.value;
  if (!is.good())
    return is;
  else
    {
      std::string ab;
      is>>ab;
      if (ab==U::abbr)
        return is;
      else
        {
          is.setstate(std::ios::failbit);
          return is;
        }
    }
 };

template<class>
struct Var_{};


template<template<template<class> class,class...> class UU,
         template<class> class SI,
         class... Us>
struct Var_<UU<SI,Us...>>
{
   double value;
   typedef UU<SI,Us...> unit;
};


template<template<class> class SI,
         template<template<class>class,class...> class UU,
         class...Us>
struct Var_impl
{
   typedef Var_<units::U<SI,Us...>> type;
};


template<template<class> class SI,
         class... U>
using Var=typename Var_impl<SI,units::U,U...>::type;

};
#endif // VARIABLES_H
